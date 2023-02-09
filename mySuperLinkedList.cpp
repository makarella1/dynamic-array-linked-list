#include "mySuperLinkedList.h"
#include "iphone.h"

MySuperLinkedList::MySuperLinkedList()
{
  head = nullptr;
  size = 0;
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
  if (head == nullptr)
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

  return;
}

IPhone MySuperLinkedList::get(int index)
{
  if (index >= 0 && index < size)
  {
    int countIndex = 0;

    Node *current = head;

    for (int i = 0; i < index; i++)
    {
      current = current->next;
    }

    return current->iphone;
  }
}

IPhone MySuperLinkedList::popFront()
{
  if (head == nullptr)
  {
    std::cerr << "You're hopeless, take a dummy data as there's nothing else I can give you!" << std::endl;

    IPhone dummy = IPhone();

    return dummy;
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
  if (head == nullptr)
  {
    std::cerr << "You're hopeless, take a dummy data as there's nothing else I can give you!" << std::endl;

    IPhone dummy = IPhone();

    return dummy;
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

  IPhone currentData = current->next->iphone;

  delete current->next;

  current->next = nullptr;

  --size;

  return currentData;
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