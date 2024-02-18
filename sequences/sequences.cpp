// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007


ll customPow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result % MOD;
}

int main() {
    string s;
    cin >> s;
    ll zeroCount, inversions, numQuestions;
    zeroCount = 0;
    inversions = 0;
    numQuestions = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            zeroCount++;
        } else if (s[i] == '1') {
            // if we hit a 1, we need to add the number of inversions again,
            // with the number of zeros * 2^(unknowns(numQuestions))
            // and also with the the summation $\sum_{i}^{2^numQuestions} i * (iC(2^k - i))$ where i is the number of unknowns,
            // and refers to choosing the number of ways to select the zeros that matter out of the number of unknowns which could 
            // possibly be a zero or a one.
            inversions = (inversions + (zeroCount * (customPow(2, numQuestions)) % MOD) + (numQuestions * (customPow(2, numQuestions - 1)) % MOD)) % MOD;
        }
        else {
            // if (numQuestions == 0) {
            //     numQuestions++;
            //     continue;
            // }
            inversions += inversions;
            // formula for $\sum_{i}^{2^numQuestions} i * (iC(2^k - i))$ is $i \cdot 2^(i - 1)$
            inversions = (inversions + (zeroCount * (customPow(2, numQuestions)) % MOD) + (numQuestions * (customPow(2, numQuestions - 1)) % MOD)) % MOD; 
            // we update the number of questions at the end as we need to do the computations before we update the number of unknowns
            numQuestions++;
        }
    }
    cout << inversions % MOD << endl;

    /*
    1 0 1 -> 0 1 1 (1 inversions)
    1 0 0 -> 0 1 0 -> 0 0 1 (2 inversions)
    0 0 1 -> (0 inversions)
    */
};