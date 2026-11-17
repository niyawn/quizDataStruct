#include <iostream>
using namespace std; 

const int MAX = 5;

struct queue{
    int data[MAX];
    int front;
    int rear;
    int count;
};

void initQueue(queue &q){
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

bool isFull(queue &q){
    return q.count == MAX;
}

bool isEmpty(queue &q){
    return q.count == 0;
}

void enqueue(queue &q, int value){
    if(isFull(q)){
        cout << "Queue is full. Cannot enqueue " << value << endl;
        return;
    }
    q.rear = (q.rear + 1) % MAX;
    q.data[q.rear] = value;
    q.count++;
    cout << value << " enqueued to queue." << endl;
}

void dequeue(queue &q){
    if(isEmpty(q)){
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }
    int dequeuedValue = q.data[q.front];
    q.front = (q.front + 1) % MAX;
    q.count--;
    cout << dequeuedValue << " dequeued from queue." << endl;
}

void display(queue &q){
    if(isEmpty(q)){
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    for(int i = 0; i < q.count; i++){
        int index = (q.front + i) % MAX;
        cout << q.data[index] << " ";
    }
    cout << endl;
}

int main() {
    queue q;
    initQueue(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);

    dequeue(q);
    dequeue(q);
    display(q);

    enqueue(q, 60);
    enqueue(q, 70);
    display(q);

    return 0;
}