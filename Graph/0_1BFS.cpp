void bfs0_1(int s) {
    dist[s] = 0;
    deque<int> q;
    q.push_front(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto edge : G[v]) {
            int u = edge.first;
            int w = edge.second;
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
}