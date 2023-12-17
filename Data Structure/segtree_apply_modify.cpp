/*
    apply(apply operation) | modify (find something in range)
    ---------------------------------------------------------
            *              |            +
            +              |         min, max
            &              |            | 
            |              |            &

*/

struct segtree {
    ll NEUTRAL_ELEMENT = -1;
    int size;
    vll operations, values;
 
    ll modify_op(ll a, ll b) {
        return (a | b);
    }

    ll calc_op(ll a, ll b) {
        return (a & b);
    } 

    void apply_mod_op(ll &a, ll b) {
        a = modify_op(a, b);
    }

    void build(int x, int lx, int rx) {
        if(rx - lx == 1) {
            values[x] = 1;
            return;
        }
        int m = (lx + rx) / 2;
        build(2*x + 1, lx, m);
        build(2*x+2, m, rx);
        values[x] = calc_op(values[2*x + 1], values[2*x+2]);
    }

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        operations.assign(2*size, 0LL);
        values.assign(2*size, 0LL);
        // build(0, 0, size);
    }
 
    void modify(int l, int r, int v, int x, int lx, int rx) {
        if(lx >= r || l >= rx) return ;
        if(lx >= l && rx <= r) {
            apply_mod_op(operations[x], v);
            apply_mod_op(values[x], v);
            return;
        }
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        values[x] = calc_op(values[2*x+1], values[2*x+2]);
        apply_mod_op(values[x], operations[x]);
    }
 
    void modify(int l, int r, int v) {
        modify(l, r, v, 0, 0, size);
    }
 
    ll calc(int l, int r, int x, int lx, int rx) {
        if(lx >= r || l >= rx) return NEUTRAL_ELEMENT;
        if(lx >= l && rx <= r) return values[x];
        int m = (lx + rx) / 2;
        auto m1 = calc(l, r, 2 * x + 1, lx, m);
        auto m2 = calc(l, r, 2 * x + 2, m, rx);
        auto res = calc_op(m1, m2); 
        apply_mod_op(res, operations[x]);
        return res;
    }
 
    ll calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }
};