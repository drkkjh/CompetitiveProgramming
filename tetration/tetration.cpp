// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    long double N;
    cin >> N;
    // Given N, we need to find a given a^N = N.
    // Equivalent to finding a = N^(1/N).
    long double value = pow(N, 1.0/N);
    cout << value << endl;
};
