#include "D:\Cpp program\.s\cpp\utils\common.hpp"
#include "D:\Cpp program\.s\data structure\Graph\graph_adjacency_list.cpp"

/* 广度优先遍历 BFS */
// 使用邻接表来表示图，以便获取指定顶点的所有邻接顶点
vector<Vertex *> graphBFS(GraphAdjList &graph, Vertex *startVet) {
    // 顶点遍历序列
    vector<Vertex *> res;
    // 哈希表，用于记录已被访问过的节点
    unordered_set<Vertex *> visited = {startVet};
    // 队列用于实现 BFS
    queue<Vertex *> que;
    que.push(startVet);     // 队尾入队 队首出队
    // 以顶点 vet 为起点，循环直至访问完所有顶点
    while (!que.empty()) {
        Vertex *vet = que.front();
        que.pop();          // 队首顶点出队
        res.push_back(vet); // 记录访问顶点
        // 遍历该顶点的所有邻接顶点
        for (auto adjVet : graph.adjList[vet]) {
            if (visited.count(adjVet))
                continue;               // 跳过已被访问过的顶点
            que.push(adjVet);           // 只入队未访问的顶点
            visited.emplace(adjVet);    // 标记该顶点已被访问
        }
    }
    // 返回顶点遍历序列
    return res;
}