#include <iostream>
using namespace std;

#define MAXSIZE 100

class SeqList
{
private:
    int data[MAXSIZE];
    int length;

public:
    SeqList() : length(0) {} // 构造函数初始化长度为0

    // 插入数据到顺序表的指定位置
    void insert(int pos, int value)
    {
        if (length == MAXSIZE || pos < 0 || pos > length)
        {
            cout << "插入位置不合法或顺序表已满!" << endl;
            return;
        }
        for (int i = length; i > pos; i--)
        {
            data[i] = data[i - 1];
        }
        data[pos] = value;
        length++;
    }

    // 从顺序表的指定位置删除数据
    void remove(int pos)
    {
        if (pos < 0 || pos >= length)
        {
            cout << "删除位置不合法!" << endl;
            return;
        }
        for (int i = pos; i < length - 1; i++)
        {
            data[i] = data[i + 1];
        }
        length--;
    }

    // 显示顺序表的内容
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    SeqList list;

    // 以下是对顺序表的操作示例
    list.insert(0, 10); // 在位置0插入10
    list.insert(1, 20); // 在位置1插入20
    list.insert(2, 30); // 在位置2插入30
    list.display();     // 显示: 10 20 30

    list.remove(1); // 删除位置1的数据
    list.display(); // 显示: 10 30

    return 0;
}
