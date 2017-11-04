//
//  Greetings.c
//  IntroLabs
//
//  Created by Mieszko Wawrzyniak on 22/10/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include <stdio.h>

#include "greetings.h"

void write_message(int times)
{
    while (times - 1)
    {
        times--;
        puts("I am happy to be here!");
    }
}
