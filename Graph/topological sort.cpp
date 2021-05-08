vi ara[1005], in_deg(1005);
vector<pii> order;
void topsort(int n)
{
	priority_queue<pii> q;
	// maybe a queue is enough sometimes ???
	order.clear();
	
	for(int K=0; K<n; K++){
		if(!in_deg[K]){
			q.push({-K, 1});
			// As want to proccess smaller first
			// multiplying with -1 makes the small number bigger(!)
		}
	}
	
	while(!q.empty()){
		pii u = q.top();
		q.pop();
		
		u.fi *= -1;
		
		order.PB({u.se, u.fi});
		// updating solution list
		
		for(int K=0; K<sz(ara[u.fi]); K++){
			in_deg[ara[u.fi][K]]--;
			
			if(!in_deg[ara[u.fi][K]]){
				q.push({-1*ara[u.fi][K], u.se+1});
				// child node's level is 1 step lower
				// so have to add 1 to parent node's level;
			}
		}
	}
}
