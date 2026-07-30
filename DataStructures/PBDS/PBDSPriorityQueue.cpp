#include <iostream>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;
using namespace __gnu_pbds;

// =============================
// PBDS Mutable Priority Queue
// =============================
/*
  =========================================================================
  | Heap Tag              | push      | pop       | modify    | erase     |
  =========================================================================
  | pairing_heap_tag      | O(1)      | O(log n)  | O(log n)  | O(log n)  |
  | thin_heap_tag         | O(1)      | O(log n)  | O(1)*     | O(log n)  |
  | binomial_heap_tag     | O(log n)  | O(log n)  | O(log n)  | O(log n)  |
  | rc_binomial_heap_tag  | O(1)      | O(log n)  | O(log n)  | O(log n)  |
  | binary_heap_tag       | O(log n)  | O(log n)  | N/A*      | N/A*      |
  =========================================================================
  * Notes:
  - thin_heap_tag: modify is O(1) when priority increases (decrease-key in min-heap).
  - binary_heap_tag: Does not support stable handles for modify/erase.
*/

// Define a template alias for easier usage. 
// We use pairing_heap_tag because it supports modify/erase and is the fastest by default.
template<typename T, class Cmp = less<T>>
using pbds_pq = __gnu_pbds::priority_queue<T, Cmp, pairing_heap_tag>;

int main() {
    pbds_pq<int> pq;

    // push(): Adds an element to the priority queue and returns a "handle" (iterator) to it.
    // -> O(1)
    auto h1 = pq.push(5);
    auto h2 = pq.push(2);
    auto h3 = pq.push(9);

    // top(): Returns the largest element (since we use less<T> by default).
    // -> O(1)
    cout << pq.top() << "\n"; // Outputs 9

    // modify(): Updates the value of a specific node using its handle.
    // -> O(log N)
    pq.modify(h2, 100); 
    cout << pq.top() << "\n"; // Outputs 100

    // erase(): Removes a specific node using its handle, even if it is not the top element.
    // -> O(log N)
    pq.erase(h3); // Removes the node that originally had value 9

    // pop(): Removes the top (largest) element from the priority queue.
    // -> O(log N)
    pq.pop(); // Removes 100 (which was at the top)

    // Check the top after the previous erase and pop operations
    // -> O(1)
    cout << pq.top() << "\n"; // Outputs 5

    return 0;
}
