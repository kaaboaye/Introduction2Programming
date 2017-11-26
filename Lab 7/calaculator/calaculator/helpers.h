//
//  helpers.h
//  calaculator
//
//  Created by Mieszko Wawrzyniak on 26/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#ifndef helpers_h
#define helpers_h

#include <stdio.h>

#include "processor.h"

void ErrorHandler(const char *token);
void AdditionHandler(void);
void SubtractonHandler(void);
void MultiplicationHandler(void);
void DivisionHandler(void);
void EqualsHandler(void);
void AnsHandler(void);
void NumberHaandler(void);

#endif /* helpers_h */
