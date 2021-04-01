#include <bits/stdc++.h>
using namespace std;

int sum[400001], num[100001];
// keep num size 4*n;

/// Building segment trees...
void build(int at, int L, int R)
{
	sum[at] = 0;
	
	if(L==R){
		// keeping the sum...
		// Or, maybe other queries...
		sum[at] = num[L];
		
		return;
	}
	
	int mid = (L+R)/2;
	build(at*2, L, mid);
	build(at*2+1, mid+1, R);
	
	// keeping the sum...
	// Or, maybe other queries...
	sum[at] = sum[at*2] + sum[at*2+1];
}

/// Updating segment tree...
void update(int at, int L, int R, int pos, int u)
{
	if(L==R){
		sum[at] += u;
		return;
	}
	
	int mid = (L+R)/2;
	
	// instead of if-else
	// we can use 
	// if(pos < L || R < pos) return;
	if(pos<=mid) update(at*2, L, mid, pos, u);
	else update(at*2+1, mid+1, R, pos, u);
	
	sum[at] = sum[at*2] + sum[at*2+1];
}


/// Making queries in segment tree...
int query(int at, int L, int R, int l, int r)
{
	// query from l to r.
	if(r < L || l > R) return 0;
	if(l <= L && R <= r) return sum[at];
	
	int mid = (L+R)/2;
	int x = query(at*2, L, mid, l, r);
	int y = query(at*2+1, mid+1, R, l, r);
	
	return x+y;
}

int main()
{
	int n, u, q, pos, value, l, r;
	
	// Input data(s).
	cin >> n;
	for(int K=1; K<=n; K++) cin >> num[K];
	
	// build...
	build(1, 1, n);
	
	// update...
	
	# handle indexes for 0 based ones. ( This Tamplate is 1 based...)
	# consider overflow for sum.
	for(int K=1; K<=4*n; K++) cout << sum[K] << ' ';
	cout << "\n";
	
	cin >> u;
	while(u--){
		cin >> pos >> value;
		update(1, 1, n, pos, value);
	}
	
	// queries...
	cin >> q;
	while(q--){
		cin >> l >> r;
		cout << query(1, 1, n, l, r) << "\n";
	}
	
	return 0;
}
