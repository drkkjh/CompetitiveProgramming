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
    int n, k;
    cin >> n >> k;
    
    vector<string> answers(n);
    for (int i = 0; i < n; i++) {
        cin >> answers[i];
    }
    int bestLowestScore = 0;
    
    // Brute force over every combination of T/F answers for the key
    for (int mask = 0; mask < (1 << k); mask++) {
        string key;
        for (int j = 0; j < k; j++) {
            if (mask & (1 << j)) {
                key.push_back('T');
            } else {
                key.push_back('F');
            }
        }
        
        // Eval current ans key
        int lowestScore = k;
        for (auto& ans : answers) {
            int score = 0;
            for (int j = 0; j < k; j++) {
                if (ans[j] == key[j]) {
                    score++;
                }
            }
            lowestScore = min(lowestScore, score);
        }
        bestLowestScore = max(bestLowestScore, lowestScore);
    }
    cout << bestLowestScore << "\n";
}

