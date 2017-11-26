//
//  main.c
//  calaculator
//
//  Created by Mieszko Wawrzyniak on 26/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "processor.h"

long double Result;
long double Ans;
TokenType Token;
long double TokenNumber;
OperationType NextOperation;

int main(int argc, const char * argv[]) {
  StartProcessing();
  return 0;
}
