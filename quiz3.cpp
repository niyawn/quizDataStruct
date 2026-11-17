#include <iostream>
using namespace std;   

const int MAX = 5;

struct queue{
    int data[MAX];
    int front;
    int rear;
};

void initQueue(queue &q){
    q.front = -1;
    q.rear = -1;
}

bool isFull(queue &q){
    return q.rear == MAX - 1;
}

bool isEmpty(queue &q){
    return q.front == -1 || q.front > q.rear;
}

void enqueue(queue &q, int value){
    if(isFull(q)){
        cout << "Queue is full. Cannot enqueue " << value << endl;
        return;
    }
    if(isEmpty(q)){
        q.front = 0;
    }
    q.rear++;
    q.data[q.rear] = value;
    cout << value << " enqueued to queue." << endl;
}

void dequeue(queue &q){
    if(isEmpty(q)){
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }
    int dequeuedValue = q.data[q.front];
    q.front++;
    cout << dequeuedValue << " dequeued from queue." << endl;
}

void front(queue &q){
    if(isEmpty(q)){
        cout << "Queue is empty. Cannot access front." << endl;
        return;
    }
    cout << "Front element is: " << q.data[q.front] << endl;
}

void display(queue &q){
    if(isEmpty(q)){
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    for(int i = q.front; i <= q.rear; i++){
        cout << q.data[i] << " ";
    }
    cout << endl;
}

int main(){
    queue q;
    initQueue(q);

    int choice = 0;
    int value = 0;
    while (true){
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice){
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                front(q);
                break;
            case 4:
                display(q);
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    }
}