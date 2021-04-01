// Number of divisors...
// Euler's totient function...

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
vector<pair<int, int> > divisors;
void divs(int n) {
	int cnt, tot=1, i;
	
	for(i=0; i<(int)primes.size() && (primes[i]*primes[i])<=n; i++) {
		if(n%primes[i]==0) {
			cnt=1;
			
			while(n%primes[i]==0) {
				n/=primes[i];
				cnt++;
			}
			
			divisors.push_back(make_pair(primes[i], cnt-1));
			tot*=cnt;
		}
	}
	
	if(n>1) {
		tot*=2;
		divisors.push_back(make_pair(n, 1));
	}
	
	printf("Number of divisors %d\n", tot);
	for(i=0; i<(int)divisors.size(); i++)
		printf("%d %d\n", divisors[i].first, divisors[i].second);
}

int main()
{
	sieve(root(n));
	divs(n);
	
	return 0;
}
