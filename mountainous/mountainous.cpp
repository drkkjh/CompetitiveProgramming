#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;   
    int count = -1;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int j = 0; j < n; j++) {
        int offset = 1;
        while (j - offset >= 0 and j + offset < n) {
            if (v[j - offset] != v[j + offset] or (v[j - offset] >= v[j - offset + 1])) {
                break;
            } else {
                offset++;
            }
            count = max(count, offset * 2 - 1);
        }
    }
    cout << count << endl;
    return 0;
};
