void getDivisor(ll idx, ll curDivisor) {
    if(idx == (int)v.size()) {
        divisor.pb(curDivisor);
        return;
    }
    for(ll i=0; i<=v[idx].ss; i++) {
        getDivisor(idx+1, curDivisor);
        curDivisor *= v[idx].ff * 1LL;
    }
}

void getFactor(ll a) {
    for(int i=0; i<(int)primes.size() && primes[i] * primes[i] <= a; i++) {
        if(a % primes[i] == 0) {
            ll cc = 0;
            while(a % primes[i] == 0) {
                a /= primes[i]; cc++;
            }
            v.pb({primes[i], cc});
        }
    }
    if(a > 1) v.pb({a, 1});
    getDivisor(0LL, 1LL);
}