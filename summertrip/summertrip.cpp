#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// does not work yet

int main() {
    int idx1, idx2, count;
    unordered_set<char> s;  
    string input;
    cin >> input;
    int n = input.size();
    while (idx1 < n) {
        idx2 = input.find_first_of(input[idx1], idx1 + 1);
        if (idx2 != -1) {
            s = unordered_set<char>(input.begin() + idx1, input.begin() + idx2);
            count += s.size();
            idx1++;
        } else {
            s = unordered_set<char>(input.begin() + idx1, input.end());
            count += s.size();
            idx1++;
        }
    }
    cout << count << endl;
    return 0;
};
