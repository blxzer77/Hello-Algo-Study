#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue
{
private:
    int data[MAX_SIZE];
    int front;
    int rear;

public:
    // 初始化队列
    Queue() : front(-1), rear(-1) {}

    // 判断队列是否为空
    bool isEmpty() const
    {
        return front == -1;
    }

    // 判断队列是否已满
    bool isFull() const
    {
        return (rear + 1) % MAX_SIZE == front;
    }

    // 入队
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty())
            front = 0;
        rear = (rear + 1) % MAX_SIZE;
        data[rear] = value;
    }

    // 出队
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1; // 表示队列为空
        }
        int value = data[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
        return value;
    }
};
