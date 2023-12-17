void dijkstra(int n) {
    dist[n] = 0;
    priority_queue<pair<ll,ll>, vp, greater<pair<ll, ll>>> q;
    q.push({0, n});
    while(!q.empty()) {
        int cur_n = q.top().ss;
        int cur_dist = q.top().ff;
        q.pop();
        if(cur_dist != dist[cur_n]) continue;
        for(auto it: G[cur_n]) {
            int next_n = it.ff;
            int next_d = it.ss;
            if(dist[cur] + next_d < dist[next_n]) {
                dist[next_n] = dist[cur] + next_d;
                q.push({dist[next_n], next_n});
            }
        }
    }
}


// Complexity O(n*n*logn). O(n^3) for dense graph

for(int i=1; i<=n; i++) {
        priority_queue<pair<ll, int>> q;
        q.push({0, i});
        dist[i][i] = 0;
        while(!q.empty()) {
            int cur_n = q.top().ss;
            ll cur_dist = -q.top().ff;
            q.pop();
            if(dist[i][cur_n] < cur_dist) continue;
            for(auto it: G[cur_n]) {
                if(dist[i][cur_n] + it.ss < dist[i][it.ff]) {
                    dist[i][it.ff] = dist[i][cur_n] + it.ss;
                    q.push({-dist[i][it.ff], it.ff});
                }
            }
        }
    }