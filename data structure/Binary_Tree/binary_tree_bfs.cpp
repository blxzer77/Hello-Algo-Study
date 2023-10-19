#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> levelOrder(TreeNode *root)
{
    // 初始化队列，加入根节点
    queue<TreeNode* > queue;
    queue.push(root);
    // 初始化一个列表，用于保存遍历序列
    vector<int> vec;
    while (!queue.empty())
    {
        TreeNode *node = queue.front();
        queue.pop();              // 队列出队
        vec.push_back(node->val); // 保存节点值
        if (node->left != nullptr)
            queue.push(node->left); // 左子节点入队
        if (node->right != nullptr)
            queue.push(node->right); // 右子节点入队
    }
    return vec;
}

int main()
{
    // 创建二叉树
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    root->left = n1;
    root->right = n2;
    n1->left = nullptr;
    n1->right = nullptr;
    n2->left = nullptr;
    n2->right = nullptr;

    // 层序遍历
    vector<int> vec = levelOrder(root);

    // 输出遍历结果
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}