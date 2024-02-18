// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    // We start at $100 to buy stocks
    ll sum = 100;
    ll prevPrice;
    ll numStocks;
    cin >> prevPrice;
    for (int i = 1; i < n; i++) {
        ll currPrice;
        cin >> currPrice;
        // Greedy algorithm
        if (currPrice > prevPrice) {
            // number of stocks has ceiling of 100000. Hence, we can find out the number of stocks we currently can purchase
            // by taking total amount of money / the price of the previous day's stock.
            // Profit here can be calculated by taking the difference of yesterday's stock vs today's stock multiplied by the 
            // number of stocks we could purchase yesterday.
            numStocks = min((sum / prevPrice), (ll) 100000);
            sum += (numStocks * (currPrice - prevPrice));
        }

        prevPrice = currPrice;
    }
    cout << sum << endl;
};
