int dp[3002][3002];
string s, ss;

int func(int i, int j) {
    if(i <= 0 || j<=0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int sum = 0;
    if(s[i-1] == ss[j-1]) {
        sum = max(sum, func(i-1, j-1) + 1);
    } else {
        sum = max(sum, max(func(i-1, j), func(i, j-1)));
    }
    return dp[i][j] = sum;
}

void solve(int tc) {
    cin>>s>>ss;;
    // cout<<"Case "<<tc<<": ";
    memset(dp, -1, sizeof(dp));
    int aa = func(s.size(), ss.size());
    string ans = "";
    int l = s.size(), r = ss.size();
    while(l > 0 && r > 0) {
        if(s[l-1] == ss[r-1]) {
            ans += s[l-1];
            l-- ; r--;
        }
        else if(dp[l-1][r] > dp[l][r-1]) l--;
        else r--;
    }
    reverse(ans);
    cout<<ans<<endl;
}