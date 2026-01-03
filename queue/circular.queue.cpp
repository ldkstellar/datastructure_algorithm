
#include <iostream>

class Queue{
    public:
        Queue() = delete;
        Queue(int size);
        ~Queue();
        void enqueue(int x);
        int dequeue();
        void display();
        private:
        int size;
        int front;
        int rear;
        int *q;
};

Queue::Queue(int size):size(size),front(0),rear(0){ //인덱스 0번은 비워 둬야한다.
    q = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        q[i] = -1;
    }
    
}
Queue::~Queue(){
delete[] q;
}

void Queue::enqueue(int x){// 뒤에 하나빼고 사용한다.
if ((rear+1)%size == front)// 즉 삽입시 front와 같은 위치가 되면 꽉찬거이다.
    printf("Queueis Full.");

else{
    rear = (rear+1)%size;
    q[rear] = x;
    }
}

int Queue::dequeue(){
    int x =-1;
    if (front == rear)//같이 있는 곳이 있다는 것은 queue가 다 비어있다는 뜻이다.
    {
        printf("queue is empty");
    }
    else{
        front = (front+1)%size;//front 이동 
        x=q[front];
    }
    return x;

}

void Queue::display(){
    int i = front+1;

    do
    {
        printf("%d",q[i]);// 첫번째 출력
        i=(i+1)%size;
    } while (i!=(rear+1)%size);// 조건 충족시 돈다.
    

} 

int main(int argc, char const *argv[])
{
    Queue queue(7);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.dequeue();
    queue.display();
    return 0;
}
