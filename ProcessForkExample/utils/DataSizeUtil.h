// -*- C++ -*-
//===------------------------ functional ----------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
// reference https://github.com/Hinsteny
//===----------------------------------------------------------------------===//

#pragma once

// Simple function that adds multiplies two numbers and returns the result
unsigned long int dataSizeConversion(const bool type, const unsigned long int input, const int series) {
  unsigned long int result = input;
  for (int i = 0; i < series; i++) {
      if (type) {
        result <<= 10;
      } else {
        result >>= 10;
      }
  }
  return result;
}
