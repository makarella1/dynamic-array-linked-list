#include <iostream>
#include "mySuperDynamicArray.h"
#include "iphone.h"

const int GROWTH_FACTOR = 2;
const int CAPACITY = 5;

MySuperDynamicArray::MySuperDynamicArray()
{
  size = 0;
  capacity = CAPACITY;
  iphones = new IPhone[CAPACITY];
}

void MySuperDynamicArray::reallocIfFull()
{
  if (size == capacity)
  {
    capacity *= GROWTH_FACTOR;

    IPhone *temp = new IPhone[capacity];

    for (int i = 0; i < size; i++)
    {
      temp[i] = iphones[i];
    }

    delete[] iphones;

    iphones = temp;
  }
}

bool MySuperDynamicArray::isEmpty()
{
  return size == 0;
}

void MySuperDynamicArray::pushFront(IPhone iphone)
{
  reallocIfFull();

  for (int i = size; i > 0; i--)
  {
    iphones[i] = iphones[i - 1];
  }

  iphones[0] = iphone;
  size++;
}

IPhone MySuperDynamicArray::popFront()
{
  if (isEmpty())
  {
    std::cerr << "What exactly were you going to pop? The array's empty!" << std::endl;
    exit(1);
  }

  IPhone iphone = iphones[0];

  for (int i = 0; i < size; i++)
  {
    iphones[i] = iphones[i + 1];
  }

  size--;

  return iphone;
}

void MySuperDynamicArray::pushBack(IPhone iphone)
{
  reallocIfFull();

  iphones[size++] = iphone;
}

IPhone MySuperDynamicArray::popBack()
{
  if (isEmpty())
  {
    std::cerr << "Haven't you learned your lesson? Nothing to pop!" << std::endl;
    exit(1);
  }

  return iphones[--size];
}

IPhone MySuperDynamicArray::get(int index)
{
  if (index <= 0 && index > size)
  {
    std::cerr << "Provide a valid index or go hit the books and learn how arrays work!" << std::endl;
    exit(1);
  }

  return iphones[index];
}

int MySuperDynamicArray::getSize()
{
  return size;
}

void MySuperDynamicArray::print()
{
  for (int i = 0; i < size; i++)
  {
    std::cout << "IPhone's model: " << iphones[i].model << std::endl;
    std::cout << "IPhone's color: " << iphones[i].color << std::endl;
    std::cout << "Has charger: " << (iphones[i].hasCharger ? "Yes" : "No") << std::endl;

    std::cout << "\n";
  }
}