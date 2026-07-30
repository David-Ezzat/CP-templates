#include <bits/stdc++.h>
using namespace std;

namespace DSULinkedList {
    // ncmps: READ-ONLY. Total number of separate groups.
    int n, ncmps;
    vector<int> par, nxt, tail;

    // 1. MUST call this FIRST.
    // Input: N (Total number of elements).
    // Time: O(N)
    void init(int _n) {
        n = _n;
        par.assign(n + 1 , -1); nxt.assign(n + 1, -1);
        tail.assign(n + 1, 0);
        for (int i = 0; i <= n; ++i) tail[i] = i;
        ncmps = n;
    }

    // 2. Returns the "Group ID" (root) of element 'u'.
    // Time: O(α(N)) amortized (with path compression)
    int find(int u) {
        return par[u] < 0 ? u : par[u] = find(par[u]);
    }

    // 3. Connects element 's' with element 'b'.
    // Returns: TRUE if successfully connected, FALSE if ALREADY connected.
    // Time: O(α(N)) amortized (union by size + path compression).
    // The linked-list splice itself is O(1).
    bool merge(int s, int b) {
        s = find(s), b = find(b);
        if (s == b) return false;
        if (-par[s] > -par[b]) swap(s, b);
        par[b] += par[s];
        par[s] = b;
        nxt[tail[b]] = s; tail[b] = tail[s];
        ncmps--;
        return true;
    }

    // 4. Checks if 'u' and 'v' are in the same group. (TRUE/FALSE)
    // Time: O(α(N)) amortized
    bool same(int u, int v) {
        return find(u) == find(v);
    }

    // 5. Gets the total count of elements in the group of 'u'.
    // Note: renamed from size() -> getSize() to avoid clashing with
    // std::size() when this namespace is combined with `using namespace std;`
    // Time: O(α(N)) amortized
    int getSize(int u) {
        return -par[find(u)];
    }

    // 6. Returns a list (vector) of ALL elements in the same group as 'u'.
    // Time: O(size of that component) — NOT O(α(N)), since it walks the
    // full linked list of the group.
    vector<int> getcmp(int u) {
        u = find(u);
        vector<int> ret;
        for (int v = u; ~v; v = nxt[v]) {
            ret.emplace_back(v);
        }
        return ret;
    }

    // 7. Returns a list of ALL groups.
    // WARNING: Modify the loop limits (i = 0 to n - 1) or (i = 1 to n) based on indexing.
    // Time: O(N · α(N)) total — sum of all component sizes = N, plus find() overhead.
    vector<vector<int>> getcmps() {
        vector<bool> vis(n + 1, false);
        vector<vector<int>> ret;
        ret.reserve(ncmps);
        // Loop bounds must match your problem's indexing (0-based or 1-based)
        for (int i = 0; i < n; ++i) { 
            int lead = find(i);
            if (vis[lead]) continue;
            vis[lead] = true;
            ret.emplace_back(getcmp(lead));
        }
        return ret;
    }
}
using namespace DSULinkedList;

signed main() {
    // Quick test to verify manual typing (Using 0-based indexing test)
    init(5); // Elements: 0, 1, 2, 3, 4
    merge(1, 2);
    merge(2, 3);
    merge(4, 0);
    cout << ncmps       << " -> Expected: 2\n";
    cout << getSize(1)  << " -> Expected: 3\n";
    cout << same(0, 4)  << " -> Expected: 1\n";
    vector<vector<int>> res = getcmps();
    cout << res.size()  << " -> Expected: 2\n";

    // Group sizes should be 3 (for 1,2,3) and 2 (for 4,0)
    cout << res[0].size() << " -> Expected: 2 or 3\n"; 
    cout << res[1].size() << " -> Expected: 3 or 2\n";
    return 0;
}
