#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Returns true if the i-th bit is set.
// Note: i should be in the range [0, 62].
bool checkBit(ll n, int i) {
    return (n >> i) & 1LL;
}

// Sets the i-th bit to 1.
// Note: i should be in the range [0, 62].
ll setBit(ll n, int i) {
    return n | (1LL << i);
}

// Clears the i-th bit to 0.
// Note: i should be in the range [0, 62].
ll clearBit(ll n, int i) {
    return n & ~(1LL << i);
}

// Toggles the i-th bit.
// Note: i should be in the range [0, 62].
ll toggleBit(ll n, int i) {
    return n ^ (1LL << i);
}

// Returns the value of the lowest set bit.
// Note: Returns 0 if n == 0.
ll getLowestSetBit(ll n) {
    return n & -n;
}

// Clears the lowest set bit.
// Note: If n == 0, the result is 0.
ll clearLowestSetBit(ll n) {
    return n & (n - 1);
}

// Checks whether n is a power of two.
bool isPowerOfTwo(ll n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// Useful Built-in Functions:
//
// __builtin_popcountll(x)
// Returns the number of set bits.
//
// __builtin_ctzll(x)
// Returns the number of trailing zeros.
// Note: x must not be 0.
//
// __builtin_clzll(x)
// Returns the number of leading zeros.
// Note: x must not be 0.
//
// __builtin_parityll(x)
// Returns 1 if the number of set bits is odd, otherwise 0.
//
// __builtin_ffsll(x)
// Returns the position (1-based) of the first set bit.
// Returns 0 if x == 0.