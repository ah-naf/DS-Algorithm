

void solve(int tc) {
    int n; cin>>n; vii v(n+1);
    for(int i=1; i<=n; i++) cin>>v[i];
    int inf = 1e9;
    vii ar(n+2, inf);
    v[0] *= -1; 
    for(int i=1; i<=n; i++) {
        int l = upper_bound(all(ar), v[i]) - ar.begin();
        if(ar[l-1] < v[i] && v[i] < ar[l]) {
            ar[l] = v[i];
        }
    }
    int ans = 0;
    for(int i=0; i<=n; i++) {
        if(ar[i] < inf) ans = i;
    }
    cout<<ans+1<<endl;
}
