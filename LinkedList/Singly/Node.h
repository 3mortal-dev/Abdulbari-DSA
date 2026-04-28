template <typename T>
class Node
{
public:
  T data;
  Node *next = nullptr;

  Node() : data(), next(nullptr) {}
  Node(T val) : data(val), next(nullptr) {}
};