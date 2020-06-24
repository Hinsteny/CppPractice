#pragma once

#include "NumberFactory.h"

#include <iostream>
#include <cstdint>
#include <string>

namespace Process {

  void NumberFactory::random(int *arr, int count) {
    for (size_t i = 0; i < count; i++) {
      int number = rand() % 100 + 1;
      arr[i] = number;
    }
  }
  
} // namespace Process