//
//  selectors.c
//  RangeSelection
//
//  Created by Mieszko Wawrzyniak on 12/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "selectors.h"

void run_with(bool (*mode)(const char*)) {
  char line[LINE_LEN];
  char word[LINE_LEN];
  
  while (fgets(line, LINE_LEN, stdin)) {
    get_first_word(line, word, LINE_LEN);
    
    if (!conf.case_sensitive) {
      // Convert string to lowercase in order to be not case sensitive.
      string_to_lowercase(word);
    }
    
    if (conf.reverse) {
      // Reverse string in order to check end of the word
      string_reverse(word);
    }
    
    if ((*mode)(word)) { // If lines fulfill expectations
      printf("\t%s", line);
    }
  }
}

bool word_begins(const char *word) {
  const char *pattern = conf.arg1;
  
  return (strcmp(pattern, word) <= 0);
}

bool word_in_range(const char *word) {
  return (word_begins(word) &&
          word_ends(word));
}

bool word_ends(const char *word) {
  const char *pattern = conf.arg2;
  
  return (strcmp(pattern, word) >= 0);
}
