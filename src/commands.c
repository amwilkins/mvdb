#include <stdio.h>
#include <stdlib.h>

#include "commands.h"

FILE *createAndOpen(char *path) {
  FILE *file = fopen(path, "r+");

  // if file does not exist, create it
  if (!file) {
    FILE *file = fopen(path, "w");
    fclose(file);
    file = fopen(path, "r+");
    return file;
  } else {
    return file;
  }
}

char *readFile(char *path) {
  FILE *file = createAndOpen(path);
  char *buffer;

  if (!file) {
    fprintf(stderr, "Could not open file\n");
    exit(1);
  }

  // get size of file
  fseek(file, 0L, SEEK_END);
  size_t file_size = ftell(file);
  rewind(file);

  // allocate memory for the file
  buffer = (char *)malloc(file_size + 1); // plus 1 for null terminator
  if (!buffer) {
    fprintf(stderr, "Failed to allocate memory for file\n");
    fclose(file);
    exit(1);
  }
  size_t bytesRead = fread(buffer, sizeof(char), file_size, file);

  // null terminator
  buffer[bytesRead] = '\0';

  fclose(file);
  return buffer;
}

void initializeDatabase(char *path, int argc, char **argv) {
  char *source = readFile(argv[1]);

  // if source is not empty, do not overwrite
  if (source[0] != '\0') {
    printf("ERROR: File already contains data\n");
    free(source);
    exit(1);
  }

  printf("Initializing new data file\n");
  // write initial data to file
  FILE *file;
  file = fopen(path, "w");
  fprintf(file, "_id ");
  for (int i = 3; i < argc; i++) {
    fprintf(file, "%s ", argv[i]);
  }
  fclose(file);
  free(source);
}

void showDatabase(char *path, int argc, char *argv[]) {
  char *source = readFile(argv[1]);
  FILE *file = fopen(path, "r");
  printf("%s\n", source);
  free(source);
}

void insertDatabase(char *path, int argc, char *argv[]) {
  char *source = readFile(argv[1]);
  FILE *file = fopen(path, "a+");
  char c;
  int count = 0;

  for (c = getc(file); c != EOF; c = getc(file))
    if (c == '\n')
      count = count + 1;

  fprintf(file, "\n");

  // create index
  fprintf(file, "%d ", count);

  // insert data
  for (int i = 3; i < argc; i++) {
    fprintf(file, "%s ", argv[i]);
  }
  fclose(file);
}
