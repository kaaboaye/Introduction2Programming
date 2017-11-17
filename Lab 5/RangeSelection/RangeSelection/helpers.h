//
//  helpers.h
//  RangeSelection
//
//  Created by Mieszko Wawrzyniak on 15/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#ifndef helpers_h
#define helpers_h

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 Sets first word to `word` argument from given line.
 
 @param line Input line
 @param word Output word
 @param len Word length
 */
void get_first_word(const char *line, char *word, int len);

/**
 Checks if given string is "-"
 
 @param str Input string
 @return Indicator
 */
bool _is_dash(const char *str);

/**
 Makes all characters lowercase.

 @param str String to convert
 */
void string_to_lowercase(char *str);


/**
 Reverses characters in given string.

 @param str String to convert
 */
void string_reverse(char *str);

#endif /* helpers_h */
