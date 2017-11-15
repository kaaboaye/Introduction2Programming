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

int main(int argc, char * argv[]) {
  config conf = new_config();
  set_config(&conf, argc, argv);

  switch (conf.rm) {
    case rm_word_begins:
      run_with(word_begins, &conf);
      break;
    case rm_word_in_range:
      run_with(word_in_range, &conf);
      break;
    case rm_word_ends:
      run_with(word_ends, &conf);
      break;
  }
  
  return 0;
}
