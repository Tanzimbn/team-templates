// Bitwise - sieve :- prime number generator;
// 0 for prime, 1 for not prime;  >> Not sure ...

#define MX 1000000000

int marked[MX/64+2];
vector<int> primes;

#define mark(x) marked[x>>6] |= (1<<((x&63)>>1))
#define check(x) (marked[x>>6] & (1<<((x&63)>>1)))

bool isPrime(int x) { return (x>1) && ((x==2) || ((x&1) && (!(check(x))))); }

void seive(int n)
{
    int i, j;
    primes.push_back(2);
    for(i=3; i*i<=n; i+=2){
        if(!check(i)){
            primes.push_back(i);
            for(j=i*i; j<=n; j+=i<<1) mark(j);
        }
    }
}


// sieve :- prime number generator;
// 0 for prime, 1 for not prime;

vector<int> primes;
vector<bool> mark(1000002);
void sieve(int n)
{
    int i, j, limit = sqrt(n*1.) + 2;

    mark[1] = 1;

    for(i = 4; i<=n; i+=2) mark[i] = 1;

    primes.push_back(2);

    for(i = 3; i <= n; i += 2)
    {
        if(!mark[i])
        {
            primes.push_back(i);

            if(i<=limit)
            {
                for(j = i*i; j <= n; j += i*2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}



// another sieve...
// 1 for prime and 0 for not-prime...
ll _sieve_size;
bitset<10000010> bs;

void sieve(ll upperbound)
{
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	
	for(ll i=2; i<=_sieve_size; i++){
		if(bs[i]){
			for(ll j=i*i; j<=_sieve_size; j+=i) bs[j] = 0;
			primes.push_back((int)i);
		}
	}
}
bool isPrime(ll n)
{
	if(n<=_sieve_size) return bs[n];
	
	for(int i=0; i<(int)primes.size(); i++){
		if(n%primes[i]==0) return false;
	}
	return true;
}

sieve(10000000);


/// Segment sieve...
/**
 * 
 * Description: Prime sieve for generating all primes smaller than LIM.
 * Status: Stress-tested
 * Time: LIM=1e9 $\approx$ 1.5s
 * Details: Despite its n log log n complexity, segmented sieve is still faster
 * than other options, including bitset sieves and linear sieves. This is
 * primarily due to its low memory usage, which reduces cache misses. This
 * implementation skips even numbers.
 *
 * Benchmark can be found here: https://ideone.com/e7TbX4
 *
 * The line `for (int i=idx; i<S+L; idx = (i += p))` is done on purpose for performance reasons.
 * Se https://github.com/kth-competitive-programming/kactl/pull/166#discussion_r408354338
 */
#pragma once

const int LIM = 1e6;
bitset<LIM> isPrime;
vi eratosthenes() {
	const int S = round(sqrt(LIM)), R = LIM / 2;
	vi pr = {2}, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
	vector<pii> cp;
	for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
		cp.push_back({i, i * i / 2});
		for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
	}
	for (int L = 1; L <= R; L += S) {
		array<bool, S> block{};
		for (auto &[p, idx] : cp)
			for (int i=idx; i < S+L; idx = (i+=p)) block[i-L] = 1;
		rep(i,0,min(S, R - L))
			if (!block[i]) pr.push_back((L + i) * 2 + 1);
	}
	for (int i : pr) isPrime[i] = 1;
	return pr;
}

