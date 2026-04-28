#include <iostream>
#include <limits>
#include <stdexcept>
#include <initializer_list>
#include "Node.h"

template <typename T>
class DoublyLinkedList
{
private:
  Node<T> *head;
  void isEmptyHelper() const
  {
    if (this->isEmpty())
      throw std::range_error("List is empty");
  };

public:
  DoublyLinkedList() : head(nullptr) {};
  ~DoublyLinkedList();

  Node<T> *getHead() const
  {
    return head;
  }
  bool isEmpty() const
  {
    return !head;
  };
  void display();
  Node<T> *nodeAt(int idx);
  T at(int idx);
  void insert(T val);
  void insert(int idx, T val);
  void insertAtHead(T val);
  void deleteHead();
  void deleteByIndex(int idx);
  void reverse();
};