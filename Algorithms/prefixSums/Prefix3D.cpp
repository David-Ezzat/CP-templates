#include <bits/stdc++.h>
using namespace std;
#define ll long long

namespace Prefix3D {
    // pre: READ-ONLY. The built 3D prefix-sum table (1-based, size (L+1) x (R+1) x (C+1)).
    vector<vector<vector<ll>>> pre;

    // 1. Builds the 3D prefix-sum table from a 3D array and stores it internally.
    // Input: A (the source 3D array, 0-based).
    // Time: O(L * R * C)
    void buildPrefix(const vector<vector<vector<ll>>>& A) {
        int L = A.size();
        int R = A[0].size();
        int C = A[0][0].size();
        pre = vector(L+1, vector(R+1, vector<ll>(C+1, 0)));
        for (int i = 1; i <= L; i++) {
            for (int j = 1; j <= R; j++) {
                for (int k = 1; k <= C; k++) {
                    pre[i][j][k] = A[i-1][j-1][k-1]
                        + pre[i-1][j][k]
                        + pre[i][j-1][k]
                        + pre[i][j][k-1]
                        - pre[i-1][j-1][k]
                        - pre[i-1][j][k-1]
                        - pre[i][j-1][k-1]
                        + pre[i-1][j-1][k-1];
                }
            }
        }
    }

    // 2. Computes the sum of the box [x1..x2] x [y1..y2] x [z1..z2] using the stored prefix table.
    // Input: x1, y1, z1, x2, y2, z2 (inclusive range bounds).
    // Returns: the sum of the specified box.
    // Time: O(1)
    // WARNING: x1, y1, z1, x2, y2, z2 must be 1-based (matching the prefix table's indexing). Adjust if your problem uses 0-based coordinates.
    ll querySum(int x1, int y1, int z1, int x2, int y2, int z2) {
        ll res = pre[x2][y2][z2]
            - pre[x1-1][y2][z2]
            - pre[x2][y1-1][z2]
            - pre[x2][y2][z1-1]
            + pre[x1-1][y1-1][z2]
            + pre[x1-1][y2][z1-1]
            + pre[x2][y1-1][z1-1]
            - pre[x1-1][y1-1][z1-1];
        return res;
    }
}
using namespace Prefix3D;

signed main() {
    vector<vector<vector<ll>>> A = {
        { {1, 2}, {3, 4} },
        { {5, 6}, {7, 8} }
    };
    buildPrefix(A);
    cout << querySum(1, 1, 1, 2, 2, 2) << " -> Expected: 36\n";
    cout << querySum(1, 1, 1, 1, 1, 1) << " -> Expected: 1\n";
    cout << querySum(2, 2, 2, 2, 2, 2) << " -> Expected: 8\n";
    return 0;
}