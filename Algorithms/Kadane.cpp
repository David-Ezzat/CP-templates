#include <bits/stdc++.h>
using namespace std;

// 1. Computes the maximum sum of a contiguous subarray using Kadane's algorithm.
// Input: arr (0-indexed array).
// Returns: the maximum subarray sum.
// Time: O(N)
int getMaxSubarraySum(vector<int> &arr) {
    int n = arr.size();
    int ret = arr[0], prev = arr[0];
    for (int i = 1; i < n; i++) {
        prev = max(arr[i], prev + arr[i]);
        ret = max(ret, prev);
    }
    return ret;
}

signed main() {
    vector<int> arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << getMaxSubarraySum(arr1) << " -> Expected: 6\n";

    vector<int> arr2 = {5};
    cout << getMaxSubarraySum(arr2) << " -> Expected: 5\n";

    vector<int> arr3 = {-3, -1, -2};
    cout << getMaxSubarraySum(arr3) << " -> Expected: -1\n";

    return 0;
}
