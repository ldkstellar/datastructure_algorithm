#include <iostream>

struct Queue {
  int size;
  int front;
  int rear;
  int *Q;
};

void enqueue(Queue *q, int x) {
  if (q->rear == q->size - 1) {
    printf("queue is full.\n");
  } else {
    q->Q[q->rear] = x;
    q->rear++;
  }
}

void dequeue(Queue *q) {
  if (q->rear == q->front) {
    printf("queue is empty.");
  } else {
    q->Q[q->rear] = -1;
    q->rear--;
  }
}

int main(int argc, char const *argv[]) {
  Queue queue = {7, -1, -1};
  queue.Q = new int[7];

  return 0;
}
