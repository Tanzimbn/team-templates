vector<vector<int> > edge(MX + 5);
int bfs(int source, int destination) {
    queue<int> Q;
    vector<int> level(200, -1);
    int u, v;
    Q.push(source);
    level[source] = 0;
    while (!Q.empty()) {
            u = Q.front();
            Q.pop();
            for (int K = 0; K < edge[u].size(); K++) {
                    v = edge[u][K];
              if (level[v] == -1) {
                    level[v] = level[u] + 1;
                    Q.push(v);
                    // can be matched with destination here to get the distance.
                    // Or, can be calculated new persons or nodes    comes in
                    // consideration for the first time.
             }
            }
    }
    return distance;
}

Uses:
Graph traversal
Finding connected component [undirected graph]
Flood fill - Labelling/colouring the connected components
Usually used in implicit-graph/2D-grid
dividing grid into colouring to solve problem 
Topological sort [Directed acyclic graph]
Needs a priority list
Used in preprocessing step for ‘DP on DAG’
Bicoloring / Bipartite Graph check
Finding cycles
Finding Articulation Point/Bridge
Finding SCC [directed graph]
Used as subproblem involves directed graph that ‘requires transformation’ to DAG
