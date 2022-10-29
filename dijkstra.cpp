void dijkstra(int n) {
    dist[n] = 0;
    priority_queue<pair<ll,ll>, vp, greater<pair<ll, ll>>> q;
    q.push({0, n});
    while(!q.empty()) {
        int cur = q.top().ss;
        int cur_dist = q.top().ff;
        q.pop();
        if(cur_dist != dist[cur]) continue;
        for(auto it: G[cur]) {
            int to = it.ff;
            int len = it.ss;
            if(dist[cur] + len < dist[to]) {
                dist[to] = dist[cur] + len;
                q.push({dist[to], to});
            }
        }
    }
}
