void solve(int tc) {
    cin>>n; a.resize(n+1); b.resize(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    // memset(dp, -1, sizeof(dp));
    for(int i=a[n]; i<=b[n]; i++) {
        dp[n][i] = 1;
        csum[n][i] += csum[n][i-1] + 1;
    }
    for(int i=n-1; i>=1; i--) {
        for(int j=a[i]; j<=b[i]; j++) {
                int l = max(j, a[i+1]);
                int r = b[i+1];           
                if(l <= r) {
                    dp[i][j] += csum[i+1][r] - csum[i+1][l-1];
                    dp[i][j] %= mod;
                    if(dp[i][j] < 0) dp[i][j] += mod;
                } 
                csum[i][j] = csum[i][j-1] + dp[i][j];
                csum[i][j] %= mod; 
            } 
    }
    ll ans = 0;
    for(int i=a[1]; i<=b[1]; i++) {
        ans += dp[1][i]; ans %= mod;
    }
    cout<<ans<<endl;

}

// https://atcoder.jp/contests/abc222/tasks/abc222_d