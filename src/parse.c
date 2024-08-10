#include <stdio.h>
#include <string.h>

#include "parse.h"

Command parseCommand(char *source) {
  char *token = NULL;
  Command command;

  token = strtok_r(source, " ", &source);
  if (strncmp(token, "INSERT", 6) == 0) {
    return COMMAND_INSERT;
  } else if (strncmp(token, "INIT", 4) == 0) {
    return COMMAND_INIT;
  } else if (strncmp(token, "REMOVE", 6) == 0) {
    return COMMAND_INIT;
  } else if (strncmp(token, "DELETE", 6) == 0) {
    return COMMAND_DELETE;
  } else if (strncmp(token, "SHOW", 4) == 0) {
    return COMMAND_SHOW;
  } else if (strncmp(token, "SELECT", 6) == 0) {
    return COMMAND_SELECT;
  } else if (strncmp(token, "RETURN", 6) == 0) {
    return COMMAND_RETURN;
  } else {
    return COMMAND_UNKNOWN;
  }
}
