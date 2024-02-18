// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

// Custom exponentiation function to prevent overflow and faster computational time.
ll customPow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result % MOD;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll digits;
        cin >> digits;
        ll total;
        // 8 is the number of choice that we can make for the first digit, because 0 cannot be the first digit.
        // Hence, we are left with digits - 1 choices for the remaining digits, which can take value from 0 to 8(9 in total).
        total = (8 * customPow(9, digits - 1)) % MOD;
        cout << total << endl;
    }
};
