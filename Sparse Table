#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

/*
    Sparse Table Template

    - Change `merge` and `ignore` together to switch operation.
    - query_overlap:  O(1), works only for idempotent operations (min, max, gcd).
    - query_non_overlap: O(log n), works for any associative operation.
*/
namespace SparseTable {
    vector<vector<int> > sp;

    int ignore = LLONG_MAX;
    int merge(int a, int b) {
        return min(a, b);
    }

    void build(int n, const vector<int> &v) {
        sp.assign(__lg(n) + 1, vector<int>(n));
        sp[0] = v;

        for (int bit = 1; (1 << bit) <= n; ++bit) {
            for (int i = 0; i + (1 << bit) <= n; ++i) {
                sp[bit][i] = merge(
                    sp[bit - 1][i],
                    sp[bit - 1][i + (1 << (bit - 1))]
                );
            }
        }
    }

    int answer_non_overlap(int l, int r) {
        int len = r - l + 1, res = ignore;
        for (int bit = 0; (1 << bit) <= len; ++bit) {
            if (((len >> bit) & 1) == true) {
                res = merge(res, sp[bit][l]);
                l += (1 << bit);
            }
        }
        return res;
    }

    int answer_overlap(int l, int r) {
        int lg = __lg(r - l + 1);
        return merge(sp[lg][l], sp[lg][r - (1 << lg) + 1]);
    }
};

using namespace SparseTable;


void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &it: v)cin >> it;
    build(n, v);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << answer_overlap(l - 1, r - 1) << el;
    }
}

signed main() {
#ifdef DAVIDsPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
    
    return 0;
}
