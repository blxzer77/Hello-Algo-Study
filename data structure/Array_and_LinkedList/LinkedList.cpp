#include <iostream>
using namespace std;

struct Node
{
    int data;   // 数据域
    Node *next; // 指针域

    Node(int d, Node *n = nullptr) : data(d), next(n) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    // 插入数据到链表的指定位置，如果位置超出链表长度，则插入到末尾
    void insert(int pos, int value)
    {
        Node *newNode = new Node(value);
        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *current = head;
        for (int i = 0; i < pos - 1 && current; i++)
        {
            current = current->next;
        }
        if (current)
        {
            newNode->next = current->next;
            current->next = newNode;
        }
        else
        {
            current = head;
            while (current && current->next)
            {
                current = current->next;
            }
            if (current)
            {
                current->next = newNode;
            }
            else
            {
                head = newNode;
            }
        }
    }

    // 根据数据值删除节点
    void remove(int value)
    {
        if (!head)
            return;
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *current = head;
        while (current->next && current->next->data != value)
        {
            current = current->next;
        }
        if (current->next)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // 显示链表的内容
    void display()
    {
        Node *current = head;
        while (current)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{
    LinkedList list;

    // 以下是对链表的操作示例
    list.insert(0, 10); // 在位置0插入10
    list.insert(1, 20); // 在位置1插入20
    list.insert(2, 30); // 在位置2插入30
    list.insert(1, 15); // 在位置1插入15
    list.display();     // 显示: 10 -> 15 -> 20 -> 30 -> nullptr

    list.remove(20);
    list.display(); // 显示: 10 -> 15 -> 30 -> nullptr

    return 0;
}
