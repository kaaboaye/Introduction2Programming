//
//  Token.c
//  calc
//
//  Created by Mieszko Wawrzyniak on 29/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "Token.h"

void FindNext(Token *t) {
  char token[TOKEN_SIZE];
  char c;
  bool wastDot = false;
  
  t->Type = type_undefined;
  
  for (int i = 0; EOF != (c = getchar()); i++) {
    if (isspace(c)) {
      i--;
      continue;
    }
    
    // Read float
    if (IS_FLOAT_C(c)) {
      if (t->Type == type_undefined) {
        t->Type = type_number;
      }
      
      if (t->Type != type_number) {
        ungetc(c, stdin);
        break;
      }
      
      if (c == '.' && wastDot) {
        INCORRECT();
      }
      
      if (c == '.' && !wastDot) {
        wastDot = true;
      }
      
      if (i == TOKEN_SIZE - 1) {
        token[i] = 0;
        break;
      }
    }
    
    // Read none float
    else {
      if (t->Type == type_undefined) {
        t->Type = type_operation;
      }
      
      if (t->Type != type_operation) {
        ungetc(c, stdin);
        break;
      }
      
      if (i == TOKEN_SIZE - 1) {
        token[i] = 0;
        break;
      }
    }
    
    token[i] = c;
    
  }
}
