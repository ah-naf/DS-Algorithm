
bool cmp(node x, node y) {
    if(x.L/BLOCK != y.L/BLOCK) {
        // different blocks, so sort by block.
        return x.L/BLOCK < y.L/BLOCK;
    }
    // same block, so sort by R value
    return x.R < y.R;
}

//---------------------------------------------//

        node Q[m+3];
        for(int i=0; i<m; i++) {
            int l, r;
            cin>>l>>r;
            l--, r--;
            Q[i].L = l, Q[i].R = r;
            Q[i].i = i;
        }
        sort(Q, Q+m, cmp);
        int ans[m+3];
        int cur_l = 0, cur_r = -1;
        for(int i=0; i<m; i++) {
            while (cur_l > Q[i].L) {
                cur_l--;
                add(cur_l);
            }
            while (cur_r < Q[i].R) {
                cur_r++;
                add(cur_r);
            }
            while (cur_l < Q[i].L) {
                remove(cur_l);
                cur_l++;
            }
            while (cur_r > Q[i].R) {
                remove(cur_r);
                cur_r--;
            }
            ans[Q[i].i] = sum;
        }
        cout<<"Case "<<++ca<<":"<<endl;
        for(int i=0; i<m; i++) cout<<ans[i]<<endl;


