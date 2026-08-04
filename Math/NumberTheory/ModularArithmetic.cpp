#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7; // change this if your problem uses a different modulus

// Normalizes any integer (positive or negative) into the range [0, MOD)
// Time complexity: O(1)
// Note: useful whenever a raw value might be negative before using it in other functions
ll fixMod(ll a) {
    a %= MOD;
    if (a < 0) a += MOD;
    return a;
}

// Fast modular exponentiation: computes (b^n) % MOD
// Time complexity: O(log n)
// Note: n must be a non-negative integer (n >= 0)
// Note: b can be any integer, negative values are handled correctly
ll power(ll b, ll n) {
    b %= MOD;
    if (b < 0) b += MOD; // make sure b is positive before multiplying
    ll s = 1;
    while (n) {
        if (n % 2 == 1) s = s * b % MOD;
        b = b * b % MOD;
        n /= 2;
    }
    return s;
}

// Modular inverse of x under MOD (MOD must be prime - uses Fermat's little theorem)
// Time complexity: O(log MOD)
// Note: x must NOT be divisible by MOD (i.e. x % MOD != 0), otherwise inverse doesn't exist
ll Inv(ll x) {
    return power(x, MOD - 2);
}

// Modular multiplication: (a * b) % MOD
// Time complexity: O(1)
ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

// Modular division: (a / b) % MOD, computed as a * inverse(b)
// Time complexity: O(log MOD) because it calls power() internally
// Note: b must NOT be divisible by MOD
ll divide(ll a, ll b) {
    return mul(a, power(b, MOD - 2));
}

// Modular addition: (a + b) % MOD
// Time complexity: O(1)
ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

// Modular subtraction: (a - b) % MOD, always returns a non-negative result
// Time complexity: O(1)
ll sub(ll a, ll b) {
    return (((a - b) % MOD) + MOD) % MOD;
}