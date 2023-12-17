const int N = 100005;

struct segtree {
  int t[4 * N];
  static const int inf = 1e9;
  segtree() {
    memset(t, 0, sizeof t);
  }
  void build(int n, int b, int e, vll &a) {
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    build(l, b, mid, a);
    build(r, mid + 1, e, a);
    t[n] = max(t[l], t[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      t[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    t[n] = max(t[l], t[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return -inf;
    if (b >= i && e <= j) return t[n];
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
};

void solve(int tc) {
    int n,q; cin>>n>>q; vll v(n+1);
    for(int i=1; i<=n; i++) cin>>v[i];
    segtree st; st.build(1, 1, n, v);
    for(int i=1; i<=n; i++) {
        cout<<st.query(1, 1, n, i ,n)<<" ";
    }
}