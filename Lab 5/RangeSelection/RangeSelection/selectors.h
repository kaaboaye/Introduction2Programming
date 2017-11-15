//
//  selectors.h
//  RangeSelection
//
//  Created by Mieszko Wawrzyniak on 12/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#ifndef selectors_h
#define selectors_h

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "config.h"
#include "consts.h"


/**
 Starts program egecution in given mode

 @param mode Function wich will decide wether to print line or not.
 */
void run_with(bool (*mode)(const config*, const char*), const config *conf);

bool word_begins(const config *conf, const char *word);
bool word_in_range(const config *conf, const char *word);
bool word_ends(const config *conf, const char *word);

/**
 Sets first word to `word` argument from given line.

 @param line Input line
 @param word Output word
 @param len Word length
 */
void get_first_word(const char *line, char *word, int len);

#endif /* selectors_h */
