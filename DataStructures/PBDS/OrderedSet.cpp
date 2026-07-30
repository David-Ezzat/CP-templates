#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// ==========================================
// PBDS Ordered Set Template (Unique elements)
// ==========================================
template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

// Descending order variant (Optional)
template <typename T>
using ordered_set_desc = tree<
    T,
    null_type,
    greater<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

int main() {
    ordered_set<int> st;

    // 1. Insert elements -> O(log N)
    st.insert(10);
    st.insert(5);
    st.insert(20);
    st.insert(15);
    // Elements stored: {5, 10, 15, 20}

    // 2. find_by_order(k) -> O(log N)
    // Returns iterator to the k-th smallest element (0-indexed)
    cout << "0-th element: " << *st.find_by_order(0) << "\n"; // Outputs 5
    cout << "2-nd element: " << *st.find_by_order(2) << "\n"; // Outputs 15

    // Check bounds before dereferencing
    if (st.find_by_order(10) == st.end()) {
        cout << "Index 10 is out of bounds!\n";
    }

    // 3. order_of_key(x) -> O(log N)
    // Returns the number of elements strictly less than x
    cout << "Elements strictly less than 15: " << st.order_of_key(15) << "\n"; // Outputs 2 (5, 10)
    cout << "Elements strictly less than 5: "  << st.order_of_key(5)  << "\n"; // Outputs 0

    // 4. Count elements in range [L, R] -> O(log N)
    int L = 10, R = 20;
    int count_in_range = st.order_of_key(R + 1) - st.order_of_key(L);
    cout << "Elements in range [10, 20]: " << count_in_range << "\n"; // Outputs 3 (10, 15, 20)

    // 5. Erase element -> O(log N)
    st.erase(5); // Erase by value
    st.erase(st.find_by_order(0)); // Erase by iterator

    // 6. Standard functions -> O(1) or O(log N)
    cout << "Size: " << st.size() << "\n"; // O(1)
    cout << "Is empty: " << (st.empty() ? "Yes" : "No") << "\n"; // O(1)

    return 0;
}
