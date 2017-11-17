//
//  helpers.c
//  RangeSelection
//
//  Created by Mieszko Wawrzyniak on 15/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "helpers.h"

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

bool _is_dash(const char *str) {
  return (strlen(str) == 1 && str[0] == '-');
}

void string_to_lowercase(char *str) {
  for (int i = 0; str[i]; ++i) {
    str[i] = tolower(str[i]);
  }
}

void string_reverse(char *str)
{
  /* skip null */
  if (str == 0)
  {
    return;
  }
  
  /* get range */
  char *start = str;
  char *end = start + strlen(str) - 1; /* -1 for \0 */
  char temp;
  
  /* reverse */
  while (end > start)
  {
    /* swap */
    temp = *start;
    *start = *end;
    *end = temp;
    
    /* move */
    ++start;
    --end;
  }
}
