#include <stack>
#include <iostream>
using namespace std;
void DFS(Graph G, int v, bool visited[], stack<int> &reversepost) {
    visited[v] = true;
    int w = GetFistNeighbor(G, v);
    while (w != -1) {
        if (!visited[w]) DFS(G, w, visited, reversepost);
        w = GetNextNeighbor(G, v, w);
    }
    reversepost.push(v);
    //在即将退出dfs方法的时候，将当前顶点添加到结果集中
}
void DFS_Order(Graph G) {
    stack<int> reversepost;//使用栈来保存最后的结果 
    bool *visited = new bool[G.vertices_num];
    for (int i = 0; i < G.n; ++i) visited[i] = false;
    for (int i = 0; i < G.n; ++i) {
        if (!visited[i]) {
            DFS(G, i, visited, reversepost);
        }
    }
    if (!reversepost.empty()) {
        cout << reversepost.top();
        reversepost.pop();
        if (!reversepost.empty()) cout << "->";
        else cout << endl;
    }
};