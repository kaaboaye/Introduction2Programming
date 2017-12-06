//
//  TokenType.h
//  calc
//
//  Created by Mieszko Wawrzyniak on 29/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#ifndef TokenType_h
#define TokenType_h

typedef enum {
  type_undefined,
  type_incorrect,
  type_operation,
  type_number
} TokenType;

#endif /* TokenType_h */
