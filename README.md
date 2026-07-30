# 🚀 Advanced Competitive Programming Templates

Welcome to my personal collection of heavily optimized Competitive Programming templates in C++. 

Instead of dumping a massive, unreadable library all at once, I am progressively releasing, documenting, and explaining highly tuned templates. Every template here is designed with **performance, clean architecture, and novelty** in mind.

---

## 📂 Current Collection

### 1. Data Structures

- [x] [Sparse Table](DataStructures/SparseTable.cpp) — *(Static RMQ / Range Queries in O(1))*
- [x] [FenwickTree](DataStructures/FenwickTree.cpp) — (Point Update, Prefix/Range Sum & k-th element search in O(log n))
#### Disjoint set union (DSU)

- [x] [DSU](DataStructures/DSU/DSU.cpp)
- [X] [DSU with linked list](DataStructures/DSU/DSULinkedLists)
      
#### Policy-Based Data Structures (PBDS)
> Black-box templates built on GNU's `__gnu_pbds` — ready to use directly.

- [x] [Ordered Set](DataStructures/PBDS/OrderedSet.cpp) — *(Unique elements, order_of_key & find_by_order in O(log n))*
- [x] [Ordered Multiset](DataStructures/PBDS/OrderedMultiset.cpp) — *(Duplicates allowed, int-only helper functions, O(log n))*
- [x] [Ordered Multiset — Pair Trick](DataStructures/PBDS/OrderedMultisetPairTrick.cpp) — *(Generic version for any comparable type, O(log n))*
- [x] [Trie](DataStructures/PBDS/Trie.cpp) — *(Prefix search & count, O(len + matches))*
- [x] [gp_hash_table](DataStructures/PBDS/GpHashTable.cpp) — *(Fast hash map with anti-hash-TLE safe custom hash, O(1) avg)*
- [x] [PBDS Priority Queue](DataStructures/PBDS/PBDSPriorityQueue.cpp) — *(Mutable heap with modify/erase via handles)*

### 2. Graph Algorithms
* [x] [Dense Dijkstra's Algorithm O(V^2)](Graphs/dense_dijkstra.cpp) — *(Highly optimized for dense graphs using an O(1) pop trick)*
* [ ] Iterative Depth-First Search (DFS)
* [ ] Standard Disjoint-Set Data Structure (DSU)

