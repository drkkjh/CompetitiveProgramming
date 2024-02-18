// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int k;
    cin >> n; // total number of apples
    cin >> k; // number of apples that he can hold
    int dist = 0;
    while (n > k) {
        // (n/k) represents the total amount of apples that he has to sacrifice per trip
        // this algorithm is greedy and will take into account a singular kilometer per iteration.
        // Hence, we increment dist by 1 at each iteration.
        dist += 1;
        n -= (n/k);
        // if there are remainders after taking n/k, we know that he has to sacrifice one more apple to make it to the next 
        // km mark.
        int remainder = (n % k);
        if (remainder) n -= 1;
    }
    // When we are done, this means that n <= k, and we can just add the remaining apples as he would be
    // able to sacrifice 1 each until he reaches his final destination.
    dist += n;
    // Since the original problem is 1-indexed, we have to add a final 1 to distance travelled as I started off on a 0-index.
    dist++;
    cout << dist << endl;
};
