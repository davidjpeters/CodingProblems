class Node
{
  public:
    int data;
    Node* next;
  
  Node(int data, Node* next = nullptr)
  {
    this->data = data;
    this->next = next;
  }
};

#include <string>

std::string stringify(Node* list) {
  
  std::string ans = "";
  
  while (list != nullptr) {
    ans += std::to_string(list->data) + " -> ";
    list = list->next;
  }
  ans += "nullptr";
  
  return ans;
}