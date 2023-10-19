#include <iostream>
#include <string>
using namespace std;

/* 链表节点结构体 */
struct ListNode
{
    int val;                                   // 节点值
    ListNode *next;                            // 指向下一节点的指针
    ListNode(int x) : val(x), next(nullptr) {} // 构造函数
};

/* 在链表的节点 n0 之后插入节点 P */
void insert(ListNode *n0, ListNode *P)
{
    ListNode *n1 = n0->next;
    P->next = n1;
    n0->next = P;
}

/* 删除链表的节点 n0 之后的首个节点 */
void remove(ListNode *n0)
{
    if (n0->next == nullptr)
        return;
    // n0 -> P -> n1
    ListNode *P = n0->next;
    ListNode *n1 = P->next;
    n0->next = n1;
    // 释放内存
    delete P;
}

/* 访问链表中索引为 index 的节点 */
ListNode *access(ListNode *head, int index)
{
    for (int i = 0; i < index; i++)
    {
        if (head == nullptr)
            return nullptr;
        head = head->next;
    }
    return head;
}

/* 在链表中查找值为 target 的首个节点 */
int find(ListNode *head, int target)
{
    int index = 0;
    while (head != nullptr)
    {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

void printLinkedList(ListNode *head)
{
    ListNode *current = head; // 从链表头节点开始遍历

    while (current != nullptr)
    {
        cout << current->val; // 打印当前节点的值
        if (current->next != nullptr)
        {
            cout << " "; // 在节点值之间添加空格
        }
        current = current->next; // 移动到下一个节点
    }

    cout << endl; // 打印换行符表示链表结束
}

int main()
{
    /* 初始化链表 1 -> 3 -> 2 -> 5 -> 4 */
    // 初始化各个节点
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(5);
    ListNode *n4 = new ListNode(4);
    // 构建引用指向
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    cout << "初始化的链表为" << endl;
    printLinkedList(n0);

    /* 插入节点 */
    insert(n0, new ListNode(0));
    cout << "插入节点后的链表为" << endl;
    printLinkedList(n0);

    /* 删除节点 */
    remove(n0);
    cout << "删除节点后的链表为" << endl;
    printLinkedList(n0);

    /* 访问节点 */
    ListNode *node = access(n0, 3);
    cout << "链表中索引 3 处的节点的值 = " << node->val << endl;

    /* 查找节点 */
    int index = find(n0, 2);
    cout << "链表中值为 2 的节点的索引 = " << index << endl;

    // 释放内存
    delete (n0);

    return 0;
}