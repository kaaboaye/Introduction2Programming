//
//  selectors.c
//  RangeSelection
//
//  Created by Mieszko Wawrzyniak on 12/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "selectors.h"

void run_with(bool (*mode)(const config*, const char*), const config *conf) {
  char line[LINE_LEN];
  char word[LINE_LEN];
  
  while (fgets(line, LINE_LEN, stdin)) {
    get_first_word(line, word, LINE_LEN);
    
    if ((*mode)(conf, word)) { // If lines fulfill expectations
      printf("%s", line);
    }
  }
}

bool word_begins(const config *conf, const char *word) {
  const char *pattern = conf->arg1;
  
  return (strcmp(pattern, word) <= 0);
}

bool word_in_range(const config *conf, const char *word) {
  return (word_begins(conf, word) &&
          word_ends(conf, word));
}

bool word_ends(const config *conf, const char *word) {
  const char *pattern = conf->arg2;
  
  return (strcmp(pattern, word) >= 0);
}



void get_first_word(const char *line, char *word, int len) {
  int i;
  
  for (i = 0; i < len - 1; ++i) {
    if (isspace(line[i])) {
        word[i] = 0;
        break;
    }
    
    word[i] = line[i];
  }
  
  // Overflow guard
  if (i == len - 1) {
    word[++i] = 0;
  }
}
