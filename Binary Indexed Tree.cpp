struct BIT {
    vll tree; int n;
    BIT(int n) {
        this->n = n;
        tree.assign(n, 0LL);
    }

    void add(vll v) {
        for(int i=0; i<v.size(); i++) {
            update(i, v[i]);
        }
    }

    void update(int idx, ll val) {
        idx += 1;
        while(idx <= n) {
            tree[idx] += val;
            idx += (idx & (-idx));
        }
    }

    ll sum(int idx) {
        ll sum = 0;
        idx += 1;
        while(idx > 0) {
            sum += tree[idx];
            idx -= (idx & (-idx));
        }
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
};
