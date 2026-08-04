#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Complexity: Time O(N log(log N)), Space O(N)
// Note: This function calculates the number of DISTINCT prime factors for each number up to 'n'.
// Constraints: The parameter 'n' should fit in standard memory limits, typically n <= 10^7.
vector<ll> NumberOfDistinctPrimeFactors(ll n) {
    vector<ll> ret(n + 1, 0);
    
    for (ll i = 2; i <= n; i++) {
        if (!ret[i]) {
            for (ll j = i; j <= n; j += i) {
                ret[j]++;
            }
        }
    }
    
    return ret;
}