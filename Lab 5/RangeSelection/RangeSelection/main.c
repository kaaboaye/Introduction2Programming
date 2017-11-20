//
//  main.c
//  RangeSelection
//
//  Created by Mieszko Wawrzyniak on 12/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include <stdio.h>

#include "config.h"
#include "selectors.h"

config conf;

int main(int argc, char * argv[]) {
  new_config(argc, argv);

  switch (conf.rm) {
    case rm_line_begins:
      run_with(line_begins);
      break;
    case rm_word_begins:
      run_with(word_begins);
      break;
    case rm_word_in_range:
      run_with(word_in_range);
      break;
    case rm_word_ends:
      run_with(word_ends);
      break;
  }
  
  return 0;
}
