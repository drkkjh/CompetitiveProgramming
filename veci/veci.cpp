// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main() {
    string s;
    cin >> s;
    string s2 = s;
    // we can use std::next_permutation to obtain the answer directly. However, we need to check if the 
    // next permutation generated is lexicographically greater than the original string as there might be
    // a permutation in which there is no lexicographically greater permutation.
    next_permutation(s.begin(), s.end());
    string result = (s <= s2) ? "0" : s;
    cout << result << endl;
};
