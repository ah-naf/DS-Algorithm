
// A  and M need to be coprime
int x = bigmod( a, m - 2, m ); // (ax)%m = 1

// When M is not prime
int modInv ( int a, int m ) {
    int x, y;
    ext_gcd( a, m, &x, &y );
 
    // Process x so that it is between 0 and m-1
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}