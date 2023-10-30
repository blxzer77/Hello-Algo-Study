#include <bits/stdc++.h>
using namespace std;

#include "D:\Cpp program\.s\cpp\utils\common.hpp"

// /* 哨兵划分 */
// int partition1(vector<int> &nums, int left, int right) {
//     // 以 nums[left] 作为基准数
//     int i = left, j = right;
//     while (i < j) {
//         while (i < j && nums[j] >= nums[left])
//             j--;    // 从右向左找首个小于基准数的元素
//         while (i < j && nums[i] <= nums[left])
//             i++;    // 从左向右找首个大于基准数的元素
//         swap(nums[i], nums[j]); // 交换这两个元素
//     }
//     swap(nums[i], nums[left]);  // 将基准数交换至两子数组的分界线
//     return i;                   // 返回基准数的索引
// }

// /* 快速排序 */
// void quickSort1(vector<int> &nums, int left, int right) {
//     // 子数组长度为 1 时停止递归
//     if (left >= right)
//         return;
//     // 哨兵划分
//     int pivot = partition1(nums, left, right);
//     // 递归左子数组、右子数组
//     quickSort1(nums, left, pivot - 1);
//     quickSort1(nums, pivot + 1, right);
// }

// /* 选取三个元素的中位数 */
// int medianThree(vector<int> &nums, int left, int mid, int right) {
//     // 此处使用异或运算来简化代码
//     // 异或规则为 0 ^ 0 = 1 ^ 1 = 0, 0 ^ 1 = 1 ^ 0 = 1
//     if ((nums[left] < nums[mid]) ^ (nums[left] < nums[right]))
//         return left;
//     else if ((nums[mid] < nums[left]) ^ (nums[mid] < nums[right]))
//         return mid;
//     else 
//         return right;
// }

// /* 哨兵划分 (三数取中值) */
// int partition2(vector<int> &nums, int left, int right) {
//     // 选取三个候选元素的中位素
//     int med = medianThree(nums, left, (left + right) / 2, right);
//     // 将中位数交换之数组最左端
//     swap(nums[left], nums[med]);
//     // 以 nums[left] 作为基准数
//     int i = left, j = right;
//     while (i < j) {
//         while (i < j && nums[j] >= nums[left])
//             j--;
//         while (i < j && nums[i] <= nums[right])
//             i++;
//         swap(nums[i], nums[j]);
//     }
//     swap(nums[i], nums[left]);
//     return i;
// }

// /* 快速排序 (尾递归优化) */
// void quickSort(vector<int> &nums, int left, int right) {
//     // 子数组长度为 1 时终止
//     while (left < right) {
//         // 哨兵划分操作
//         int pivot = partition2(nums, left, right);
//         // 对两个子数组中较短的那个执行快排
//         if (pivot - left < right - pivot) {
//             quickSort(nums, left, pivot - 1);   // 递归排序左子数组
//             left = pivot + 1;                   // 剩余未排序区间为 [pivot + 1, right]
//         } else {
//             quickSort(nums, pivot + 1, right);  // 递归排序右子数组
//             right = pivot - 1;                  // 剩余未排序区间为 [left, pivot - 1]
//         }
//     }
// }

// void quickSort(vector<int> &nums, int left, int right) {
//     if (left >= right)
//         return;
//     int i = left - 1, j = right + 1;
//     int x = nums[(left + right) >> 1];
//     while (i < j) {
//         do{
//             i++;
//         } while (nums[i] < x);
//         do{
//             j--;
//         } while (nums[j] > x);
//         if (i < j)
//             swap(nums[i], nums[j]);
//     }
//     quickSort(nums, left, j);
//     quickSort(nums, j + 1, right);
// }

/* 快速排序类 */
class QuickSort
{
private:
    /* 元素交换 */
    static void swap(vector<int> &nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    /* 哨兵划分 */
    static int partition(vector<int> &nums, int left, int right)
    {
        // 以 nums[left] 作为基准数
        int i = left, j = right;
        while (i < j)
        {
            while (i < j && nums[j] >= nums[left])
                j--; // 从右向左找首个小于基准数的元素
            while (i < j && nums[i] <= nums[left])
                i++;          // 从左向右找首个大于基准数的元素
            swap(nums, i, j); // 交换这两个元素
        }
        swap(nums, i, left); // 将基准数交换至两子数组的分界线
        return i;            // 返回基准数的索引
    }

public:
    /* 快速排序 */
    static void quickSort(vector<int> &nums, int left, int right)
    {
        // 子数组长度为 1 时终止递归
        if (left >= right)
            return;
        // 哨兵划分
        int pivot = partition(nums, left, right);
        // 递归左子数组、右子数组
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }
};

/* 快速排序类（中位基准数优化） */
class QuickSortMedian
{
private:
    /* 元素交换 */
    static void swap(vector<int> &nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    /* 选取三个元素的中位数 */
    static int medianThree(vector<int> &nums, int left, int mid, int right)
    {
        // 此处使用异或运算来简化代码
        // 异或规则为 0 ^ 0 = 1 ^ 1 = 0, 0 ^ 1 = 1 ^ 0 = 1
        if ((nums[left] < nums[mid]) ^ (nums[left] < nums[right]))
            return left;
        else if ((nums[mid] < nums[left]) ^ (nums[mid] < nums[right]))
            return mid;
        else
            return right;
    }

    /* 哨兵划分（三数取中值） */
    static int partition(vector<int> &nums, int left, int right)
    {
        // 选取三个候选元素的中位数
        int med = medianThree(nums, left, (left + right) / 2, right);
        // 将中位数交换至数组最左端
        swap(nums, left, med);
        // 以 nums[left] 作为基准数
        int i = left, j = right;
        while (i < j)
        {
            while (i < j && nums[j] >= nums[left])
                j--; // 从右向左找首个小于基准数的元素
            while (i < j && nums[i] <= nums[left])
                i++;          // 从左向右找首个大于基准数的元素
            swap(nums, i, j); // 交换这两个元素
        }
        swap(nums, i, left); // 将基准数交换至两子数组的分界线
        return i;            // 返回基准数的索引
    }

public:
    /* 快速排序 */
    static void quickSort(vector<int> &nums, int left, int right)
    {
        // 子数组长度为 1 时终止递归
        if (left >= right)
            return;
        // 哨兵划分
        int pivot = partition(nums, left, right);
        // 递归左子数组、右子数组
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }
};

/* 快速排序类（尾递归优化） */
class QuickSortTailCall
{
private:
    /* 元素交换 */
    static void swap(vector<int> &nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    /* 哨兵划分 */
    static int partition(vector<int> &nums, int left, int right)
    {
        // 以 nums[left] 作为基准数
        int i = left, j = right;
        while (i < j)
        {
            while (i < j && nums[j] >= nums[left])
                j--; // 从右向左找首个小于基准数的元素
            while (i < j && nums[i] <= nums[left])
                i++;          // 从左向右找首个大于基准数的元素
            swap(nums, i, j); // 交换这两个元素
        }
        swap(nums, i, left); // 将基准数交换至两子数组的分界线
        return i;            // 返回基准数的索引
    }

public:
    /* 快速排序（尾递归优化） */
    static void quickSort(vector<int> &nums, int left, int right)
    {
        // 子数组长度为 1 时终止
        while (left < right)
        {
            // 哨兵划分操作
            int pivot = partition(nums, left, right);
            // 对两个子数组中较短的那个执行快排
            if (pivot - left < right - pivot)
            {
                quickSort(nums, left, pivot - 1); // 递归排序左子数组
                left = pivot + 1;                 // 剩余未排序区间为 [pivot + 1, right]
            }
            else
            {
                quickSort(nums, pivot + 1, right); // 递归排序右子数组
                right = pivot - 1;                 // 剩余未排序区间为 [left, pivot - 1]
            }
        }
    }
};

/* Driver Code */
int main()
{
    /* 快速排序 */
    vector<int> nums{2, 4, 1, 0, 3, 5};
    QuickSort::quickSort(nums, 0, nums.size() - 1);
    cout << "快速排序完成后 nums = ";
    printVector(nums);

    /* 快速排序（中位基准数优化） */
    vector<int> nums1 = {2, 4, 1, 0, 3, 5};
    QuickSortMedian::quickSort(nums1, 0, nums1.size() - 1);
    cout << "快速排序（中位基准数优化）完成后 nums = ";
    printVector(nums);

    /* 快速排序（尾递归优化） */
    vector<int> nums2 = {2, 4, 1, 0, 3, 5};
    QuickSortTailCall::quickSort(nums2, 0, nums2.size() - 1);
    cout << "快速排序（尾递归优化）完成后 nums = ";
    printVector(nums);

    return 0;
}