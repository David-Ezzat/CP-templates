#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 500 + 5;

namespace DenseDijkstra {
    int N_nodes;
    // Note: If the problem requires long long for weights/distances, 
    // change 'int' to 'long long' and use 0x3f3f3f3f3f3f3f3fLL for infinity.
    int dist[N], adj[N][N], nvis[N], par[N];

    /**
     * Initializes the graph matrices and structures.
     * @param x Number of nodes (1-indexed or 0-indexed depending on input)
     */
    void init(int x) {
        N_nodes = x;
        memset(dist, 0x3f, N_nodes * sizeof(dist[0])); // Sets values to ~1B (0x3f3f3f3f)
        memset(adj,  0x3f, N_nodes * sizeof(adj[0]));
        memset(par,  -1,   N_nodes * sizeof(par[0]));
        iota(nvis, nvis + N_nodes, 0);
    }

    /**
     * Calculates the shortest path from source 's' to all reachable nodes.
     * Optimized O(V^2) implementation for dense graphs.
     */
    int shortestPath(int s, int t) {
        int remaining = N_nodes;
        int nxt = s, best = 0;
        dist[s] = 0;

        while (nxt != -1) {
            int idx = nxt;
            int u = nvis[idx];
            nxt = -1;
            best = 0x3f3f3f3f;

            // O(1) Pop from unvisited array
            nvis[idx] = nvis[--remaining];

            for (int i = 0; i < remaining; ++i) {
                int v = nvis[i];

                // Relaxation step
                if (dist[v] > dist[u] + adj[u][v]) {
                    dist[v] = dist[u] + adj[u][v];
                    par[v] = u;
                }

                // Node selection for the next iteration
                if (dist[v] < best) {
                    best = dist[v];
                    nxt = i;
                }
            }
        }
        return dist[t];
    }

    /**
     * Reconstructs and prints the path from source to the given node.
     */
    void buildPath(int node) {
        if (par[node] != -1) buildPath(par[node]);
        cout << node << ' ';
    }

    int GetDist(int u) {
        return dist[u];
    }
}

using namespace DenseDijkstra;

signed main() {
#ifdef DAVIDsPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, u, v, w;
    cin >> n >> m;

    // Initializing with n + 1 to safely handle both 0-indexed and 1-indexed graphs
    init(n + 1);

    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u][v] = w;
        // adj[v][u] = w; // Uncomment for Undirected Graphs
    }

    cin >> u >> v;
    cout << shortestPath(u, v) << '\n';
    buildPath(v);

    return 0;
}
