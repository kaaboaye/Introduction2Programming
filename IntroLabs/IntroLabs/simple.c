//
//  simple.c
//  IntroLabs
//
//  Created by Mieszko Wawrzyniak on 23/10/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "simple.h"
#include "simple_private.h"

#include "CONST.h"

void lines_with(const char c)
{
    char line[LINE_LENGHT];
    
    while (fgets(line, LINE_LENGHT, stdin))
    {
        if (contains(c, line))
        {
            printf("%s", line);
        }
    }
}

bool contains(const char c, char *line)
{
    for (int i = 0; line[i]; i++)
    {
        if (c == line[i])
        {
            return true;
        }
    }
    
    return false;
}
