# 🚀 Advanced Competitive Programming Templates

Welcome to my personal collection of heavily optimized Competitive Programming templates in C++. 

Instead of dumping a massive, unreadable library all at once, I am progressively releasing, documenting, and explaining highly tuned templates. Every template here is designed with **performance, clean architecture, and novelty** in mind.

---

## 📂 Current Collection

### 1. Data Structures
* [x] **Sparse Table** — *(Static RMQ / Range Queries in O(1))*

### 2. Graph Algorithms
* [x] **Dense Dijkstra's Algorithm O(V^2)** — *(Highly optimized for dense graphs using an O(1) pop trick)*
* [ ] Iterative Depth-First Search (DFS)
* [ ] Standard Disjoint-Set Data Structure (DSU)

---

## 🌟 Featured Template: Dense Dijkstra O(V^2)

Most competitive programmers default to the O(E log V) priority-queue (Heap) implementation of Dijkstra. However, for **dense graphs** (where E ≈ V^2), the O(V^2) approach is fundamentally faster due to lower constant factors and avoiding the overhead of heap operations.

### ✨ The Novelty (Optimization Trick)
This implementation uses a custom **`nvis` (unvisited) array trick**. 
Instead of iterating over all V nodes to find the next optimal node, we strictly maintain an array of unvisited nodes. When a node is processed, it is removed in **O(1) time** by swapping it with the last element in the `nvis` array (`nvis[idx] = nvis[--remaining];`). 

This drastically reduces the constant factor and makes the inner loop incredibly fast.

### 📝 Usage Example
```cpp
// 1. Initialize the graph with the number of nodes (handles 0/1-based indexing easily)
DenseDijkstra::init(n + 1);

// 2. Add edges to the adjacency matrix
DenseDijkstra::adj[u][v] = weight; 

// 3. Find the shortest path from Source 'u' to Target 'v'
int shortest_distance = DenseDijkstra::shortestPath(u, v);

// 4. Build and print the path
DenseDijkstra::buildPath(v);
