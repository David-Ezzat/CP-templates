#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// =========================================================
// PBDS Trie (Prefix Search) - Built-in trie with prefix ops
// =========================================================

// pref_trie: stores strings and supports fast prefix search
typedef trie<
    string,
    null_type,
    trie_string_access_traits<>,
    pat_trie_tag,
    trie_prefix_search_node_update
> pref_trie;

// Helper Function: Get all strings that start with a prefix -> O(len + matches)
// Returns a vector of all matching strings
vector<string> words_with_prefix(pref_trie& t, const string& prefix) {
    vector<string> res;
    auto range = t.prefix_range(prefix);
    for (auto it = range.first; it != range.second; ++it) {
        res.push_back(*it);
    }
    return res;
}

// Helper Function: Count how many strings start with a prefix -> O(len + matches)
int count_with_prefix(pref_trie& t, const string& prefix) {
    auto range = t.prefix_range(prefix);
    int cnt = 0;
    for (auto it = range.first; it != range.second; ++it) cnt++;
    return cnt;
}

int main() {
    pref_trie t;

    // 1. Insert strings -> O(len)
    t.insert("apple");
    t.insert("app");
    t.insert("application");
    t.insert("banana");

    // 2. Check if a string exists -> O(len)
    cout << "Does 'app' exist? " << (t.find("app") != t.end()) << "\n"; // Outputs 1

    // 3. Get all strings starting with a prefix -> O(len + matches)
    cout << "Words starting with 'app': ";
    for (auto& w : words_with_prefix(t, "app")) {
        cout << w << " "; // Outputs: app apple application
    }
    cout << "\n";

    // 4. Count strings starting with a prefix -> O(len + matches)
    cout << "Count of words starting with 'app': "
         << count_with_prefix(t, "app") << "\n"; // Outputs 3

    // 5. Erase a string -> O(len)
    t.erase("app");
    cout << "Count after erasing 'app': "
         << count_with_prefix(t, "app") << "\n"; // Outputs 2

    // 6. Size and Empty check -> O(1)
    cout << "Total size: " << t.size() << "\n"; // Outputs 3

    return 0;
}
