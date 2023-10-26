#include <bits/stdc++.h>
using namespace std;

/* 冒泡排序 */
void bubbleSort(vector<int> &nums) {
    // 外循环：未排序区间为 [0, i]
    for (int i = nums.size() - 1; i > 0; i--) {
        // 内循环：将未排序区间 [0, i] 中的最大元素交换至该区间的最右端
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
    }
}

/* 冒泡排序 (标志优化) */
void bubbleSortWithFlag(vector<int> &nums) {
    // 外循环：未排序区间为 [0, i]
    for (int i = nums.size() - 1; i > 0; i--) {
        bool flag = false;  // 初始化标志位
        // 内循环：将未排序区间 [0, i] 中的最大元素交换至该区间的最右端
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                flag = true;   // 记录交换元素
            }
        }
        if (!flag)
            break;  // 此轮冒泡未交换任何元素，直接跳出
    }
}

/* 冒泡排序 (链式存储) */
// 链表节点的定义
struct Node {
    int val;
    Node *next;
};

// 冒泡排序函数
void bubbleSort(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return; // 如果链表为空或链表只有一个节点则无需排序

    bool swapped;   // 用于标记是否发生交换
    Node *current;
    Node *last = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (current->val > current->next->val) {
                // 交换相邻节点的数据
                swap(current->val, current->next->val);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}