// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin >> n;
    cin.ignore(); // ignore newline after n;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int len = s.length();
        for (int j = 1; j <= len; j++) {
            string pattern = s.substr(0, j);
            string repeated = "";
            // concat to repeated until minimally the length of len;
            while (repeated.length() < len) {
                repeated += pattern;
            }
            // check if original begins with repeated pattern, this will return the minimum length of the pattern if true
            if (s == repeated.substr(0, len)) {
                cout << j << "\n";
                break;
            }
        }
    }
};
