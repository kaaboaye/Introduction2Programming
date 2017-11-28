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
  
  // Addiction
  if (
      TOKEN_IS("+") ||
      TOKEN_IS("add") ||
      TOKEN_IS("plus")
      ) {
    Token = token_addition;
    return;
  }
  
  // Subtraction
  if (
     TOKEN_IS("-") ||
     TOKEN_IS("subtract") ||
     TOKEN_IS("minus")
     ) {
    Token = token_subtraction;
    return;
  }
  
  // Multiplication
  if (
     TOKEN_IS("*") ||
     TOKEN_IS("times")
     ) {
    Token = token_multiplication;
    return;
  }
  
  // Division
  if (
     TOKEN_IS("/")
     ) {
    Token = token_division;
    return;
  }
  
  // Equals
  if (
      TOKEN_IS("=") ||
      TOKEN_IS("equals")
      ) {
    Token = token_equals;
    return;
  }
  
  // Ans
  if (
     TOKEN_IS("ans") ||
     TOKEN_IS("prev") ||
     TOKEN_IS("prev_result")
     ) {
    Token = token_ans;
    return;
  }
  
  // Number
  if (EOF != sscanf(token, "%Lf", &TokenNumber)) {
    if (isnan(TokenNumber)) {
      Token = token_error;
      return;
    }
    
    Token = token_number;
    return;
  }
  
  // Error
  Token = token_error;
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
