vp G[N];
vll dist(N, 1e15);
vector<bool> vis(N);

void dijkstra(int n) {
    dist[n] = 0;
    priority_queue<pair<ll,ll>, vp, greater<pair<ll, ll>>> q;
    q.push({0, n});
    while(!q.empty()) {
        ll cur_n = q.top().ss;
        ll cur_dist = q.top().ff;
        q.pop();
        if(vis[cur_n]) continue;
        vis[cur_n] = true;

        for(auto it: G[cur_n]) {
            if(cur_dist + it.ss < dist[it.ff]) {
                dist[it.ff] = cur_dist + it.ss;
                q.push({dist[it.ff], it.ff});
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