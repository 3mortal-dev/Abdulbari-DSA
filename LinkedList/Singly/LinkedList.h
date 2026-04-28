#include <iostream>
#include <limits>
#include <stdexcept>
#include <initializer_list>
#include "Node.h"

template <typename T>
class LinkedList
{
private:
  Node<T> *head;
  Node<T> *tail;
  void isEmptyHelper() const
  {
    if (this->isEmpty())
      throw std::range_error("List is empty");
  };
  void deleteNextNode(Node<T> *currNode);

public:
  LinkedList() { head = nullptr, tail = nullptr; };
  LinkedList(std::initializer_list<T> values);
  LinkedList(const LinkedList<T> &list);
  ~LinkedList();

  Node<T> *getHead() const
  {
    return head;
  }
  Node<T> *getTail() const
  {
    return tail;
  }
  void iterativeDisplay();
  void recursiveDisplay();
  size_t size() const;
  T sum() const;
  T min() const;
  T max() const;
  // no binary search for linked list as we can't get to the mid of the list in O(1) :O
  Node<T> *linearSearch(T target);
  bool isEmpty() const;
  Node<T> *nodeAt(int idx) const;
  T at(int idx) const;
  void insertAt(int idx, T val);
  void insertAtHead(T data);
  void insertAtTail(T val);
  void insertAtSorted(T val);
  void deleteByIndex(int idx);
  void deleteHead();
  void deleteTail();
  void deleteFirstValue(T val);
  void deleteAllValues(T val);
  bool isSorted() const;
  void deleteDuplicatesInSortedList();
  void reverse();
  void concatenate(const LinkedList<T> &list);
  LinkedList<T> &operator=(const LinkedList<T> &list);
  void merge(const LinkedList<T> &list);
  void clear();
};