#pragma once

#include "iphone.h"
#include "benchmark.h"

struct Node
{
  IPhone iphone;
  Node *next;

  Node(IPhone iphone) : iphone(iphone), next(nullptr){};
};

struct MySuperLinkedList : public BenchmarkBase
{
private:
  Node *head;
  int size;
  bool isEmpty();

public:
  MySuperLinkedList();
  ~MySuperLinkedList() override = default;

  void pushFront(IPhone iphone) override;

  void pushBack(IPhone iphone) override;

  IPhone get(int index) override;

  IPhone popFront() override;

  IPhone popBack() override;

  int getSize() override;

  void print();
};