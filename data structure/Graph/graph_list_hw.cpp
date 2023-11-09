#include <bits/stdc++.h>
using namespace std;

/* 顶点类 */
struct Vertex
{
    int val;
    int index;    // 顶点的邻接顶点索引位置
    bool visited; // 顶点是否被访问过
    Vertex(int x) : val(x), index(0), visited(false) {}
};

/* 基于邻接表实现的无向图类 */
class GraphAdjList
{
public:
    // 邻接表，key: 顶点， value: 该顶点的所有邻接顶点
    unordered_map<Vertex *, vector<Vertex *>> adjList;

    /* 构造方法 */
    GraphAdjList(const vector<vector<Vertex *>> &edges)
    {
        // 添加所有顶点和边
        for (const vector<Vertex *> &edge : edges)
        {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0], edge[1]);
        }
    }

    /* 获取顶点数量 */
    int size()
    {
        return adjList.size();
    }

    /* 获取顶点的第一个邻接顶点 */
    Vertex *FirstAdjVex(Vertex *vet)
    {
        if (!adjList.count(vet))
            throw invalid_argument("不存在顶点");
        vet->index = 0; // 初始化邻接顶点索引位置
        if (adjList[vet].empty())
            return nullptr;
        return adjList[vet][0];
    }

    /* 获取顶点的下一个邻接顶点 */
    Vertex *NextAdjVex(Vertex *vet)
    {
        Vertex *adjVex = FirstAdjVex(vet);
        if (!adjList.count(vet) || !adjList.count(adjVex))
            throw invalid_argument("不存在顶点");
        vet->index++; // 增加邻接顶点索引位置
        if (vet->index >= adjList[vet].size())
            return nullptr;
        return adjList[vet][vet->index];
    }

    /* 添加顶点 */
    void addVertex(Vertex *vet)
    {
        if (adjList.count(vet))
            return;
        adjList[vet] = vector<Vertex *>();
    }

    /* 在 vector 中删除指定节点 */
    void remove(vector<Vertex *> &vec, Vertex *vet)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == vet)
            {
                vec.erase(vec.begin() + i);
                break;
            }
        }
    }

    /* 删除顶点*/
    void removeVertex(Vertex *vet)
    {
        if (!adjList.count(vet))
            throw invalid_argument("不存在顶点");
        // 在邻接表中删除顶点 vet 对应的链表
        adjList.erase(vet);
        // 遍历其他顶点的链表，删除所有包含 vet 的边
        for (auto &adj : adjList)
            remove(adj.second, vet);
    }

    /* 添加边 */
    void addEdge(Vertex *vet1, Vertex *vet2)
    {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw invalid_argument("不存在顶点");
        // 添加边 vet1 - vet2
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }

    /* 删除边 */
    void removeEdge(Vertex *vet1, Vertex *vet2)
    {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw invalid_argument("不存在顶点");
        // 删除边 vet1 - vet2
        remove(adjList[vet1], vet2);
        remove(adjList[vet2], vet1);
    }

    /* 广度优先遍历 */
    void BFS(Vertex *start)
    {
        if (!adjList.count(start))
            throw invalid_argument("不存在顶点");

        queue<Vertex *> q;
        start->visited = true;
        q.push(start);

        while (!q.empty())
        {
            Vertex *cur = q.front();
            q.pop();
            cout << cur->val << " ";

            for (Vertex *adj : adjList[cur])
            {
                if (!adj->visited)
                {
                    adj->visited = true;
                    q.push(adj);
                }
            }
        }
    }

    /* 深度优先遍历 DFS 辅助函数 */
    void dfs(unordered_set<Vertex *> &Visited, vector<Vertex *> &res, Vertex *vet)
    {
        res.push_back(vet);   // 记录访问顶点
        Visited.emplace(vet); // 标记该顶点已被访问
        // 遍历该顶点的所有邻接顶点
        for (Vertex *adjVet : adjList[vet])
        {
            if (Visited.count(adjVet))
                continue; // 跳过已被访问过的顶点
            // 递归访问邻接顶点
            dfs(Visited, res, adjVet);
        }
    }

    /* 深度优先遍历 DFS */
    // 使用邻接表来表示图，以便获取指定顶点的所有邻接顶点
    vector<Vertex *> DFS(Vertex *startVet)
    {
        // 顶点遍历序列
        vector<Vertex *> res;
        // 哈希表，用于记录已被访问过的顶点
        unordered_set<Vertex *> Visited;
        dfs(Visited, res, startVet);
        return res;
    }

    /* 打印邻接表 */
    void print() {
        cout << "邻接表 =" << endl;
        for (auto &adj : adjList)
        {
            const auto &key = adj.first;
            const auto &vec = adj.second;
            cout << key->val << " : ";
            
            for (const auto &vertex : vec)
                cout << vertex->val << " ";

            cout << endl;
        }
    }
};

/* 输入值列表 vals, 返回顶点列表vets */
vector<Vertex *> valsToVets(vector<int> vals)
{
    vector<Vertex *> vets;
    for (int val : vals)
    {
        vets.push_back(new Vertex(val));
    }
    return vets;
}

/* Driver Code */
int main() 
{
    /* 初始化无向图 */
    vector<Vertex *> v = valsToVets(vector<int>{1, 2, 3, 4, 5});
    vector<vector<Vertex *>> edges = {{v[0], v[1]}, {v[0], v[3]}, {v[1], v[2]}, {v[1], v[4]}, {v[2], v[3]}, {v[2], v[4]}};

    GraphAdjList graph(edges);
    cout << "\n初始化后，图为" << endl;
    graph.print();
    
    /* 获取v1即v[0]的第一个邻接顶点 */
    cout << "v1的第一个邻接顶点是: ";
    Vertex *F = graph.FirstAdjVex(v[0]);
    cout << F->val << endl;

    /* 获取v1即v[0]的下一个邻接顶点 */
    cout << "v1的下一个邻接顶点是: ";
    Vertex *N = graph.NextAdjVex(v[0]);
    cout << N->val << endl;

    /* 添加边 */
    // 顶点v1，v3 即 v[0], v[2]
    graph.addEdge(v[0], v[2]);
    cout << "\n添加边v1-v3后，图为" << endl;
    graph.print();

    /* 删除边 */
    // 顶点v1，v3 即 v[0], v[2]
    graph.removeEdge(v[0], v[2]);
    cout << "\n删除边v1-v3后，图为" << endl;
    graph.print();

    /* 添加顶点 */
    Vertex *v5 = new Vertex(6);
    graph.addVertex(v5);
    cout << "\n添加顶点v6后，图为" << endl;
    graph.print();

    /* 基于邻接表实现的图的遍历 */
    // BFS
    cout << endl << "BFS" << endl;
    graph.BFS(v[0]);
    // DFS
    cout << endl << "DFS" << endl;
    vector<Vertex *> res = graph.DFS(v[0]);
    for (Vertex *r : res) {
        cout << r->val << " ";
    }

    /* 删除顶点 */
    // 顶点v3 即v[2]
    graph.removeVertex(v[2]);
    cout << "\n删除顶点 v3 后, 图为" << endl;
    graph.print();

    /* 释放内存 */
    for (Vertex *vet : v) {
        delete vet;
    }
    
    return 0;
}