#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define boost_      ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

ll ara[505][505];
int main()
{
    boost_;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    
    // Code here. . . .
    
    int n, m, a, b, q;
    ll c;
    
    cin >> n >> m >> q;
    
    for(int K=1; K<=n; K++){
		for(int L=1; L<=n; L++) ara[K][L] = MXL;
	}
	for(int K=1; K<=n; K++) ara[K][K] = 0LL;
	
    while(m--){
		cin >> a >> b >> c;
		ara[a][b] = ara[b][a] = min(c, ara[a][b]);
	}
	
	for(int M=1; M<=n; M++){
		for(int K=1; K<=n; K++){
			for(int L=1; L<=n; L++){
				if(ara[K][L] > ara[K][M]+ara[M][L])
					ara[K][L] = ara[K][M]+ara[M][L];
			}
		}
	}
    
    while(q--){
		cin >> a >> b;
		
		if(ara[a][b]>=MXL) cout << -1 << "\n";
		else cout << ara[a][b] << "\n";
	}
    
    return 0;
}
