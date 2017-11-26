//
//  helpers.c
//  calaculator
//
//  Created by Mieszko Wawrzyniak on 26/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "helpers.h"

void ErrorHandler(const char *token) {
  fprintf(stderr, "Processing error: Unknow token: \"%s\".\n", token);
}

void AdditionHandler() {
  NextOperation = operation_addiction;
}

void SubtractonHandler() {
  NextOperation = operation_subtraction;
}

void MultiplicationHandler() {
  NextOperation = operation_multiplication;
}

void DivisionHandler() {
  NextOperation = operation_division;
}

void EqualsHandler() {
  printf("%.15Lf\n", Result);
  Ans = Result;
  NextOperation = operation_null;
}

void AnsHandler() {
  // Pretend to the last result has been typed.
  TokenNumber = Ans;
  NumberHaandler();
}

void NumberHaandler() {
  switch (NextOperation) {
    case operation_null:
      Result = TokenNumber;
      break;
    case operation_addiction:
      Result += TokenNumber;
      break;
    case operation_subtraction:
      Result -= TokenNumber;
      break;
    case operation_multiplication:
      Result *= TokenNumber;
      break;
    case operation_division:
      Result /= TokenNumber;
      break;
  }
  
  NextOperation = operation_null;
}
