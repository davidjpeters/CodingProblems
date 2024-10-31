#include <iostream>
#include <string>
#include <cctype>
#include <vector>

class Node {
  public:
    int data;
    Node *next;
    Node(int data, Node *next = nullptr): data(data), next(next) {}
};

Node *parse(const std::string& s) {
  
  if (s.length() == 0) {
    return nullptr;
  }
  
  std::vector<std::string> elements;
  
  for (size_t i = 0; i < s.length(); ++i) {
    if (std::isdigit(s[i])) {
      int j = i;
      while (std::isdigit(s[j])) {
        j++;
      }
      elements.push_back(s.substr(i, j - i));
      i = j;
    }
  }
  
  if (elements.empty()) 
    return nullptr;
  
  Node* head = new Node(std::stoi(elements[0]), nullptr);
  Node* copy = head;

  for (size_t i = 1; i < elements.size(); ++i) {

    head->next = new Node(std::stoi(elements[i]), nullptr);
    head = head->next;
  }
  
  return copy;
}