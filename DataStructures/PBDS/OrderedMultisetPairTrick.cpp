#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// =========================================================
// PBDS Multiset (Pair Trick) - Highly recommended for CP
// =========================================================
template <typename T>
using ordered_multiset_pair = tree<
    pair<T, int>, // {value, unique_id}
    null_type,
    less<pair<T, int>>, // Normal 'less' comparator
    rb_tree_tag,
    tree_order_statistics_node_update
>;

// Helper Function: Count elements strictly less than x -> O(log N)
// Works for ANY type T (int, double, pair, string...) since we only
// push the trick onto the int tie-breaker, never onto T itself
template <typename T>
int count_less(ordered_multiset_pair<T>& s, T x) {
    return s.order_of_key({x, INT_MIN});
}

// Helper Function: Count elements less than or equal to x -> O(log N)
template <typename T>
int count_le(ordered_multiset_pair<T>& s, T x) {
    return s.order_of_key({x, INT_MAX});
}

// Helper Function: Count frequency of a value -> O(log N)
template <typename T>
int count_val(ordered_multiset_pair<T>& s, T x) {
    return count_le(s, x) - count_less(s, x);
}

// Helper Function: Count elements in range [L, R] safely -> O(log N)
template <typename T>
int count_in_range(ordered_multiset_pair<T>& s, T L, T R) {
    if (L > R) return 0;
    return count_le(s, R) - count_less(s, L);
}

// Helper Function: Erase ONE instance of a value -> O(log N)
template <typename T>
void erase_one(ordered_multiset_pair<T>& s, T val) {
    auto it = s.lower_bound({val, INT_MIN});
    if (it != s.end() && it->first == val) s.erase(it);
}

int main() {
    ordered_multiset_pair<int> ms;
    int timer = 0; // Unique ID counter for each inserted element

    // 1. Insert elements -> O(log N)
    ms.insert({10, timer++});
    ms.insert({10, timer++});
    ms.insert({5, timer++});
    ms.insert({20, timer++});
    ms.insert({10, timer++});
    // Now stored as: { {5,2}, {10,0}, {10,1}, {10,4}, {20,3} }

    // 2. find_by_order(k) -> O(log N)
    // Remember to use `.first` to get the actual value
    cout << "0-th element: " << ms.find_by_order(0)->first << "\n"; // Outputs 5
    cout << "2-nd element: " << ms.find_by_order(2)->first << "\n"; // Outputs 10

    // 3. order_of_key(x) -> O(log N)
    // Count how many elements are strictly less than x
    cout << "Elements strictly less than 10: "
         << count_less(ms, 10) << "\n"; // Outputs 1 (only the 5)

    // 4. Count frequency of a value -> O(log N)
    cout << "Count of 10: " << count_val(ms, 10) << "\n"; // Outputs 3

    // 5. Erase ONE instance of a value -> O(log N)
    erase_one(ms, 10);
    cout << "Count of 10 after erase_one: " << count_val(ms, 10) << "\n"; // Outputs 2

    // 6. Count elements in range [L, R] -> O(log N)
    cout << "Elements in range [5, 10]: "
         << count_in_range(ms, 5, 10) << "\n"; // Outputs 3 (5, 10, 10)

    // 7. Size and Empty check -> O(1)
    cout << "Total size: " << ms.size() << "\n"; // Outputs 4

    return 0;
}
