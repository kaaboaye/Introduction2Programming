//
// Created by Mieszko Wawrzyniak on 28/12/2017.
//

#ifndef LAB_9_SIGN_H
#define LAB_9_SIGN_H

/**
 * Sign function for int input
 * @return {-1, 0 ,1}
 */
int sign_i(int);

#define sign(num) \
  (((num) > 0) - ((num) < 0))

#endif //LAB_9_SIGN_H
