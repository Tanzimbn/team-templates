struct Node{
	int at, cost;
	
	Node(int _at, int _cost){
		at = _at;
		cost = _cost;
	}
};
bool operator<(Node A, Node B){
	// Priority queue returns the greatest value
	// So we need to write the comparator in a wayy
	// So that cheapest value bacomes greatest value
	return A.cost > B.cost;
}
struct Edge {
	int v, w;
	
	Edge(int _v, int _w){
		v = _v;
		w = _w;
	}
};

vector<Edge> adj[1005];               // adjacency list of weighted graph
priority_queue<Node> PQ;
int dist[101];
int n;
int dijkstra(int source, int dest)
{
	memset(dist, -1, sizeof dist);
	
	dist[source] = 0;
	while(!PQ.empty()) PQ.pop();
	PQ.push(Node(source, 0));
	
	while(!PQ.empty()){
		Node u = PQ.top();
		PQ.pop();
		
		if(u.cost!=dist[u.at]){
			continue;
		}
		
		for(Edge e:adj[u.at]){
			if(dist[e.v]==-1 || dist[e.v] > u.cost+e.w){
				dist[e.v] = u.cost+e.w;
				PQ.push(Node(e.v, dist[e.v]));
			}
		}
	}
	
	return dist[dest];
}
