#include <bits/stdc++.h>
using namespace std;

// 1. Computes the length of the Longest Increasing Subsequence.
// Input: n (number of elements), v (1-indexed vector, valid entries at v[1..n]).
// Returns: length of the LIS.
// Time: O(N log N)
// WARNING: 1-based indexing assumed — v must have size >= n+1 with data starting at v[1]. Adjust bounds if your input is 0-based.
int LIS(int n, vector<int> v) {
    vector<int> res = {v[1]};
    for (int i = 2; i <= n; ++i) {
        if (v[i] > res.back()) res.push_back(v[i]);
        else {
            int pos = lower_bound(all(res), v[i]) - res.begin();
            res[pos] = v[i];
        }
    }
    return res.size();
}

signed main() {
    vector<int> v = {0, 5, 2, 8, 6, 3, 6, 9, 7};
    cout << LIS(8, v) << " -> Expected: 4\n";

    vector<int> v2 = {0, 1, 2, 3, 4, 5};
    cout << LIS(5, v2) << " -> Expected: 5\n";

    vector<int> v3 = {0, 5, 4, 3, 2, 1};
    cout << LIS(5, v3) << " -> Expected: 1\n";
    return 0;
}
