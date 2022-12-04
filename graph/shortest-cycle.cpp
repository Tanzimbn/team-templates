#include <bits/stdc++.h>
using namespace std;
#define N 100200
vector<int> gr[N];

// Function to add edge
void Add_edge(int x, int y) {
    gr[x].push_back(y);
    gr[y].push_back(x);
}

// Function to find the length of
// the shortest cycle in the graph
int shortest_cycle(int n) {
    // To store length of the shortest cycle
    int ans = INT_MAX;

    // For all vertices
    for (int i = 0; i < n; i++) {
        vector<int> dist(n, (int)(1e9)); // Make distance maximum
        vector<int> par(n, -1);  // Take a imaginary parent
        dist[i] = 0;        // Distance of source to source is 0
        queue<int> q;
        q.push(i);        // Push the source element

        while (!q.empty()) { // Continue until queue is not empty
            // Take the first element
               int x = q.front();
              q.pop();
              for (int child : gr[x]) {
                       // If it is not visited yet
                         if (dist[child] == (int)(1e9)) {
                           dist[child] = 1 + dist[x]; // Increase distance by 1
                                  par[child] = x;   // Change parent
                           q.push(child);   // Push into the queue
                       }
                            else if (par[x] != child and par[child] != x)  // If it is already visited
                                 ans = min(ans, dist[x] + dist[child] + 1);
                    }
        }
    }

    if (ans == INT_MAX) return -1;    // If graph contains no cycle\
    else return ans;    // If graph contains cycle
}

