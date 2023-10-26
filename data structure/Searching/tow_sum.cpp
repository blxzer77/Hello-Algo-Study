#include <bits/stdc++.h>
using namespace std;

/* 方法一：暴力枚举 */
vector<int> towSumBruteForce(vector<int> &nums, int target) {
    int size = nums.size();
    // 两层循环，时间复杂度 O(n^2)
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
}

/* 方法二：辅助哈希表 */
vector<int> twoSumHashTable(vector<int> &nums, int target) {
    int size = nums.size();
    // 辅助哈希表，空间复杂度 O(n)
    unordered_map<int, int> dic;
    // 单层循环，时间复杂度O()
    for (int i = 0; i < size; i++) {
        if (dic.find(target - nums[i]) != dic.end()) {
            return {dic[target - nums[i], i]};
        }
        dic.emplace(nums[i], i);
    }
    return {};
}