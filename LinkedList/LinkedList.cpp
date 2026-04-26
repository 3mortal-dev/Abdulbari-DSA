#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
  head = tail = nullptr;
  Node<T> *temp = list.getHead();
  while (temp)
  {
    insertAtTail(temp->data);
    temp = temp->next;
  }
}

// ==================================

template <typename T>
LinkedList<T>::~LinkedList()
{
  Node<T> *current = head;
  while (current != nullptr)
  {
    Node<T> *nextNode = current->next;
    delete current;
    current = nextNode;
  }
  head = tail = nullptr;
}

// ==================================

template <typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> values)
{
  head = tail = nullptr;
  for (const auto &v : values)
    insertAtTail(v);
}

// ==================================

template <typename T>
void LinkedList<T>::iterativeDisplay()
{
  Node<T> *temp = this->head;
  while (temp)
  {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << '\n';
}

// ==================================

template <typename T>
void LinkedList<T>::recursiveDisplay()
{
  if (!head)
    return;
  std::cout << head->data << " ";
  Node<T> *temp = head;
  head = head->next;
  this->recursiveDisplay();
  head = temp;
}

// ==================================

template <typename T>
size_t LinkedList<T>::size() const
{
  size_t count = 0;
  Node<T> *temp = head;
  while (temp)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

// ==================================

template <typename T>
T LinkedList<T>::sum() const
{
  T sum = 0;
  Node<T> *temp = head;
  while (temp)
  {
    sum += temp->data;
    temp = temp->next;
  }
  return sum;
}

// ==================================

template <typename T>
T LinkedList<T>::min() const
{
  T mini = std::numeric_limits<T>::max();
  Node<T> *temp = head;
  while (temp)
  {
    if (temp->data < mini)
      mini = temp->data;
    temp = temp->next;
  }
  return mini;
}

// ==================================

template <typename T>
T LinkedList<T>::max() const
{
  T maxi = std::numeric_limits<T>::lowest();
  Node<T> *temp = head;
  while (temp)
  {
    if (temp->data > maxi)
      maxi = temp->data;
    temp = temp->next;
  }
  return maxi;
}

// ==================================

template <typename T>
Node<T> *LinkedList<T>::linearSearch(T target)
{
  Node<T> *temp = head;
  while (temp)
  {
    if (temp->data == target)
      return temp;
    temp = temp->next;
  }
  return nullptr;
}

// ==================================

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  return !head;
}

// ==================================

template <typename T>
Node<T> *LinkedList<T>::nodeAt(int idx) const
{
  if (isEmpty())
    throw std::out_of_range("List is empty");
  if (idx < 0)
    throw std::invalid_argument("Index cannot be negative");

  Node<T> *temp = this->head;
  while (idx--)
  {
    if (!temp->next)
      throw std::out_of_range("Index out of bounds");
    temp = temp->next;
  }
  return temp;
}

// ==================================

template <typename T>
T LinkedList<T>::at(int idx) const
{
  return nodeAt(idx)->data;
}

// ==================================

template <typename T>
void LinkedList<T>::insertAt(int idx, T val)
{
  if (idx == 0)
  {
    insertAtHead(val);
    return;
  }
  Node<T> *currNode = nodeAt(idx - 1); // idx - 1 cause we want to make a new node at this index not after it
  Node<T> *newNode = new Node<T>(val);
  newNode->next = currNode->next;
  currNode->next = newNode;
  if (!newNode->next)
    tail = newNode;
}

// ==================================

template <typename T>
void LinkedList<T>::insertAtHead(T data)
{
  Node<T> *newNode = new Node<T>(data);
  newNode->next = head;
  head = newNode;
  if (!tail)
    tail = newNode;
}

// ==================================

template <typename T>
void LinkedList<T>::insertAtTail(T val)
{
  Node<T> *newNode = new Node<T>(val);
  if (!head)
  {
    head = tail = newNode;
    return;
  }
  tail->next = newNode;
  tail = newNode;
}

// ==================================

template <typename T>
void LinkedList<T>::insertAtSorted(T val)
{
  int count = 0;
  Node<T> *p = head;

  while (p)
  {
    if (p->data > val)
      break;
    count++;
    p = p->next;
  }

  insertAt(count, val);
}

// ==================================

template <typename T>
void LinkedList<T>::deleteByIndex(int idx)
{
  if (idx == 0)
  {
    deleteHead();
    return;
  }

  Node<T> *nodeBeforeIdx = nodeAt(idx - 1);
  Node<T> *currNode = nodeBeforeIdx->next;

  if (!currNode)
    throw std::out_of_range("Index out of bounds");

  if (currNode == tail)
  {
    deleteTail();
    return;
  }

  nodeBeforeIdx->next = currNode->next;
  delete currNode;
}

// ==================================

template <typename T>
void LinkedList<T>::deleteHead()
{
  isEmptyHelper();

  Node<T> *oldHead = head;
  head = head->next;

  if (!head)
    tail = head;
  delete oldHead;
}

// ==================================

template <typename T>
void LinkedList<T>::deleteNextNode(Node<T> *currNode)
{
  if (!currNode || !currNode->next)
    throw std::invalid_argument("Invalid node");

  Node<T> *oldNode = currNode->next;
  currNode->next = oldNode->next;
  if (tail == oldNode)
    tail = currNode;
  delete oldNode;
}

// ==================================

template <typename T>
void LinkedList<T>::deleteTail()
{
  isEmptyHelper();

  if (head == tail && head)
  {
    delete head;
    head = nullptr, tail = nullptr;
    return;
  }

  Node<T> *oldTail = tail;
  Node<T> *temp = head;

  while (temp->next != tail)
    temp = temp->next;

  tail = temp;
  tail->next = nullptr;
  delete oldTail;
}

// ==================================

template <typename T>
void LinkedList<T>::deleteFirstValue(T val)
{
  isEmptyHelper();

  if (head->data == val)
  {
    deleteHead();
    return;
  }

  Node<T> *temp = head;

  // Stops before the node with the valude so I can edit it
  while (temp->next && temp->next->data != val)
    temp = temp->next;

  if (!temp->next)
  {
    std::cerr << val << " isn't in the list.";
    return;
  }

  Node<T> *oldNode = temp->next;
  temp->next = oldNode->next;

  if (oldNode == tail)
    tail = temp;

  delete oldNode;
}

// ==================================

template <typename T>
void LinkedList<T>::deleteAllValues(T val)
{
  isEmptyHelper();

  while (head && head->data == val)
    deleteHead();

  Node<T> *temp = head;
  while (temp && temp->next)
  {
    if (temp->next->data == val)
      deleteNextNode(temp);
    else
      temp = temp->next;
  }
}

// ==================================

template <typename T>
bool LinkedList<T>::isSorted() const
{
  isEmptyHelper();

  Node<T> *temp = head;
  while (temp && temp->next)
  {
    if (temp->data <= temp->next->data)
      temp = temp->next;
    else
      return false;
  }
  return true;
}

// ==================================

template <typename T>
void LinkedList<T>::deleteDuplicatesInSortedList()
{
  isEmptyHelper();

  Node<T> *temp = head;
  while (temp && temp->next)
  {
    if (temp->data == temp->next->data)
      deleteNextNode(temp);
    else
      temp = temp->next;
  }
}

// ==================================

template <typename T>
void LinkedList<T>::reverse()
{
  isEmptyHelper();

  Node<T> *beforeNode = nullptr;
  Node<T> *currNode = head;
  Node<T> *nextNode = head->next;
  while (currNode)
  {
    currNode->next = beforeNode;
    beforeNode = currNode;
    currNode = nextNode;
    if (nextNode)
      nextNode = nextNode->next;
  }
  std::swap(head, tail);
}

// ==================================

template <typename T>
void LinkedList<T>::concatenate(const LinkedList<T> &list)
{
  if (list.isEmpty())
    return;
  Node<T> *temp = list.getHead();
  while (temp)
  {
    insertAtTail(temp->data);
    temp = temp->next;
  }
}

// ==================================

template <typename T>
void LinkedList<T>::clear()
{
  Node<T> *current = head;
  while (current != nullptr)
  {
    Node<T> *nextNode = current->next;
    delete current;
    current = nextNode;
  }
  head = tail = nullptr;
}

// ==================================

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &list)
{
  if (this == &list)
    return *this;
  clear();
  Node<T> *temp = list.getHead();
  while (temp)
  {
    this->insertAtTail(temp->data);
    temp = temp->next;
  }
  return *this;
}

// ==================================

template <typename T>
void LinkedList<T>::merge(const LinkedList<T> &list)
{
  if (isEmpty() || list.isEmpty())
    return;

  if (!isSorted() || !list.isSorted())
    throw std::invalid_argument("Both lists must be sorted");

  LinkedList<T> mergingList;
  Node<T> *temp1 = head;
  Node<T> *temp2 = list.getHead();
  while (temp1 && temp2)
  {
    if (temp1->data <= temp2->data)
    {
      mergingList.insertAtTail(temp1->data);
      temp1 = temp1->next;
    }
    else
    {
      mergingList.insertAtTail(temp2->data);
      temp2 = temp2->next;
    }
  }
  while (temp1)
  {
    mergingList.insertAtTail(temp1->data);
    temp1 = temp1->next;
  }
  while (temp2)
  {
    mergingList.insertAtTail(temp2->data);
    temp2 = temp2->next;
  }
  *this = mergingList;
}