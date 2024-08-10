#include <stdio.h>  // for printf
#include <stdlib.h> // for malloc, exit

#include "commands.h"
#include "parse.h"

int main(int argc, char *argv[]) {

  if (argc < 3) {
    printf("ERROR: Please supply data file and command.\n");
    printf("Format should be: DATABASE COMMAND ...\n");
  } else {
    char *database = argv[1];
    Command command = parseCommand(argv[2]);

    switch (command) {
    case COMMAND_INIT:
      initializeDatabase(database, argc, argv);
      break;
    case COMMAND_SHOW:
      showDatabase(database, argc, argv);
      break;
    case COMMAND_DELETE:
      printf("Delete item\n");
      break;
    case COMMAND_REMOVE:
      printf("Remove item\n");
      break;
    case COMMAND_INSERT:
      printf("Insert into database\n");
      insertDatabase(database, argc, argv);
      break;
    case COMMAND_SELECT:
      printf("Select a row\n");
      break;
    case COMMAND_RETURN:
      printf("Return a value\n");
      break;
    case COMMAND_UNKNOWN:
      printf("ERROR: Command Unknown\n");
      exit(1);
    }
  }
}
