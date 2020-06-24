#pragma once

#include "../threadpool/ThreadPool.h"

#include <iostream>

using std::cout;
using std::endl;

void printlnNumber(const int anumber) {
  cout << anumber << endl;
}

// Simple function that adds multiplies two numbers and returns the result
int multiply(const int a, const int b) {
  const int res = a * b;
  return res;
}

void printSomeNumbers(int *arr, int count) {
  // Create pool with 3 threads
  ThreadPool pool(3);
  // Initialize pool
  pool.init();
  for (size_t i = 0; i < count; i++) {
    // The type of future is given by the return type of the function
    auto future = pool.submit(printlnNumber, arr[i]);
  }
  // Shutdown the pool, releasing all threads
  pool.shutdown();
}