#include <bits/stdc++.h>
using namespace std;

/* 插入排序 */
void insertionSort(vector<int> &nums) {
    // 外循环：以及排序元素数量为 1, 2, 3, ······ , n
    for (int i = 1; i < nums.size(); i++) {
        int base = nums[i], j = i - 1;
        // 内循环：将 base 插入到已排序部分的正确位置
        while (j >= 0 && nums[j] > base) {
            nums[j + 1] = nums[j];  // 将 nums[j] 向右移动一位
            j--;
        }
        nums[j + 1] = base; // 将 base 赋值到正确位置
    }
}