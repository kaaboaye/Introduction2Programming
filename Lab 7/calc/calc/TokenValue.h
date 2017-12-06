//
//  TokenValue.h
//  calc
//
//  Created by Mieszko Wawrzyniak on 29/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#ifndef TokenValue_h
#define TokenValue_h

#include "OperationType.h"

typedef union {
  OperationType Operation;
  double Number;
} TokenValue;

#endif /* TokenValue_h */
