struct Node {
  Node * next;
  int data;
};


int Length(Node *head)
{
  int length = 0;
  while (head != nullptr) {
    length++;
    head = head->next;
  }
  return length;
}

int Count(Node *head, int data)
{
  int count = 0;
  while (head != nullptr) {
    if (head->data == data)
      count++;
    head = head->next;
  }
  return count;
}