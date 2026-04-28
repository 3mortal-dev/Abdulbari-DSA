#include "DoublyLinkedList.h"

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  Node<T> *current = head;
  while (current != nullptr)
  {
    Node<T> *nextNode = current->next;
    delete current;
    current = nextNode;
  }
  head = nullptr;
}
// =================================================

template <typename T>
void DoublyLinkedList<T>::display()
{
  Node<T> *temp = head;
  while (temp)
  {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << '\n';
}

// =================================================

template <typename T>
Node<T> *DoublyLinkedList<T>::nodeAt(int idx)
{
  if (isEmpty())
    throw std::out_of_range("List is empty");
  if (idx < 0)
    throw std::invalid_argument("Index cannot be negative");

  Node<T> *temp = head;
  while (idx--)
  {
    if (!temp->next)
      throw std::out_of_range("Index out of bounds");
    temp = temp->next;
  }
  return temp;
}

// =================================================

template <typename T>
T DoublyLinkedList<T>::at(int idx)
{
  return nodeAt(idx)->data;
}

// =================================================

template <typename T>
void DoublyLinkedList<T>::insert(T val)
{
  if (!head)
  {
    head = new Node<T>(val);
    return;
  }

  Node<T> *newNode = new Node<T>(val);
  Node<T> *temp = head;

  while (temp->next)
    temp = temp->next;

  temp->next = newNode;
  newNode->prev = temp;
}

// =================================================

template <typename T>
void DoublyLinkedList<T>::insert(int idx, T val)
{
  if (idx == 0)
  {
    insertAtHead(val);
    return;
  }

  Node<T> *temp = nodeAt(idx - 1);
  Node<T> *newNode = new Node<T>(val);

  newNode->next = temp->next;
  newNode->prev = temp;
  if (temp->next)
    temp->next->prev = newNode;
  temp->next = newNode;
}

// =================================================

template <typename T>
void DoublyLinkedList<T>::insertAtHead(T val)
{
  Node<T> *newNode = new Node<T>(val);
  newNode->next = head;
  if (head)
    head->prev = newNode;
  head = newNode;
}

// =================================================

template <typename T>
void DoublyLinkedList<T>::deleteHead()
{
  isEmptyHelper();
  Node<T> *oldHead = head;
  head = head->next;
  if (head)
    head->prev = nullptr;
  delete oldHead;
}

// =================================================

template <typename T>
void DoublyLinkedList<T>::deleteByIndex(int idx)
{
  isEmptyHelper();
  if (idx == 0)
  {
    deleteHead();
    return;
  }
  Node<T> *deletion = nodeAt(idx);
  deletion->prev->next = deletion->next;
  if (deletion->next)
    deletion->next->prev = deletion->prev;
  delete deletion;
}

// =================================================

template <typename T>
void DoublyLinkedList<T>::reverse()
{
  if (isEmpty())
    return;

  Node<T> *temp = head;
  while (temp)
  {
    std::swap(temp->next, temp->prev);
    if (!temp->prev)
      head = temp;
    temp = temp->prev;
  }
}

// =================================================
int main()
{
  DoublyLinkedList<int> list;
  list.insert(4);
  list.insert(5);
  std::cout << list.at(1);
}