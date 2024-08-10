#ifndef PARSE_H
#define PARSE_H

#include <stdint.h>

typedef enum {
  COMMAND_INIT,
  COMMAND_SHOW,
  COMMAND_REMOVE,
  COMMAND_DELETE,
  COMMAND_INSERT,
  COMMAND_SELECT,
  COMMAND_RETURN,
  COMMAND_UNKNOWN
} Command;

Command parseCommand(char *source);

#endif
