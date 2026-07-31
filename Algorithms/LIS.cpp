#include <bits/stdc++.h>
using namespace std;

// 1. Computes the length of the Longest Increasing Subsequence.
// Input: v (0-indexed vector).
// Returns: length of the LIS.
// Time: O(N log N)
int LIS(vector<int> v) {
    int n = v.size();
    vector<int> res = {v[0]};
    for (int i = 1; i < n; ++i) {
        if (v[i] > res.back()) res.push_back(v[i]);
        else {
            int pos = lower_bound(res.begin(), res.end(), v[i]) - res.begin();
            res[pos] = v[i];
        }
    }
    return res.size();
}

signed main() {
    vector<int> v = {5, 2, 8, 6, 3, 6, 9, 7};
    cout << LIS(v) << " -> Expected: 4\n";

    vector<int> v2 = {1, 2, 3, 4, 5};
    cout << LIS(v2) << " -> Expected: 5\n";

    vector<int> v3 = {5, 4, 3, 2, 1};
    cout << LIS(v3) << " -> Expected: 1\n";

    return 0;
}
