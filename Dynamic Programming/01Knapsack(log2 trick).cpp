int N, M;
vll vol, profit;

ll dp[2][5005];

void solve(int tc) {
    cin>>N>>M;
    vol.pb(0); profit.pb(0);
    for(int i=0; i<N; i++) {
        ll n, v, p; cin>>n>>v>>p;
        ll now = 1, cntSum = 0;
        while(cntSum + now <= n) {
            // if(v * now > 5000) break;
            vol.pb(v * now);
            profit.pb(p * now);
            cntSum += now; now *= 2;
        }
        if(n - cntSum >= 0) {
            vol.pb(v * (n - cntSum));
            profit.pb(p * (n - cntSum));
        }
    }
    // memset(dp, 0, sizeof(dp));
    for(int i=0; i<=1; i++) {
        for(int j=0; j<=5002; j++) dp[i][j] = LLONG_MIN;
    }
    int sz = vol.size() - 1;
    for(int i=0; i<=5002; i++) dp[(sz+1)&1][i] = 0;
    for(int i=sz; i>=1; i--) {
        for(int j=0; j<=5002; j++) {
            if(j - vol[i] >= 0) {
                dp[i&1][j] = max(dp[(i+1)&1][j], profit[i] + dp[(i+1)&1][j-vol[i]]);
            } else {
                dp[i&1][j] = dp[(i+1)&1][j];
            }
        }
    }
    ll ans = LLONG_MIN;
    for(int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        ans = max(ans, max(dp[0][a], dp[1][a]) - b);
    }
    cout<<ans<<endl;
}