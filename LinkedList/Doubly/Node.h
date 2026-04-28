template <typename T>
class Node
{
public:
  T data;
  Node *next = nullptr;
  Node *prev = nullptr;

  Node() : data(), next(nullptr), prev(nullptr) {}
  Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};