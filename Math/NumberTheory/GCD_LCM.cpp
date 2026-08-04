#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Time Complexity: O(log(min(a, b)))
// This is the standard Euclidean algorithm implemented recursively.
// Note: works correctly for a, b >= 0. GCD(0, 0) returns 0 by convention.
ll GCD(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 1 || a == b) return b;
    if (!b) return a;
    return GCD(a % b, b);
}

// Time Complexity: O(log(min(a, b)))
// Same complexity as GCD, since GCD is the only non-constant step here.
// Note: division is done before multiplication (b / GCD first, then * a)
// to reduce the risk of overflow compared to (a * b) / GCD.
// Constraint: if a == 0 and b == 0, GCD(a, b) = 0, which would normally
// cause a division by zero. This case is handled explicitly below.
ll LCM(ll a, ll b) {
    ll g = GCD(a, b);
    if (g == 0) return 0; // handles the (0, 0) edge case safely
    return a * (b / g);
}