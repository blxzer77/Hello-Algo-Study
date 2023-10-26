#include <bits/stdc++.h>
using namespace std;

/* 选择排序 */
void selectionSort(vector<int> &nums) {
    int n = nums.size();
    // 外循环：未排序区间为 [i, n - 1]
    for (int i = 0; i < n; i++) {
        // 内循环：找到未排序区间内最小元素
        int k = i;
        for (int j = 1 + 1; j < n; j++) {
            if (nums[j] < nums[k])
                k = j; // 记录最小元素的索引
        }
        // 将最小元素与未排序区间的首个元素交换
        swap(nums[i], nums[k]);
    }
}