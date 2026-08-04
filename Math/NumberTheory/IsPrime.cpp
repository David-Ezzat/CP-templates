#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Complexity: O(sqrt(n)) Time, O(1) Space
// Notes:
// - Checks if a given number 'n' is prime.
// - Works safely for negative numbers, 0, and 1 by instantly returning false.
bool isPrime(ll n) {
    if (n <= 1) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}