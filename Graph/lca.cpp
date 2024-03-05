const int LOG = 20;
vii G[N], depth(N, 0);
int up[N][LOG];

void dfs(int a) {
    for(auto it: G[a]) {
        depth[it] = 1 + depth[a];

        // Binary Lifting
        up[it][0] = a;
        for(int j=1; j<LOG; j++) {
            up[it][j] = up[ up[it][j-1] ][j-1];
        }
        
        dfs(it);
    }
}

int get_lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    for(int j=LOG-1; j>=0; j--) {
        if(checkbit(k, j)) a = up[a][j];
    }
    if(a == b) return a;

    for(int j=LOG-1; j>=0; j--) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}
