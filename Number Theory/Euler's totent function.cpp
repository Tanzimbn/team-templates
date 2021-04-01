// Euler's Totient

int EulerT(int n) {
    if(n==1)return 0;
    int cnt, toi=n, i;
    for(i=0; i<primes.size() && (primes[i]*primes[i])<=n; i++) {
        if(n%primes[i]==0) {
        while(n%primes[i]==0) n/=primes[i];
            toi-=toi/primes[i];
        }
    }
    if(n>1) toi-=toi/n;
    return toi;
}
