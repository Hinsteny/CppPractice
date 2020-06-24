#include "task/NumberFactory.h"
#include "thread/PrintNumberJob.h"

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using namespace Process;

// declaration function
void printSomeNumbers(int count);
// declaration function
void printSomeNumbersAsync(int count);

int main() {
  printSomeNumbers(10);
  printSomeNumbersAsync(10);
  
}

// implements function
void printSomeNumbers(int count) {
  int *numbers = new int[count];
  Process::NumberFactory numberFactory;
  numberFactory.random(numbers, count);
  for (size_t i = 0; i < count; i++) {
    cout << "[" << i << "]:" << numbers[i] << endl;
  }
  delete []numbers;
}


// implements function
void printSomeNumbersAsync(int count) {
  int *numbers = new int[count];
  Process::NumberFactory numberFactory;
  numberFactory.random(numbers, count);
  printSomeNumbers(numbers, count);
  delete []numbers;
}