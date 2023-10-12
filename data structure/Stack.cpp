#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack
{
private:
    int data[MAX_SIZE];
    int top;

public:
    // 初始化栈
    Stack() : top(-1) {}

    // 判断栈是否为空
    bool isEmpty() const
    {
        return top == -1;
    }

    // 判断栈是否已满
    bool isFull() const
    {
        return top == MAX_SIZE - 1;
    }

    // 入栈
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
            return;
        }
        data[++top] = value;
    }

    // 出栈
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1; // 表示栈为空
        }
        return data[top--];
    }
};
