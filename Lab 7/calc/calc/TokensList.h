//
//  TokensList.h
//  calc
//
//  Created by Mieszko Wawrzyniak on 29/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#ifndef TokensList_h
#define TokensList_h

#include <stdlib.h>

#include "Token.h"

typedef struct {
  Token *Tokens;
  Token *Last;
  unsigned int Count;
} TokensList;

TokensList newTokensList(void);
void TokensListAdd(TokensList *tl);
void TokensListAddElement(TokensList *tl, const Token token);

#endif /* TokensList_h */
