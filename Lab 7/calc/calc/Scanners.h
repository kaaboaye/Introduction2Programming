//
//  Scanners.h
//  calc
//
//  Created by Mieszko Wawrzyniak on 28/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#ifndef Scanners_h
#define Scanners_h

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "Const.h"

#define FLOAT_CHAR (isdigit(c) || c == '.')

bool next_float(char *str, const int len);

#endif /* Scanners_h */
