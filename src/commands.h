#ifndef COMMANDS_H
#define COMMANDS_H

#include "parse.h"
#include <stdint.h>

// Database Functions
void initializeDatabase(char *path, int argc, char *argv[]);
void showDatabase(int argc, char *argv[]);

// Row Functions
void insertRow(char *path, int argc, char *argv[]);
void returnRow(char *path, int argc, char *argv[]);
// void selectRow(char *path, int argc, char *argv[]);
// void removeRow(char *path, int argc, char *argv[]);
// void deleteRow(char *path, int argc, char *argv[]);
void returnRow(char *path, int argc, char *argv[]);
#endif
