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
void run_with(bool (*mode)(const char*));

bool word_begins(const char *word);
bool word_in_range(const char *word);
bool word_ends(const char *word);

#endif /* selectors_h */
