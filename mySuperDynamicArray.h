#pragma once

#include "iphone.h"
#include "benchmark.h"

const int CAPACITY = 5;

struct MySuperDynamicArray : public BenchmarkBase
{
private:
  IPhone *iphones;
  int size;
  int capacity;

  void reallocIfFull();

  bool isEmpty();

public:
  MySuperDynamicArray();
  ~MySuperDynamicArray() override = default;

  void pushFront(IPhone iphone) override;

  IPhone popFront() override;

  void pushBack(IPhone iphone) override;

  IPhone popBack() override;

  IPhone get(int index) override;

  int getSize() override;

  void print();
};