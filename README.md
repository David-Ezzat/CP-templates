# 🚀 Advanced Competitive Programming Templates

Welcome to my personal collection of heavily optimized Competitive Programming templates in C++. 

Instead of dumping a massive, unreadable library all at once, I am progressively releasing, documenting, and explaining highly tuned templates. Every template here is designed with **performance, clean architecture, and novelty** in mind.

---

## 📂 Current Collection
### 1. Algorithms & Techniques
- [x] [Kadane's Algorithm](Algorithms/Kadane.cpp) — (Maximum subarray sum in O(n))
- [x] [Longest Increasing Subsequence (LIS)](Algorithms/LIS.cpp) - ((O(n log n) LIS algorithm))
- [x] [Coordinate Compression](Algorithms/CoordinateCompression.cpp) — *(Compress values into contiguous ranks, O(n log n))*
#### Prefix Sums
- [x] [2D Prefix Sums](Algorithms/PrefixSums/Prefix2D.cpp) — *(Build O(R·C), Range-sum query O(1))*
- [x] [3D Prefix Sums](Algorithms/PrefixSums/Prefix3D.cpp) — *(Build O(L·R·C), Range-sum query O(1))*
### 2. Data Structures

- [x] [Sparse Table](DataStructures/SparseTable.cpp) — *(Static RMQ / Range Queries in O(1))*
- [x] [FenwickTree](DataStructures/FenwickTree.cpp) — (Point Update, Prefix/Range Sum & k-th element search in O(log n))

#### Policy-Based Data Structures (PBDS)
> Black-box templates built on GNU's `__gnu_pbds` — ready to use directly.

- [x] [Ordered Set](DataStructures/PBDS/OrderedSet.cpp) — *(Unique elements, order_of_key & find_by_order in O(log n))*
- [x] [Ordered Multiset](DataStructures/PBDS/OrderedMultiset.cpp) — *(Duplicates allowed, int-only helper functions, O(log n))*
- [x] [Ordered Multiset — Pair Trick](DataStructures/PBDS/OrderedMultisetPairTrick.cpp) — *(Generic version for any comparable type, O(log n))*
- [x] [Trie](DataStructures/PBDS/Trie.cpp) — *(Prefix search & count, O(len + matches))*
- [x] [gp_hash_table](DataStructures/PBDS/GpHashTable.cpp) — *(Fast hash map with anti-hash-TLE safe custom hash, O(1) avg)*
- [x] [PBDS Priority Queue](DataStructures/PBDS/PBDSPriorityQueue.cpp) — *(Mutable heap with modify/erase via handles)*

### 3. Graphs

- [x] [Dense Dijkstra's Algorithm O(V^2)](Graphs/DenseDijkstra.cpp) — *(Highly optimized for dense graphs using an O(1) pop trick)*
- [x] [Forward Star](Graphs/ForwardStar.cpp) — *(Memory-efficient static adjacency list for fast graph traversal)*


#### Disjoint set union (DSU)
- [x] [DSU](DataStructures/DSU/DSU.cpp) — *(Union by Size + Path Compression, Component Size & Count in O(α(n)))*
- [X] [DSU with linked list](DataStructures/DSU/DSULinkedLists)  — *(Enumerate Component(s) in O(size) while keeping DSU operations in O(α(n)))*

### 4. Math
#### Number Theory

- [x] [GCD & LCM](Math\NumberTheory\GCD_LCM.cpp) — *(Standard Euclidean algorithm and LCM safely handling zeros, O(log(min(a, b))))*
- [x] [Divisors & Multiples](Math\NumberTheory\GetDivisors_GetMultiplies.cpp) — *(Get all divisors in O(sqrt(n)) & multiples in O(n/x))*
- [x] [Primality Test](Math\NumberTheory\IsPrime.cpp) — *(Check if a number is prime safely, O(sqrt(n)))*
- [x] [Modular Arithmetic](Math\NumberTheory\ModularArithmetic.cpp) — *(Fast Power, Mod Inverse, Add, Sub, Mul, Div under modulo)*
- [x] [Distinct Prime Factors](Math\NumberTheory\NumberOfDistinctPrimeFactors.cpp) — *(Count distinct prime factors up to N, O(N log(log N)))*
- [x] [Prime Factorization](Math\NumberTheory\PrimeFacorization.cpp) — *(Find prime factors and their powers in O(sqrt(n)))*
- [x] [Sieve of Eratosthenes](Math\NumberTheory\Sieve.cpp) — *(Precompute primes up to N, O(N log(log N)))*
- [x] [Smallest Prime Factor (SPF)](Math\NumberTheory\SPF.cpp) — *(O(log X) prime factorization per query after O(N log(log N)) precomputation)*