#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Time Complexity : O(N * log(log(N)))
// Space Complexity: O(N)
//
// This function returns a vector of size (n+1) of type bool.
// prime[i] == true  -> i is a prime number
// prime[i] == false -> i is NOT a prime number
vector<bool> sieve(ll n) {
    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;

    for (ll i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    return prime;
}