//
// Created by Mieszko Wawrzyniak on 28/12/2017.
//

#include "sign.h"

int sign_i(const int num) {
  return ((num > 0) - (num < 0));
}