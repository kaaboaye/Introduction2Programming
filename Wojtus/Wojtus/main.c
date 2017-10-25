//
//  main.c
//  Wojtus
//
//  Created by Mieszko Wawrzyniak on 25/10/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
  float temp;
  
  printf("Podaj toplote: ");
  if (!scanf("%f", &temp))
  {
    puts("Podaj liczbe cfelu");
    return 0xDEADC0DE;
  }
  
  printf("Toplota: %f\n", temp);
  if (temp > 15) puts("Ujdzie");
  else puts("Kurwa pizga");
  
  return 0;
}
