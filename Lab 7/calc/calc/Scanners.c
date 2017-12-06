//
//  Scanners.c
//  calc
//
//  Created by Mieszko Wawrzyniak on 28/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "Scanners.h"

bool next_float(char *str, const int len)
{
  bool is_float = false; // Wether loop is inside of the float
  bool was_dot = false; // Determinates wether there was a dot in the float
  int i = 0; // Char no. in the integer
  char c;  // Read char
  char first_c = '\0'; // First integers character
  
  while (EOF != (c = getchar()))
  {
    // Wasn't any digit yet in the stdin
    if (!is_float && !FLOAT_CHAR) continue;
    
    // If second char is a digit if staring char was [+-]
    if (i == 1 && (first_c == '-' || first_c == '+') && !FLOAT_CHAR)
    {
      is_float = false;
      was_dot = false;
      i = 0;
      continue;
    }
    
    // Detect beginning of the float
    if (!is_float && FLOAT_CHAR)
    {
      is_float = true;
      first_c = c;
    }
    
    // Second dot detection
    else if (is_float && was_dot && c == '.')
    {
      str[++i] = 0;
      return true;
    }
    
    // End of the float
    else if (is_float && !FLOAT_CHAR)
    {
      str[++i] = 0;
      return true;
    }
    
    // Set flag preventing multiple dots
    if (is_float && c == '.') was_dot = true;
    
    // Override guard
    if (i == len - 1)
    {
      str[++i] = 0;
      return false;
    }
    
    str[i] = c; // Add char to the string
    i++; // It's not for loop because incrementation can happen only when added
    //       char to string.
  }
  
  // End of file
  if (is_float) return true;
  return false;
}
