#include <vector>
using namespace std;
#define ll long long

vector<int> spf;


// Time Complexity: O(N * log(log(N)))
// Notes: 
// - 'n' is the maximum limit for numbers you want to process.
// - This function MUST be called ONCE before doing any prime factorization.
// - 'n' should typically not exceed 10^7 to avoid Memory Limit Exceeded.

void precomputeSPF(int n) {
    spf.assign(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        spf[i] = i;
    }

    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

// Time Complexity: O(log(X))
// Notes:
// - Returns a vector containing all prime factors of the number 'x'.
// - You must call precomputeSPF(n) first.
// - 'x' must be <= 'n' (the limit passed to precomputeSPF).
// - 'x' must be >= 1.

vector<int> getPrimeFactors(int x) {
    vector<int> factors;
    while (x != 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}