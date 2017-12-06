//
//  Token.h
//  calc
//
//  Created by Mieszko Wawrzyniak on 29/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#ifndef Token_h
#define Token_h

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "Const.h"
#include "TokenType.h"
#include "TokenValue.h"

#define IS_FLOAT_C(c) (isdigit(c) || c == '.')

#define INCORRECT() t->Type = type_incorrect; return;

typedef struct {
  TokenType Type;
  TokenValue Value;
} Token;

void FindNext(Token *t);

#endif /* Token_h */
