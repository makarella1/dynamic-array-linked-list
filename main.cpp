#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mySuperLinkedList.cpp"
#include "mySuperDynamicArray.cpp"
#include "benchmark.cpp"
#include "iphone.cpp"

main()
{
  srand(time(NULL));

  MySuperDynamicArray array;
  MySuperLinkedList list;

  runBenchmarks(array, "DYNAMIC ARRAY");
  runBenchmarks(list, "LINKED LIST");
}