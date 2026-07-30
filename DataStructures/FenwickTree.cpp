#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Fenwick Tree (a.k.a. Binary Indexed Tree / BIT)
//
// Supports (all 1-indexed, index 0 unused):
//   add(idx, delta)        -> add delta to a[idx]
//   sumPrefix(idx)         -> a[1] + ... + a[idx]
//   sumRange(l, r)         -> a[l] + ... + a[r]
//   build(a)               -> build whole tree from an existing array
//   lowerBound(target)     -> first index whose prefix sum >= target
//   upperBound(target)     -> first index whose prefix sum >  target
//
// COMPLEXITY SUMMARY (n = size of the tree):
//   init(n)              O(n)
//   add(idx, delta)       O(log n)
//   sumPrefix(idx)        O(log n)
//   sumRange(l, r)        O(log n)
//   build(a)              O(n)
//   lowerBound(target)    O(log n)
//   upperBound(target)    O(log n)
//
// NOTE: lowerBound/upperBound require all stored values to be >= 0
// (prefix sums must be non-decreasing for the binary search to make sense).
// ============================================================

template <class T>
struct Fenwick {
    int n;
    vector<T> bit;

    Fenwick() : n(0) {}
    Fenwick(int n_) { init(n_); }

    // Reset tree to size n_, all values = 0.
    // COMPLEXITY: O(n)
    void init(int n_) {
        n = n_;
        bit.assign(n + 1, T{});
    }

    // Add delta to a[idx].
    // COMPLEXITY: O(log n)
    void add(int idx, T delta) {
        for (int i = idx; i <= n; i += i & -i)
            bit[i] += delta;
    }

    // Return a[1] + a[2] + ... + a[idx].
    // COMPLEXITY: O(log n)
    T sumPrefix(int idx) const {
        T ans{};
        for (int i = idx; i > 0; i -= i & -i)
            ans += bit[i];
        return ans;
    }

    // Return a[l] + a[l+1] + ... + a[r].
    // COMPLEXITY: O(log n)
    T sumRange(int l, int r) const {
        if (l > r) return T{};
        return sumPrefix(r) - sumPrefix(l - 1);
    }

    // Build the tree from an existing 1-indexed array (a[0] ignored).
    // COMPLEXITY: O(n)
    void build(const vector<T>& a) {
        init((int)a.size() - 1);
        for (int i = 1; i <= n; ++i) {
            bit[i] += a[i];
            int parent = i + (i & -i);
            if (parent <= n) bit[parent] += bit[i];
        }
    }

    // First index pos such that sumPrefix(pos) >= target.
    // Returns n+1 if no such index exists.
    // COMPLEXITY: O(log n)
    int lowerBound(T target) const {
        if (target <= T{}) return 1;
        int idx = 0;
        T current{};
        int step = 1;
        while ((step << 1) <= n) step <<= 1;
        for (; step > 0; step >>= 1) {
            int next = idx + step;
            if (next <= n && current + bit[next] < target) {
                idx = next;
                current += bit[next];
            }
        }
        return idx + 1;
    }

    // First index pos such that sumPrefix(pos) > target.
    // COMPLEXITY: O(log n)
    int upperBound(T target) const {
        int idx = 0;
        T current{};
        int step = 1;
        while ((step << 1) <= n) step <<= 1;
        for (; step > 0; step >>= 1) {
            int next = idx + step;
            if (next <= n && current + bit[next] <= target) {
                idx = next;
                current += bit[next];
            }
        }
        return idx + 1;
    }
};

// ------------------------------------------------------------
// Quick usage example (not part of the template):
//
// Fenwick<long long> fw(10);      // array of size 10, all zeros
// fw.add(3, 5);                   // a[3] += 5
// fw.add(7, 2);                   // a[7] += 2
// cout << fw.sumPrefix(5);        // a[1]+...+a[5] = 5
// cout << fw.sumRange(3, 7);      // a[3]+...+a[7] = 7
//
// vector<long long> a = {0, 1, 2, 3, 4, 5}; // a[0] unused
// Fenwick<long long> fw2;
// fw2.build(a);                   // builds in O(n)
// ------------------------------------------------------------
