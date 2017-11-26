//
//  processor.c
//  calaculator
//
//  Created by Mieszko Wawrzyniak on 26/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "processor.h"

void StartProcessing() {
  NextOperation = operation_null;
  Ans = 0;
  
  while (true) {
    Update();
  }
}

void Update() {
  ReadToken();
  Process();
}

void ReadToken() {  
  TokenNumber = NAN;
  
  if (EOF == scanf("%255s", token)) {
    exit(0);
  }
  
  // Detect token type
  if (
      // Addiction
      TOKEN_IS("+") ||
      TOKEN_IS("add") ||
      TOKEN_IS("plus")
      )
  { Token = token_addition; }
  else if (
           // Subtraction
           TOKEN_IS("-") ||
           TOKEN_IS("subtract") ||
           TOKEN_IS("minus")
           )
  { Token = token_subtraction; }
  else if (
           // Multiplication
           TOKEN_IS("*") ||
           TOKEN_IS("times")
           )
  { Token = token_multiplication; }
  else if (
           // Division
           TOKEN_IS("/")
           )
  { Token = token_division; }
  else if (
           // Equals
           TOKEN_IS("=") ||
           TOKEN_IS("equals")
           )
  { Token = token_equals; }
  else if (
           // Ans
           TOKEN_IS("ans") ||
           TOKEN_IS("prev") ||
           TOKEN_IS("prev_result")
           )
  { Token = token_ans; }
  else if (
           // Number
           EOF != sscanf(token, "%Lf", &TokenNumber))
  {
    if (isnan(TokenNumber)) {
      Token = token_error;
    }
    else {
      Token = token_number;
    }
  }
  else // Error
  { Token = token_error; }
  // End of detection token type
  
}

void Process() {
  switch (Token) {
    case token_error:
      ErrorHandler(token);
      break;
    case token_addition:
      AdditionHandler();
      break;
    case token_subtraction:
      SubtractonHandler();
      break;
    case token_multiplication:
      MultiplicationHandler();
      break;
    case token_division:
      DivisionHandler();
      break;
    case token_equals:
      EqualsHandler();
      break;
    case token_ans:
      AnsHandler();
      break;
    case token_number:
      NumberHaandler();
      break;
  }
}
