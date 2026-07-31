#include <bits/stdc++.h>
using namespace std;

namespace CoordinateCompression {
    // sortedVals: READ-ONLY. Sorted, deduplicated values from the last call to Compress().
    vector<int> sortedVals;

    // 1. Compresses the values of 'arr' into contiguous ranks starting from 0.
    // Input: arr (the array of values to compress).
    // Returns: a map from original value to its compressed rank.
    // Time: O(N log N)
    map<int, int> Compress(vector<int> &arr) {
        sortedVals = arr;
        sort(sortedVals.begin(), sortedVals.end());
        map<int, int> ret;
        sortedVals.erase(unique(sortedVals.begin(), sortedVals.end()), sortedVals.end());
        for (int i = 0; i < sortedVals.size(); i++) {
            ret[sortedVals[i]] = i;
        }
        return ret;
    }

    // 2. Gets the number of distinct values from the last call to Compress().
    // Time: O(1)
    int GetSize() {
        return sortedVals.size();
    }
}
using namespace CoordinateCompression;

signed main() {
    vector<int> arr = {40, 10, 20, 10, 30};
    map<int, int> ranks = Compress(arr);
    cout << ranks[10] << " -> Expected: 0\n";
    cout << ranks[20] << " -> Expected: 1\n";
    cout << ranks[30] << " -> Expected: 2\n";
    cout << ranks[40] << " -> Expected: 3\n";
    cout << GetSize()  << " -> Expected: 4\n";
    return 0;
}