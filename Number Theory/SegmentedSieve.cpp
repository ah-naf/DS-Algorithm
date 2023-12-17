int segmentedSieve(ll L, ll R)
{
    bool isPrime[R-L+1];
    for(int i=0 ; i<=R-L+1 ; i++)
        isPrime[i]=true;
        
    if(L==1)
        isPrime[0]=false;
        
    for(int i=0 ; primes[i]*primes[i]<=R ; i++) {
        ll curPrime=primes[i];
        ll base=curPrime*curPrime;
        if(base<L) {
            base=((L+curPrime-1)/curPrime)*curPrime;
        }
        for(ll j=base ; j<=R ; j+=curPrime)
            isPrime[j-L]=false;
    }
    int cc = 0;
    for(int i=0 ; i<=R-L ; i++) {
        if(isPrime[i]==true)
            cc++;
    }
    return cc;
}