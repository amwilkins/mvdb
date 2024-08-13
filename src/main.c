#include "commands.h"
#include "common.h"
#include "parse.h"

typedef struct {
  char *buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;

InputBuffer *new_input_buffer() {
  InputBuffer *input_buffer = malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->buffer_length = 0;
  input_buffer->input_length = 0;

  return input_buffer;
}

void read_input(InputBuffer *input_buffer) {
  ssize_t bytes_read =
      getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

  if (bytes_read <= 0) {
    printf("Error reading input\n");
    exit(EXIT_FAILURE);
  }

  // Ignore trailing newline
  input_buffer->input_length = bytes_read - 1;
  input_buffer->buffer[bytes_read - 1] = 0;
}

void executeCommand(char *database_path, Command command,
                    InputBuffer *input_buffer) {
  int argc = 0;
  char *argv[3];

  switch (command) {
  // Database commands
  case COMMAND_INIT:
    // initializeDatabase(database_path, argc, argv);
    break;
  case COMMAND_SHOW:
    showDatabase(database_path);
    break;
  case COMMAND_DELETE:
    printf("Delete Database\n");
    break;
  // Row commands
  case COMMAND_REMOVE:
    printf("Remove item\n");
    break;
  case COMMAND_INSERT:
    insertRow(database_path, argc, argv);
    break;
  case COMMAND_SELECT:
    printf("Select a row\n");
    break;
  case COMMAND_RETURN:
    // returnRow(database_path, argc, argv);
    break;
  case COMMAND_UNKNOWN:
    printf("ERROR: Command Unknown\n");
  }
}

void repl(char *database_path) {
  InputBuffer *input_buffer = new_input_buffer();
  while (1) {
    printf("db > ");
    read_input(input_buffer);
    Command command = parseCommand(input_buffer->buffer);
    executeCommand(database_path, command, input_buffer);
  }
}

int main(int argc, char *argv[]) {
  char *database_path = argv[1];
  if (argc < 2) {
    printf("ERROR: Please supply a database file\n");
    exit(1);
  } else if (argc == 2) {
    repl(database_path);
  } else {
    Command command = parseCommand(argv[2]);

    switch (command) {
    // Database commands
    case COMMAND_INIT:
      initializeDatabase(database_path, argc, argv);
      break;
    case COMMAND_SHOW:
      showDatabase(database_path);
      break;
    case COMMAND_DELETE:
      printf("Delete Database\n");
      break;
    // Row commands
    case COMMAND_REMOVE:
      printf("Remove item\n");
      break;
    case COMMAND_INSERT:
      insertRow(database_path, argc, argv);
      break;
    case COMMAND_SELECT:
      printf("Select a row\n");
      break;
    case COMMAND_RETURN:
      printf("RETURN %s, index %s\n", argv[1], argv[3]);
      returnRow(database_path, argc, argv);
      break;
    case COMMAND_UNKNOWN:
      printf("ERROR: Command Unknown\n");
      exit(1);
    }
  }
}
