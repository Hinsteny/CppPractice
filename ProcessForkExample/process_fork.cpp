#include "task/NumberFactory.h"
#include "thread/PrintNumberJob.h"
#include "info/RuntimeInfoMac.h"
#include "utils/DataSizeUtil.h"

#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>

using std::cout;
using std::endl;
using namespace Process;

// declaration function
void printSomeNumbers(int count);
// declaration function
void printSomeNumbersAsync(int count);
// declaration function
void printProcessInfo();

int main() {
  // printSomeNumbers(10);
  // printSomeNumbersAsync(10);
  printProcessInfo();
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

// implements function
void printProcessInfo() {
  int pid = getpid();
  cout << pid << endl;
  RunProcDyn rpd;
  run_get_dynamic_proc_info(pid, &rpd);
  cout << rpd.rss << " Bytes, " << dataSizeConversion(false, rpd.rss, 1) << " KB ;" << endl;
  cout << rpd.vsize << " Bytes, " <<  dataSizeConversion(false, rpd.vsize, 2) << " MB ;" << endl;
}