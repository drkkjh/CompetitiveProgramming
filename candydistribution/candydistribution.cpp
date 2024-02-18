// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// cX mod K = 1
// rewritten as: cX + Ky = 1
// This would ensure that buying X amount of bags will result in only 1 spare candy after evenly distributing all candies to K kids.

ll extendedGCD(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll k, c, x, y, gcd;
        cin >> k >> c;
        gcd = extendedGCD(c, k, x, y);
        if (c == 1) {
            cout << (k + 1) << endl;
            continue;
        }
        if (k == 1 && c > 1) {
            cout << 1 << endl;
            continue;
        }
        if (gcd != 1) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        // cout << gcd << endl;
        // cout << x << ":" << y << endl;
        // Ensure that value of x is within the range of [0, k-1]
        // x % k finds remainder when x/k
        // + k to ensure result is non-negative since smallest value of remainder could be negative: -(k-1) if x is negative
        // Final modulo (% k) ensures that the value of x is within the range of [0, k - 1]
        else {
            // cout << x << " " << y << "\n" << endl;
            cout << (x % k + k) % k << endl;
        }
    }
};
