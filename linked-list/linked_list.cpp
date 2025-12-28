#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
};
Node *create(int A[], int size) {
  Node *head = new Node; // 새 노드생성

  Node *temp;
  Node *last;

  head->data = A[0]; // 배열에  첫번째 값 삽입
  head->next = nullptr;
  last = head; // 초기엔는 마지막이 head이다

  // Create a Linked List
  for (int i = 1; i < size; i++) {

    temp = new Node;

    temp->data = A[i];
    temp->next = nullptr;

    last->next = temp; // head로 숨기고 있어 last
    last = temp;       // head 이제 last가 아니야
  }

  // Display Linked List
  Node *p = head;

  return p;
}

void remove(Node *p) {
  Node *node = p;
  while (node->next != nullptr) {
    Node *temp = node->next;
    delete node;
    node = temp;
  }
}

int main() {

  int A[] = {3, 5, 7, 10, 15};

  Node *p = create(A, 5);

  while (p != nullptr) {
    cout << p->data << " -> " << flush;
    p = p->next;
  }

  remove(p);

  return 0;
}