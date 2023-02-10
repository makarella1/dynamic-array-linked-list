#include <iostream>
#include "mySuperLinkedList.h"
#include "iphone.h"

MySuperLinkedList::MySuperLinkedList()
{
  head = nullptr;
  size = 0;
}

bool MySuperLinkedList::isEmpty()
{
  return head == nullptr;
}

void MySuperLinkedList::pushFront(IPhone iphone)
{
  Node *newHead = new Node(iphone);

  newHead->next = head;

  head = newHead;

  ++size;
}

void MySuperLinkedList::pushBack(IPhone iphone)
{
  if (isEmpty())
  {
    head = new Node(iphone);
  }
  else
  {
    Node *newTail = new Node(iphone);

    Node *current = head;

    while (current->next != nullptr)
    {
      current = current->next;
    }

    current->next = newTail;
  }
  ++size;
}

IPhone MySuperLinkedList::get(int index)
{
  if (index <= 0 && index > size)
  {
    std::cerr << "Can you just leave me alone?" << std::endl;
    exit(1);
  }

  Node *current = head;

  for (int i = 0; i < index; i++)
  {
    current = current->next;
  }

  return current->iphone;
}

IPhone MySuperLinkedList::popFront()
{
  if (isEmpty())
  {
    std::cerr << "You're hopeless, there's nothing I can give you!" << std::endl;
    exit(1);
  }

  Node *newHead = head->next;

  IPhone headData = head->iphone;

  delete head;

  head = newHead;

  --size;

  return headData;
}

IPhone MySuperLinkedList::popBack()
{
  if (isEmpty())
  {
    std::cerr << "What do you expect me to give you?" << std::endl;
    exit(1);
  }
  else if (head->next == nullptr)
  {
    IPhone headData = head->iphone;

    delete head;

    head = nullptr;

    return headData;
  }

  Node *current = head;

  while (current->next->next != nullptr)
  {
    current = current->next;
  }

  IPhone lastData = current->next->iphone;

  delete current->next;

  current->next = nullptr;

  --size;

  return lastData;
}

int MySuperLinkedList::getSize()
{
  return size;
}

void MySuperLinkedList::print()
{
  Node *current = head;

  while (current != nullptr)
  {
    std::cout << "IPhone's model: " << current->iphone.model << std::endl;
    std::cout << "IPhone's color: " << current->iphone.color << std::endl;
    std::cout << "Has charger: " << (current->iphone.hasCharger ? "Yes" : "No") << std::endl;

    std::cout << "\n";

    current = current->next;
  }
}