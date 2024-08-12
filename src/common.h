#ifndef COMMON_H
#define COMMON_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#endif
