#include <iostream>
using namespace std;

const int MAX = 100;

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
        cout << "Stack is full." << value << endl;
        return;
    }
    s.top++;
    s.data[s.top] = value;
}

void pop(Stack &s){
    if(isEmpty(s)){
        cout << "Stack is empty." << endl;
        return;
    }
    char poppedValue = s.data[s.top];
    s.top--;
}

int main (){
    Stack s;
    initStack(s);

    Stack s1;
    initStack(s1);

    cout << "Enter a word: ";
    string word;
    cin >> word;

    int idx = 0;
    while(word[idx] != '\0'){
        push(s, word[idx]);
        idx++;
    }

    cout << "Original word: " << word << endl;
    cout << "Reversed word: ";
    while(!isEmpty(s)){
        cout << (char)s.data[s.top];
        pop(s);
    }
    cout << endl;
    return 0;

}