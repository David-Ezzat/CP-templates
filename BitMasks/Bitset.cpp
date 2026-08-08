#include <bitset>
using namespace std;

// ======================================================
// std::bitset
// Fixed-size sequence of bits.
// For a compile-time constant MAX_BITS = 64, most operations are effectively O(1).
// Note: count(), all(), any(), none(), to_string(), to_ullong() are O(MAX_BITS / word_size).
// ======================================================

const int MAX_BITS = 64;

signed main() {
    // Create a bitset.
    bitset<MAX_BITS> bs;

    // --------------------------------------------------
    // Access
    // --------------------------------------------------

    // Read the i-th bit.
    bool bit = bs.test(0);

    // Read using operator[].
    bool bit2 = bs[0];

    // --------------------------------------------------
    // Modify
    // --------------------------------------------------

    // Set the i-th bit.
    bs.set(0);

    // Set all bits.
    bs.set();

    // Reset the i-th bit.
    bs.reset(0);

    // Reset all bits.
    bs.reset();

    // Flip the i-th bit.
    bs.flip(0);

    // Flip all bits.
    bs.flip();

    // --------------------------------------------------
    // Queries
    // --------------------------------------------------

    // Returns true if all bits are 1.
    bs.all();

    // Returns true if at least one bit is 1.
    bs.any();

    // Returns true if all bits are 0.
    bs.none();

    // Count the number of set bits.
    bs.count();

    // Returns the size of the bitset.
    bs.size();

    // --------------------------------------------------
    // Conversion
    // --------------------------------------------------

    // Convert to unsigned long long.
    // Note: Throws overflow_error if the value does not fit.
    unsigned long long x = bs.to_ullong();

    // Convert to string.
    string s = bs.to_string();

    // --------------------------------------------------
    // Bitwise Operations
    // --------------------------------------------------

    bitset<MAX_BITS> a, b;

    a &= b;
    a |= b;
    a ^= b;

    bitset<MAX_BITS> c = ~a;

    a <<= 3;
    a >>= 2;

    return 0;
}