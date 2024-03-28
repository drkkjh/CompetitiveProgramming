// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Not solved, TLE on Kattis. Probably should try KMP algorithm.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    string s;
    cin >> s;
    // cout << s << "\n";
    int n;
    cin >> n;
    while (n--) {
        string a;
        int occurence;
        cin >> a >> occurence;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.substr(i, a.length()) == a) {
                count++;
                if (count == occurence) {
                    cout << i + 1 << "\n";
                    break;
                }
            }
            else {
                if (i == s.length() - 1) {
                    cout << -1 << "\n";
                }
            }
        }
    }
};
