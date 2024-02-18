// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main () {
    long long ans = 0;
    int n;
    cin >> n;
    vector<long long> time(n);
    long long sum = 0;
    long long max = 0;
    // Compute the sum of the vector time which stores the time required for the i^th team to understand and implement an algo
    // and compute the max of the vector time at the same time
    for (int i = 0; i < n; i++) {
        cin >> time[i];
        sum += time[i];
        if (time[i] > max) max = time[i];
    }
    // Sum of everything else excluding the max element:
    long long sumExcludingMax = sum - max;
    // Case 1: When max > sumExcludingMax, we need minimally (2 * max) time
    if (max > sumExcludingMax) {
        ans = 2 * max;
    } else {
        // Case 2: When max <= sumExcludingMax, we need minimally the sum of all the time
        ans = sum;
    }
    cout << ans << endl;
};

