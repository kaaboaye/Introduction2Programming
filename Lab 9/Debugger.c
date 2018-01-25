//
// Created by Mieszko Wawrzyniak on 28/12/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "Debugger.h"

void DebuggerError(const char *err) {
  fprintf(stderr, "%s", err);
  exit(1);
}