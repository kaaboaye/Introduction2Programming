//
//  processor.h
//  calaculator
//
//  Created by Mieszko Wawrzyniak on 26/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#ifndef processor_h
#define processor_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "const.h"
#include "helpers.h"

#define TOKEN_IS(str) !strncmp(str, token, sizeof(str))

typedef enum {
  token_error,
  token_addition,
  token_subtraction,
  token_multiplication,
  token_division,
  token_equals,
  token_ans,
  token_number
} TokenType;

typedef enum {
  operation_null,
  operation_addiction,
  operation_subtraction,
  operation_multiplication,
  operation_division
} OperationType;

// A current result.
extern long double Result;

// A previos result.
extern long double Ans;

// A last token type.
extern TokenType Token;

// A last token number.
extern long double TokenNumber;

// The next operation wich will be performed on the next number.
extern OperationType NextOperation;

// A token readed from stdin.
static char token[LINE_LEN];


/**
 Initialize the processor.
 */
void StartProcessing(void);

/**
 Function called at every token.
 */
void Update(void);

/**
 Token Reader.
 */
void ReadToken(void);

/**
 Token router.
 */
void Process(void);

#endif /* processor_h */
