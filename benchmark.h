#pragma once

struct BenchmarkBase
{
  virtual void pushBack(IPhone iphone);
  virtual void pushFront(IPhone iphone);
  virtual int getSize();
  virtual IPhone get(int index);
  virtual IPhone popFront();
  virtual IPhone popBack();
};