
int dp[102][102];
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
    cin>>s;
    int n = s.size();
    ss = s; reverse(ss);
    cout<<"Case "<<tc<<": ";
    memset(dp, -1, sizeof(dp));
    cout<<n- func(n, n)<<endl;
}
