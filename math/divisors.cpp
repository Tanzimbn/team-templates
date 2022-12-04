Maximal number of divisors of any n-digit number:
First 18 numbers: 4, 12, 32, 64, 128, 240, 448, 768, 1344, 2304, 4032, 6720, 10752, 17280, 26880, 41472, 64512, 103680

// Number of divisors...
// Euler's totient function...

// first, run a sieve for value sqrt(n);
vector<pair<int, int> > divisors;
void divs(int n) {
    int cnt, tot = 1, i;
    for (i = 0; i < (int)primes.size() && (primes[i] * primes[i]) <= n; i++) {
            if (n % primes[i] == 0) {
              cnt = 1;
                    while (n % primes[i] == 0) {
                    n /= primes[i];
                    cnt++;
             }
                    divisors.push_back(make_pair(primes[i], cnt - 1));
                    tot *= cnt;
            }
    }
    if (n > 1) {
            tot *= 2;"pascal's triangle.cpp"
            divisors.push_back(make_pair(n, 1));
    }
    printf("Number of divisors %d\n", tot);
    for (i = 0; i < (int)divisors.size(); i++) printf("%d %d\n", divisors[i].first, divisors[i].second);
}
// Number of divisors...
ll NOD(int n) {
    ll ans = 1;
    for (int K = 0; K < sz(divisors); K++) {
            ans *= (ll)(divisors[K].se + 1);
    }
    return ans;
}
// Sum of divisors...
ll SOD(int n) {
    ll ans = 1, cnt;
    for (int K = 0; K < sz(divisors); K++) {
            cnt = divisors[K].fi;
            while (divisors[K].se--) cnt *= (ll)divisors[K].fi;
            ans *= (ll)(cnt - 1) / (divisors[K].fi - 1);
    }
    return ans;
}


// using miller rabin algo.
// complexity O(n^1/3)
// Counting Divisors in O(N^(1/3))
// use miller rabin code here.
bool square(ll n) {
    ll root = sqrt(n);
    for (ll from = root - 2; from <= root + 2; from++) {
        if (from * from == n) return true;
    }
    return false;
}
ll count_divisors(ll n) {
    // divide n with primes <= n^(1/3) and update answer
    ll ans = 1LL;

    for (int p = 2; 1LL * p * p * p <= n; p++) {
        int exp = 0;
        while (n % p == 0) {
            n /= p;
            exp++;
        }
        ans *= (exp + 1);
    }

    // If n doesn't contain any prime factors anymore then we are done
    if (n == 1) return ans;

    // Check if n is prime
    if (miller_rabin(n)) {
        ans *= 2LL;  // add contribution to answer
    }
    // Check if n is a square of a prime
    else if (square(n)) {
        ans *= 3LL;
    }
    // else n is product of two different primes
    else {
        ans *= 4LL;
    }

    return ans;
}
