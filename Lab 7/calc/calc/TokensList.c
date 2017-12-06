//
//  TokensList.c
//  calc
//
//  Created by Mieszko Wawrzyniak on 29/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "TokensList.h"

TokensList newTokensList(void) {
  TokensList tl;
  
  tl.Count = 0;
  tl.Tokens = (Token *) malloc(0 * sizeof(Token));
  
  return tl;
}

void TokensListAdd(TokensList *tl) {
  tl->Count++;
  tl->Tokens = (Token *) realloc(tl->Tokens, (tl->Count) * sizeof(Token));
  tl->Last = &tl->Tokens[tl->Count - 1];
}

void TokensListAddElement(TokensList *tl, const Token token) {
  TokensListAdd(tl);
  
  tl->Last->Type = token.Type;
  tl->Last->Value = token.Value;
}

