#include <bits/stdc++.h>
using namespace std;

namespace ForwardStar {
    // ne: READ-ONLY. Number of directed edges currently stored (also the next free slot index).
    int ne;
    // to: READ-ONLY. to[e] = destination node of edge e.
    // nxt: READ-ONLY. nxt[e] = index of the next edge in the same adjacency list as e (-1 if none).
    // head: READ-ONLY. head[u] = index of the first edge starting at u (-1 if none).
    vector<int> to, nxt, head;
    // w: READ-ONLY. w[e] = weight of edge e. Only meaningful if the graph is weighted; ignore otherwise.
    vector<int> w;

    // 1. MUST call this FIRST.
    // Input: n (number of nodes), m (number of edges; for an undirected graph each edge is stored twice internally via add()).
    // Time: O(N + M)
    void initialize(int n, int m) {
        ne = 0;
        to.assign(2 * m, 0); nxt.assign(2 * m, 0); w.assign(2 * m, 0);
        head.assign(n, -1);
    }

    // 2. Adds a directed edge from u to v.
    // Input: u (source node), v (destination node), weight (edge weight; only relevant if the graph is weighted, defaults to 0 otherwise).
    // Time: O(1)
    void add(int u, int v, int weight = 0) {
        to[ne] = v;
        w[ne] = weight;
        nxt[ne] = head[u];
        head[u] = ne++;
    }

    // 3. Gets all neighbors (children) of node u.
    // Input: u.
    // Returns: vector of node ids directly reachable from u.
    // Time: O(deg(u))
    vector<int> getNeighbors(int u) {
        vector<int> res;
        for (int e = head[u]; e != -1; e = nxt[e]) res.push_back(to[e]);
        return res;
    }
}
using namespace ForwardStar;

int main() {
    initialize(4, 3);
    add(0, 1, 5);
    add(1, 0, 5);
    add(0, 2, 7);
    add(2, 0, 7);
    add(1, 2, 3);
    add(2, 1, 3);

    vector<int> neighbors = getNeighbors(0);
    sort(neighbors.begin(), neighbors.end());
    for (int x : neighbors) cout << x << " ";
    cout << "-> Expected: 1 2 \n";

    // WARNING: node indices here (0, 1, 2, ...) are 0-based. Adjust bounds/offsets if the problem uses 1-based node numbering.
    for (int e = head[0]; e != -1; e = nxt[e]) {
        int child = to[e];
        int weight = w[e]; // use this only if the graph is weighted
        cout << child << "(" << weight << ") ";
    }
    cout << "-> Expected: 1(5) 2(7) \n";

    return 0;
}
