#include <iostream>

class Queue {

public:
  Queue(int size);
  void enqueue(int x);
  void dequeue();

private:
  int front;
  int rear;
  int size;
  int *p;
};

Queue::Queue(int size) { p = new int[size]; }

void Queue::enqueue(int x) {
  if (rear == size - 1) {
    printf("queue is full");
  } else {
    p[rear++] = x;
  }
}

void Queue::dequeue() {
  if (front == rear) {
    printf("queue is empty.");
  } else {
    p[front--] = -1;
  }
}
