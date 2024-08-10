#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdint.h>

void initializeDatabase(char *path, int argc, char *argv[]);
void showDatabase(char *path, int argc, char *argv[]);
void insertDatabase(char *path, int argc, char *argv[]);

#endif
