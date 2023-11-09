#include <bits/stdc++.h>
using namespace std;

/* 基于邻接矩阵实现的无向图类 */
class GraphAdjMat
{
    vector<int> vertices;       // 顶点列表，元素代表顶点值，索引代表顶点索引
    vector<vector<int>> adjMat; // 邻接矩阵，行列索引对应顶点索引

public:
    /* 构造方法 */
    GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges)
    {
        // 添加顶点
        for (int val : vertices)
            addVertex(val);
        // 添加边
        // edges 元素代表顶点索引，即对应 vertices 元素索引
        for (const vector<int> &edge : edges)
            addEdge(edge[0], edge[1]);
    }

    /* 获取顶点数量 */
    int size() const
    {
        return vertices.size();
    }

    /* 获取顶点的第一个邻接顶点 */
    int FirstAdjVex(int index)
    {
        if (index < 0 || index >= size())
            throw out_of_range("顶点不存在");

        for (int i = 0; i < size(); i++)
        {
            if (adjMat[index][i] == 1)
                return i;
        }

        return -1; // 顶点没有邻接顶点
    }

    /* 获取顶点的下一个邻接顶点 */
    int NextAdjVex(int index)
    {
        int prevAdjVex = FirstAdjVex(index);
        if (prevAdjVex == -1)
            return -1;
        if (index < 0 || index >= size())
            throw out_of_range("顶点不存在");

        for (int i = prevAdjVex + 1; i < size(); i++)
        {
            if (adjMat[index][i] == 1)
                return i;
        }

        return -1;
    }

    /* 添加顶点 */
    void addVertex(int val)
    {
        int n = size();
        // 向顶点列表中添加新顶点的值
        vertices.push_back(val);
        // 在邻接矩阵中添加一行
        adjMat.emplace_back(vector<int>(n, 0));
        // 在邻接矩阵中添加一列
        for (vector<int> &row : adjMat)
            row.push_back(0);
    }

    /* 删除顶点 */
    void removeVertex(int index)
    {
        if (index >= size())
            throw out_of_range("顶点不存在");
        // 在顶点列表中移除索引 index 的顶点
        vertices.erase(vertices.begin() + index);
        // 在邻接矩阵中删除索引 index 的行
        adjMat.erase(adjMat.begin() + index);
        // 在邻接矩阵中删除索引 index 的列
        for (vector<int> &row : adjMat)
            row.erase(row.begin() + index);
    }

    /* 添加边 */
    // 参数 i, j 对应 vertices 元素索引
    void addEdge(int i, int j)
    {
        // 索引越界与相等处理
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j)
            throw out_of_range("顶点不存在");
        // 在无向图中，邻接矩阵沿对角线对称，即满足 (i, j) == (j, i)
        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }

    /* 删除边 */
    void removeEdge(int i, int j)
    {
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j)
            throw out_of_range("顶点不存在");
        adjMat[i][j] = 0;
        adjMat[j][i] = 0;
    }

    /* 深度优先搜索 */
    void DFS(int start)
    {
        vector<bool> visited(size(), false); // 记录顶点是否被访问过
        stack<int> s;                        // 辅助栈

        // 将起始顶点入栈
        s.push(start);
        visited[start] = true;

        while (!s.empty())
        {
            int curr = s.top();
            s.pop();
            cout << vertices[curr] << " ";

            // 遍历当前顶点的邻接顶点
            for (int i = 0; i < size(); i++)
            {
                if (adjMat[curr][i] == 1 && !visited[i])
                {
                    s.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    /* 广度优先搜索 */
    void BFS(int start)
    {
        vector<bool> visited(size(), false);
        queue<int> q; // 使用队列来辅助实现 BFS

        // 将起始顶点入队
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << vertices[curr] << " ";

            // 遍历当前顶点的邻接顶点
            for (int i = 0; i < size(); i++)
            {
                if (adjMat[curr][i] == 1 && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    /* 打印邻接矩阵 */
    void print()
    {
        cout << "顶点列表 = " << endl;
        for (auto v : vertices)
            cout << v << " ";
        cout << endl;

        cout << "邻接矩阵 = " << endl;

        for (int i = 0; i < size(); i++)
        {
            for (int j = 0; j < size(); j++)
            {
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

/* Driver Code */
int main()
{
    /* 初始化无向图 */
    // edges 元素代表顶点索引，即对应 vertices 元素索引
    vector<int> vertices = {1, 2, 3, 4, 5};
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {1, 4}, {2, 3}, {2, 4}};
    GraphAdjMat graph(vertices, edges);
    cout << "\n初始化后，图为:" << endl;
    graph.print();

    /* 获取顶点v1的第一个邻接顶点 */
    cout << "v1的第一个邻接顶点是: ";
    int F = vertices[graph.FirstAdjVex(0)];
    cout << F << endl;

    /* 获取顶点v1的下一个邻接顶点 */
    cout << "v1的下一个邻接顶点是: ";
    int N = vertices[graph.NextAdjVex(0)];
    cout << N << endl;
    
    /* 添加边 */
    // 顶点v1, v3
    graph.addEdge(0, 2);
    cout << "\n添加边 v1-v3 后，图为" << endl;
    graph.print();

    /* 基于邻接表实现的图的遍历 */
    // BFS
    cout << endl << "BFS" << endl;
    graph.BFS(0);
    // DFS
    cout << endl << "DFS" << endl;
    graph.DFS(0);
    cout << endl;

    /* 删除边 */
    // 顶点v1, v2
    graph.removeEdge(0, 1);
    cout << "\n删除边 v1-v2 后，图为" << endl;
    graph.print();

    /* 添加顶点 */
    // 添加顶点v6
    graph.addVertex(6);
    cout << "\n添加顶点 v6 后，图为" << endl;
    graph.print();

    /* 删除顶点 */
    // 删除顶点v3
    graph.removeVertex(2);
    cout << "\n删除顶点 v3 后，图为" << endl;
    graph.print();

    return 0;
}