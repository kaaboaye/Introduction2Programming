//
//  running_modes.c
//  LineManager
//
//  Created by Mieszko Wawrzyniak on 12/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "running_modes.h"

void lines_to_lowercase(void) {
    char line[LINE_LEN];
    
    while (fgets(line, LINE_LEN, stdin)) {
        line_to_lowercase(line);
        printf("%s", line);
    }
}

void lines_to_uppercase(void) {
    char line[LINE_LEN];
    
    while (fgets(line, LINE_LEN, stdin)) {
        line_to_uppercase(line);
        printf("%s", line);
    }
}

void lines_swap(void) {
    char line[LINE_LEN];
    
    while (fgets(line, LINE_LEN, stdin)) {
        line_swap(line);
        printf("%s", line);
    }
}

void lines_to_sentence(void) {
    char line[LINE_LEN];
    
    while (fgets(line, LINE_LEN, stdin)) {
        line_to_sentence(line);
        printf("%s", line);
    }
}
