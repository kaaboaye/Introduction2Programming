//
//  Processor.c
//  calc
//
//  Created by Mieszko Wawrzyniak on 28/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "Processor.h"

void ProcessorInit() {
  
}

bool ProcessToken() {
  char token[TOKEN_SIZE];
  
  if (next_float(token, TOKEN_SIZE)) {
    AddToken();
    
    Tokens.Last->Type = type_number;
    Tokens.Last->Value.Number = atof(token);
  }
  
  return true;
}

void AddToken() {
  Tokens.Count++;
  Tokens.Tokens = (Token *) realloc(Tokens.Tokens, (Tokens.Count) * sizeof(Token));
  Tokens.Last = &Tokens.Tokens[Tokens.Count - 1];
}
