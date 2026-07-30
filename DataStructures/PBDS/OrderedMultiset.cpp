#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// =============================================== 
// PBDS Ordered Multiset Template (Allows duplicates)
// =============================================== 
template <typename T>
using ordered_multiset = tree<
    T, null_type, less_equal<T>,
    rb_tree_tag, tree_order_statistics_node_update
>;

// Helper Function: Erase ONE instance of a value -> O(log N)
// Works with ANY comparable type T (int, double, pair, string...)
template <typename T>
void erase_one(ordered_multiset<T>& ms, T val) {
    int index = ms.order_of_key(val);
    auto it = ms.find_by_order(index);
    if (it != ms.end() && *it == val) {
        ms.erase(it);
    }
}

// Helper Function: Count frequency of a value -> O(log N)
// !! INT-ONLY !! Uses "val + 1" to get the next distinct value,
// which only makes sense for discrete types (int, long long, char...).
// With double/pair/string, "val + 1" is either meaningless or won't compile.
// -> If you need this to work with other types, use the "pair trick"
//    version instead (tree<pair<T,int>, ...>) with count_less/count_le.
template <typename T>
int count_val(ordered_multiset<T>& ms, T val) {
    return ms.order_of_key(val + 1) - ms.order_of_key(val);
}

// Helper Function: Count elements in range [L, R] safely -> O(log N)
// !! INT-ONLY !! Same issue as count_val ("R + 1"), plus the
// "R == INT_MAX" check is literally hard-coded for the int type.
// -> For a generic version (double/pair/...), use the "pair trick" template.
template <typename T>
int count_in_range(ordered_multiset<T>& s, T L, T R) {
    if (L > R) return 0;
    int right = (R == INT_MAX) ? (int)s.size() : s.order_of_key(R + 1);
    return right - s.order_of_key(L);
}

int main() {
    ordered_multiset<int> ms;

    // 1. Insert elements (Duplicates allowed) -> O(log N)
    ms.insert(10);
    ms.insert(10);
    ms.insert(5);
    ms.insert(20);
    ms.insert(10);
    // Elements stored: {5, 10, 10, 10, 20}

    // 2. find_by_order(k) -> O(log N)
    // Returns iterator to k-th element (0-indexed)
    cout << "0-th element: " << *ms.find_by_order(0) << "\n"; // Outputs 5
    cout << "2-nd element: " << *ms.find_by_order(2) << "\n"; // Outputs 10

    // 3. order_of_key(x) -> O(log N)
    // Returns number of elements strictly less than x
    cout << "Elements strictly less than 10: " << ms.order_of_key(10) << "\n"; // Outputs 1 (only 5)

    // 4. Count frequency of a value -> O(log N)
    cout << "Count of 10: " << count_val(ms, 10) << "\n"; // Outputs 3

    // 5. Erase ONE instance of value -> O(log N)
    erase_one(ms, 10);
    cout << "Count of 10 after erase_one: " << count_val(ms, 10) << "\n"; // Outputs 2

    // 6. Size and Empty check -> O(1)
    cout << "Total size: " << ms.size() << "\n"; // Outputs 4

    return 0;
}
