vector<vector<int>> G;
vector<bool> is_removed;
vector<int> sub, par;

int get_subtree_size(int node, int parent = -1) {
    sub[node] = 1;
    for (int child : G[node]) {
        if (child == parent || is_removed[child]) { continue; }
        sub[node] += get_subtree_size(child, node);
    }
    return sub[node];
}

int get_centroid(int node, int tree_size, int parent = -1) {
    for (int child : G[node]) {
        if (child == parent || is_removed[child]) { continue; }
        if (sub[child] * 2 > tree_size) {
            return get_centroid(child, tree_size, node);
        }
    }
    return node;
}

void build_centroid_decomp(int node = 0, int parent=-1) {
    int centroid = get_centroid(node, get_subtree_size(node));
    par[centroid] = parent;
    // do something
    is_removed[centroid] = true;

    for (int child : G[centroid]) {
        if (is_removed[child]) { continue; }
        build_centroid_decomp(child, centroid);
    }
}