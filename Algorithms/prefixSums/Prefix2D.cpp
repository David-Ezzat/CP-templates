#include <bits/stdc++.h>
using namespace std;
#define ll long long

namespace Prefix2D {
    // pre: READ-ONLY. The built 2D prefix-sum table (1-based, size (R+1) x (C+1)).
    vector<vector<ll>> pre;

    // 1. Builds the 2D prefix-sum table from a 2D array and stores it internally.
    // Input: A (the source 2D array, 0-based).
    // Time: O(R * C)
    void buildPrefix(const vector<vector<ll>>& A) {
        int R = A.size();
        int C = A[0].size();
        pre.assign(R + 1, vector<ll>(C + 1, 0));
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                pre[i][j] = A[i-1][j-1]
                + pre[i-1][j]
                + pre[i][j-1]
                - pre[i-1][j-1];
            }
        }
    }

    // 2. Computes the sum of the rectangle [x1..x2] x [y1..y2] using the stored prefix table.
    // Input: x1, y1, x2, y2 (inclusive range bounds).
    // Returns: the sum of the specified rectangle.
    // Time: O(1)
    // WARNING: x1, y1, x2, y2 must be 1-based (matching the prefix table's indexing). Adjust if your problem uses 0-based coordinates.
    ll querySum(int x1, int y1, int x2, int y2) {
        return pre[x2][y2]
        - pre[x1-1][y2]
        - pre[x2][y1-1]
        + pre[x1-1][y1-1];
    }
}
using namespace Prefix2D;

signed main() {
    vector<vector<ll>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    buildPrefix(A);
    cout << querySum(1, 1, 2, 2) << " -> Expected: 12\n";
    cout << querySum(1, 1, 3, 3) << " -> Expected: 45\n";
    cout << querySum(2, 2, 3, 3) << " -> Expected: 28\n";
    return 0;
}