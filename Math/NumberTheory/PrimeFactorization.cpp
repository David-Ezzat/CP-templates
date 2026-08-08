#include <bits/stdc++.h>
using namespace std;
#define ll long long


// Complexity: O(sqrt(n)) Time, O(log(n)) Space
// Notes:
// - Returns a vector of pairs, where each pair contains a prime factor and its frequency (power).
// - Parameter 'n' must be strictly >= 1.
vector<pair<ll, ll>> PrimeFacorization(ll n) {
    vector<pair<ll, ll>> ret;
    for (ll i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        if (cnt) {
            ret.push_back({i, cnt});
        }
    }
    if (n > 1) {
        ret.push_back({n, 1});
    }
    return ret;
}
