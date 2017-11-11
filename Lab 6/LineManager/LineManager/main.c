//
//  main.c
//  LineManager
//
//  Created by Mieszko Wawrzyniak on 11/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>

#include "running_modes.h"

int main(int argc, char * argv[]) {
    char option;
    
    option = getopt(argc, argv, "lLuUcCnN");
    
    switch (option) {
        case 'l': case 'L':
            lines_to_lowercase();
            break;
            
        case 'u': case 'U':
            lines_to_uppercase();
            break;
            
        case 'c': case 'C':
            lines_swap();
            break;
            
        case 'n': case 'N':
            lines_to_sentence();
            break;
            
        default:
            lines_to_uppercase();
            break;
    }
    
    return 0;
}
