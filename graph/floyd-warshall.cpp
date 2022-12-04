const int N = 400;
ll dist[N+5][N+5];

// Inside main function . . .
// dist[] <- Infinity
for (int K = 1; K <= n; K++) dist[K][K] = 0LL;
while (m--) {
    cin >> a >> b >> c;
    dist[a][b] = dist[b][a] = min(c, dist[a][b]);
}
/*
	Sometimes dijkstra can be used to solve these kinds of problems.
	Complexity: Dijkstra: [ O(V^3*logV) ] && FWA: [ V^4 ],  where E = V^2 
	Is usually used for fast typing/coding; [For n <= 400]

Uses:
	Solving SCC problems on a small weighted graph. ( n <= 400 )
	Printing the shortest path (a bit different from other path printings)
*/
for(int K = 0; K < n; K++){
    for(int L = 0; L < n; L++) p[K][L] = K;
}

for(int M = 0; M < n; M++){
    for(int K = 0; K < n; K++){
        for(int L = 0; L < n; L++){
            if(dist[K][M] + dist[M][L] < dist[K][L]){
				dist[K][L] = dist[K][M] + dist[M][L];
                p[K][L] = p[M][L];
            }
        }
    }
}

// path print . . 
Void print(int i, int j)
{
    if(i != j) print(i, p[i][j]);
    printf(" %d", j);
}
/*
Transitive Closure (Warshall’s Algorithm)
	Instead of weight in the adjacency matrix, we use 1 for directly connected edges and 0 for directly not connected edges.
	Then, run floyd warshall algo.
Minimax and Maximin (Revisited - after MST)
	The minimum cost AdjMat[K][L] is the minimum of either (itself) or (the maximum between AdjMat[K][M] or AdjMat[M][L] )
	Initially AdjMat[][] = {INF} except the given edges. 
Finding the Cheapest / Negative cycle:
	If AdjMat[K][K] < INF, then we have a cycle. The minimum value for AdjMat[K][K] is the cheapest cycle
	If AdjMat[K][K] < 0, then we have a negative cycle.
Finding the graph diameter
	Maximum value in AdjMat[][]
Finding SCC
*/


