// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    deque<int> stack;
    ll count = 0;
    // This algorithm involves the usage of a monotonically decreasing stack.
    for (int i = 0; i < n; i++) {
        int currHeight;
        cin >> currHeight;
        // If stack is empty, we just add the current height to the stack to begin our algo
        if (stack.empty()) {
            stack.push_front(currHeight);
            // cout << stack.size() << endl;
        } else {
            // We only want to increment count for everything in between, i.e we do not want to increment count when we pop
            // the first guy in the stack.
            while ((stack.size() != 1) && currHeight > stack.front()) {
                stack.pop_front();
                count++;
            }
            // pop the first guy but dont increment count
            if (currHeight > stack.front()) stack.pop_front();
            // We add the next guy which is greater in value, to continue our monotonically decreasing stack
            stack.push_front(currHeight);
            // cout << stack.size() << endl;
        }
    }
    // We have to trivially add the number of adjacent pairs as it is part of the answer. Hence, count += (n-1).
    count += (n - 1);
    cout << count << endl;
};
