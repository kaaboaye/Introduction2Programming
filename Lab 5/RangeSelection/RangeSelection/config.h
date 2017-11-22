//
//  config.h
//  RangeSelection
//
//  Created by Mieszko Wawrzyniak on 12/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#ifndef config_h
#define config_h

#include <stdio.h>
#include <unistd.h>

#include "helpers.h"

/**
 Running mode
 
 This enum determinates mode which should be used in order to
 run the application.
 */
typedef enum {
  rm_line_begins,
  rm_word_begins,
  rm_word_in_range,
  rm_word_ends,
} running_mode;

/**
 Application config
 */
typedef struct {
  bool case_sensitive;
  bool reverse;
  char *arg1;
  char *arg2;
  running_mode rm;
  
} config;

extern config conf;

/**
 config's constructor.
 */
void new_config(int argc, char * argv[]);

/**
 Reads config from given parameters and sets it to the given object.
 */
void read_config(int argc, char * argv[]);

void set_config(int argc, char * argv[]);

void apply_not_casesensitive(void);
void apply_reverse(void);

/**
 Prints user freandly usage message :v
 */
void print_usage(void);

#endif /* config_h */
