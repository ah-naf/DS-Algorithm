#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

struct edge {
    int to;
    int cap;
    int rev;
};

class Dinic {
private:
    int INF;
    std::vector<edge> G[100000];
    int level[100000];
    int iter[100000];
public:
    Dinic();
    void add_edge(int from, int to, int cap);
    void bfs(int s);
    int dfs(int v, int t, int f);
    int maximum_flow(int s, int t);
};

Dinic::Dinic() {
    INF = 0x7fffffff;
    std::fill(level, level + 100000, 0);
    std::fill(iter, iter + 100000, 0);
}

void Dinic::add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
}
void Dinic::bfs(int s) {
    std::memset(level, -1, sizeof(level));
    std::queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < (int)G[v].size(); i++)
        {
            edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0)
            {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
}
int Dinic::dfs(int src, int sink, int f) {
    if (src == sink)
        return f;
    for (int &i = iter[src]; i < (int)G[src].size(); i++)
    {
        edge &e = G[src][i];
        if (e.cap > 0 && level[src] < level[e.to])
        {
            int d = dfs(e.to, sink, std::min(f, e.cap));
            if (d > 0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int Dinic::maximum_flow(int src, int sink) {
    int flow = 0;
    for (;;)
    {
        bfs(src);
        if (level[sink] < 0)
            return flow;
        std::memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(src, sink, INF)) > 0)
            flow += f;
    }
}