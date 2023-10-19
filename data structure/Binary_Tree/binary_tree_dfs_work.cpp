#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;            // 节点值
    TreeNode *left;     // 左子树
    TreeNode *right;    // 右子树
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 用于存储遍历的二叉树的值
vector<int> vec;

/* 前序遍历 */ 
void preOrder(TreeNode *root) {
    if (root == nullptr)
        return;
    // 访问优先级：根节点 -> 左子树 -> 右子树
    vec.push_back(root->val);   // 存储当前根节点的值
    preOrder(root->left);       // 递归处理左子树
    preOrder(root->right);      // 递归处理右子树
}

/* 中序遍历(递归实现) */
void inOrder1(TreeNode *root) {
    if (root == nullptr)
        return;
    // 访问优先级：左子树 -> 根节点 -> 右子树
    inOrder1(root->left);       // 递归处理左子树
    vec.push_back(root->val);   // 存储当前根节点的值
    inOrder1(root->right);      // 递归处理右子树
}

/* 后序遍历 */
void postOrder(TreeNode *root) {
    if (root == nullptr)
        return;
    // 访问优先级：左子树 -> 右子树 -> 根节点
    postOrder(root->left);      // 递归处理左子树
    postOrder(root->right);     // 递归处理右子树
    vec.push_back(root->val);   // 存储当前根节点的值
}

/* 中序遍历(非递归实现) */ 
void inOrder2(TreeNode *root) {
    stack<TreeNode *> stack;

    while (root != nullptr || !stack.empty()) {
        while (root != nullptr) {
            stack.push(root);
            root = root->left;
        }
        root = stack.top();
        stack.pop();
        vec.push_back(root->val);
        root = root->right;
    }
}
// 首先建立一个辅助栈，再建立一个vector容易用于存储中序遍历的二叉树的值，从根节点开始，如果root != nullptr而且栈不为空则进入以下行为：如果root != nullptr则进入以下行为：将当前节点推入栈顶，root指向它的左子树；不满足root != nullptr后退出while循环，root = 栈顶存放的节点，栈顶元素出栈，将root的值添加到vector中，root指向它的右子树。

/* 将列表反序列化为二叉树：递归 */
TreeNode *vectorToTreeDFS(vector<int> &arr, int i)
{
    if (i < 0 || i >= arr.size() || arr[i] == INT_MAX)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(arr[i]);
    root->left = vectorToTreeDFS(arr, 2 * i + 1);
    root->right = vectorToTreeDFS(arr, 2 * i + 2);
    return root;
}

/* 将列表反序列化为二叉树 */
TreeNode *vectorToTree(vector<int> arr)
{
    return vectorToTreeDFS(arr, 0);
}

/* Driver Code */
int main()
{
    TreeNode *root = vectorToTree(vector<int>{1, 2, 3, 4, 5, 6, 7});
    cout << endl << "初始化二叉树\n" << endl;

    /* 前序遍历 */
    vec.clear();
    preOrder(root);
    cout << endl << "前序遍历的节点打印序列 = ";
    for (auto &i : vec) {
        cout << i << ' ';
    }

    /* 中序遍历 */
    vec.clear();
    inOrder1(root);
    cout << endl << "递归的中序遍历的节点打印序列 = ";
    for (auto &i : vec) {
        cout << i << ' ';
    }

    vec.clear();
    inOrder2(root);
    cout << endl << "非递归的中序遍历的节点打印序列 = ";
    for (auto &i : vec) {
        cout << i << ' ';
    }

    /* 后序遍历 */
    vec.clear();
    postOrder(root);
    cout << endl << "后序遍历的节点打印序列 = ";
    for (auto &i : vec) {
        cout << i << ' ';
    }

    return 0;
}