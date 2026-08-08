#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Time Complexity: O(sqrt(n))
// Notes:
// - Parameter 'n' must be >= 1.
// - The function returns the divisors in an unsorted order.
vector<ll> getDivisors(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) {
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}

// Time Complexity: O(n/x)
// Notes:
// - Parameter 'x' must be >= 1 to avoid an infinite loop.
// - Parameter 'n' is the maximum limit.
vector<ll> getMultiplies(ll x, ll n) {
    vector<ll> ret;
    for (ll i = x; i <= n; i += x) {
        ret.push_back(i);
    }
    return ret;
}