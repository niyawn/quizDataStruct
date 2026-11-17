#include <iostream>
using namespace std;

const int MAX = 5;

struct Stack{
    int data[MAX];
    int top;
};

void initStack(Stack &s){
    s.top = -1;
}

bool isFull(Stack &s){
    return s.top == MAX - 1;
}

bool isEmpty(Stack &s){
    return s.top == -1;
}

void push(Stack &s, int value){
    if(isFull(s)){
        cout << "Stack is full. Cannot push " << value << endl;
        return;
    }
    s.top++;
    s.data[s.top] = value;
    cout << value << " pushed to stack." << endl;
}

void pop(Stack &s){
    if(isEmpty(s)){
        cout << "Stack is empty. Cannot pop." << endl;
        return;
    }
    int poppedValue = s.data[s.top];
    s.top--;
    cout << poppedValue << " popped from stack." << endl;
}

void peek(Stack &s){
    if(isEmpty(s)){
        cout << "Stack is empty. Cannot peek." << endl;
        return;
    }
    cout << "Top element is: " << s.data[s.top] << endl;
}

void display(Stack &s){
    if(isEmpty(s)){
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements: ";
    for(int i = s.top; i >= 0; i--){
        cout << s.data[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack s;
    initStack(s);

    int choice = 0;
    int value = 0;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(s, value);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                peek(s);
                break;
            case 4:
                display(s);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

}