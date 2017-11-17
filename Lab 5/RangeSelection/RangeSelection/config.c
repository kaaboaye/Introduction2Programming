//
//  config.c
//  RangeSelection
//
//  Created by Mieszko Wawrzyniak on 12/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "config.h"

void new_config(int argc, char * argv[]) {
  conf.case_sensitive = true;
  conf.reverse = false;
  conf.arg1 = "";
  conf.arg2 = "";
  
  set_config(argc, argv);
  apply_not_casesensitive();
  apply_reverse();
}

void set_config(int argc, char * argv[]) {
  char c;
  int non_flags_arguments = 0;
  
  while (optind < argc) {
    if (-1 != (c = getopt(argc, argv, "ieh"))) {
      switch (c) {
        case 'i':
          conf.case_sensitive = false;
          break;
          
          case 'e':
          conf.reverse = true;
          break;
        
        case '?': case 'h':
          print_usage();
          break;
      }
    }
    else { // Read non flag arguments
      non_flags_arguments++;
    
      switch (non_flags_arguments) {
        case 1:
          conf.arg1 = argv[optind];
          break;
        
        case 2:
          conf.arg2 = argv[optind];
          break;
        
        default:
          print_usage();
          break;
      }
    
      optind++;
    }
  }
  
  // Choose running mode
  if (non_flags_arguments == 1) {
    conf.rm = rm_word_begins;
  }
  else if (non_flags_arguments == 2) {
    if (_is_dash(conf.arg1)) {
      conf.rm = rm_word_ends;
    }
    else if (_is_dash(conf.arg2)) {
      conf.rm = rm_word_begins;
    }
    else {
      conf.rm = rm_word_in_range;
    }
  }
}

void apply_not_casesensitive() {
  if (!conf.case_sensitive) {
    string_to_lowercase(conf.arg1);
    string_to_lowercase(conf.arg2);
  }
}

void apply_reverse() {
  if (conf.reverse) {
    string_reverse(conf.arg1);
    string_reverse(conf.arg2);
  }
}

void print_usage() {
  puts("Usage:");
  puts("\t-i Not case sensitive");
  puts("\t-h Prints this message");
  exit(0);
}
