#include <bits/stdc++.h>
using namespace std;

namespace DSU {
    // ncmps: READ-ONLY variable. Gives you the current total number of separate groups.
    int n, ncmps;
    vector<int> par;

    // 1. MUST call this FIRST.
    // Input: N (Total number of elements).
    // Note: It safely handles 1-based indexing automatically.
    // Time: O(N)
    void init(int _n) {
        n = _n;
        par.assign(n + 1, -1);
        ncmps = n;
    }

    // 2. Returns the "Group ID" of element 'u'.
    // Note: You usually don't need to call this directly in the main.
    // Time: O(α(N)) amortized (with path compression)
    int find(int u) {
        return par[u] < 0 ? u : par[u] = find(par[u]);
    }

    // 3. Connects element 's' with element 'b'.
    // Returns: TRUE if they successfully connected.
    // Returns: FALSE if they were ALREADY connected.
    // Time: O(α(N)) amortized (union by size + path compression)
    bool merge(int s, int b) {
        s = find(s), b = find(b);
        if (s == b) return false;
        if (-par[s] > -par[b]) swap(s, b);
        par[b] += par[s];
        par[s] = b;
        ncmps--;
        return true;
    }

    // 4. Checks if element 'u' and element 'v' are in the same group.
    // Returns: TRUE if connected, FALSE if disconnected.
    // Time: O(α(N)) amortized
    bool same(int u, int v) {
        return find(u) == find(v);
    }

    // 5. Gets the count of elements in the group of 'u'.
    // Input: Any element 'u'.
    // Returns: Integer (size of the group).
    // Note: renamed from size() -> getSize() to avoid clashing with
    // std::size() when this namespace is combined with `using namespace std;`
    // Time: O(α(N)) amortized
    int getSize(int u) {
        return -par[find(u)];
    }
}
using namespace DSU;

int main() {
    // Quick test to verify manual typing on paper
    init(5);
    merge(1, 2);
    merge(2, 3);
    cout << same(1, 3)  << " -> Expected: 1\n";
    cout << same(1, 4)  << " -> Expected: 0\n";
    cout << getSize(2)  << " -> Expected: 3\n";
    cout << ncmps       << " -> Expected: 3\n";
    merge(4, 5);
    cout << ncmps       << " -> Expected: 2\n";
    return 0;
}
