#include <bits/stdc++.h>
using namespace std;
#include "D:\Cpp program\.s\data structure\Searching\binary_search_insertion.cpp"

/* 二分查找最左一个 target */
int binarySearchLeftEdge(vector<int> &nums, int target) {
    // 等价于查找 target 的插入点
    int i = binarySearchInsertion(nums, target);
    // 未找到 target ， 返回 -1
    if (i == nums.size() || nums[i] != target)
        return -1;
    // 找到 target , 返回索引 i
    return i;
}

/* 二分查找最右一个 target */
int binarySearchRightEdge(vector<int> &nums, int target) {
    // 转化为查找最左一个 target + 1;
    int i = binarySearchInsertion(nums, target + 1);
    // j 指向最右一个 target, i 指向首个大于 target 的元素
    int j = i - 1;
    // 未找到 target, 返回 -1
    if (j == -1 || nums[j] != target)
        return -1;
    // 找到 target， 返回索引 j
    return j; 
}
