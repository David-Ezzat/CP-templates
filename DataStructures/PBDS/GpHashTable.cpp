#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

// ==========================================
// PBDS gp_hash_table (Default & Safe Custom Hash)
// ==========================================

// A safe hash function for single integers (prevents anti-hash TLE)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    
    // -> Time Complexity: O(1)
    size_t operator()(uint64_t x) const {
        static const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + SEED);
    }
};

// A safe hash function for pairs (useful for 2D grid coordinates)
struct pair_hash {
    // -> Time Complexity: O(1)
    size_t operator()(const pair<int, int>& p) const {
        // Packs two int coordinates into one 64-bit integer, then hashes it
        return custom_hash{}(((uint64_t)(uint32_t)p.first << 32) | (uint32_t)p.second);
    }
};

int main() {
    // ---------------------------------------------------------
    // 1. Using Default gp_hash_table (Without custom_hash)
    // Use this for normal problems without Anti-Hash TLE risks.
    // ---------------------------------------------------------
    gp_hash_table<int, int> default_mp;
    
    // Insert elements -> O(1) average
    default_mp[10] = 500;
    default_mp[20] = 600;
    
    // Access elements -> O(1) average
    cout << "Value of key 10 (Default): " << default_mp[10] << "\n";
    // Outputs: Value of key 10 (Default): 500
    
    // Get the current number of elements -> O(1)
    cout << "Size (Default): " << default_mp.size() << "\n";
    // Outputs: Size (Default): 2

    cout << "-----------------------\n";

    // ---------------------------------------------------------
    // 2. Using gp_hash_table with single integers (Safe Hash)
    // Key: long long, Value: int
    // ---------------------------------------------------------
    gp_hash_table<long long, int, custom_hash> safe_mp;

    // Insert or update elements -> O(1) average
    safe_mp[5] = 100;
    safe_mp[3] = 200;
    safe_mp[7] = 300;
    
    // Access elements -> O(1) average
    cout << "Value of key 5 (Safe): " << safe_mp[5] << "\n"; 
    // Outputs: Value of key 5 (Safe): 100

    // Check if an element exists -> O(1) average
    if (safe_mp.find(5) != safe_mp.end()) {
        cout << "Key 5 is present!\n"; 
        // Outputs: Key 5 is present!
    }

    // Erase an element -> O(1) average
    safe_mp.erase(3);

    // Iterate over elements -> O(N)
    // NOTE: The order of printed elements is RANDOM and changes every run due to the random SEED.
    cout << "Elements in safe_mp:\n";
    for (auto& p : safe_mp) {
        cout << p.first << " -> " << p.second << "\n";
    }
    // Outputs (Example): 
    // 5 -> 100
    // 7 -> 300
    
    cout << "-----------------------\n";

    // ---------------------------------------------------------
    // 3. Using gp_hash_table with pairs (Safe Hash)
    // Key: pair<int, int>, Value: int
    // ---------------------------------------------------------
    gp_hash_table<pair<int, int>, int, pair_hash> coord_count;

    // Increment count for a 2D coordinate -> O(1) average
    coord_count[{3, 5}]++;
    coord_count[{3, 5}]++;
    coord_count[{1, 2}] = 10;
    
    // Access a coordinate -> O(1) average
    cout << "Count for {3, 5}: " << coord_count[{3, 5}] << "\n";
    // Outputs: Count for {3, 5}: 2

    // Iterate over pair elements -> O(N)
    // NOTE: Order is also RANDOM here.
    cout << "Elements in coord_count:\n";
    for (auto& p : coord_count) {
        cout << "{" << p.first.first << ", " << p.first.second << "} -> " << p.second << "\n";
    }
    // Outputs (Example):
    // {1, 2} -> 10
    // {3, 5} -> 2

    return 0;
}
