//
//  simple.c
//  LinesWith
//
//  Created by Mieszko Wawrzyniak on 04/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "simple.h"

void lines_with(const char c)
{
  char line[LINE_LEN];
  
  while (fgets(line, LINE_LEN, stdin))
  {
    if (contains(c, line))
    {
      printf("%s", line);
    }
  }
}

bool contains(const char c, char *line)
{
  for (int i = 0; line[i]; i++)
  {
    if (c == line[i])
    {
      return true;
    }
  }
  
  return false;
}
