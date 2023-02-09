#pragma once

struct BenchmarkBase
{
  virtual void pushBack(IPhone iphone) = 0;
  virtual void pushFront(IPhone iphone) = 0;
  virtual int getSize() = 0;
  virtual IPhone get(int index) = 0;
  virtual IPhone popFront() = 0;
  virtual IPhone popBack() = 0;

  virtual ~BenchmarkBase(){};
};