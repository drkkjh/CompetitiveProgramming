// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long binomialCoeff(double n, double k) {
    long long res = 1;
    if (k > n - k) {
        k = n - k;
    }
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

// Function to calculate the probability of winning
double calculateProbability(int N, int V1, int V2, double P, int votesNeeded) {
    double probability = 0.0;
    double remaining = N - V1 - V2;

    for (int i = votesNeeded - V1; i < remaining + 1; i++) {
        probability += binomialCoeff(remaining, i) * pow(P, remaining);
    }

    return probability;
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        double N, V1, V2, W;
        cin >> N >> V1 >> V2 >> W;
        double probability = W / 100.0;
        double votesNeeded;
        double remaining = N - V1 - V2;
        if ((int)N % 2 == 0) {
            votesNeeded = ceil(N / 2) + 1;
        } else {
            votesNeeded = ceil(N / 2);
            // cout << votesNeeded << endl;
        }
        // cout << remaining << " " << votesNeeded << endl;
        if (V1 >= votesNeeded) {
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
        }
        else if (remaining < votesNeeded - V1) {
            cout << "RECOUNT!" << endl;
        } else {
            double probabilityWinning = calculateProbability(N, V1, V2, 0.5, votesNeeded);
            // cout << probabilityWinning << endl;
            if (probabilityWinning > probability) {
                cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
            } else {
                cout << "PATIENCE, EVERYONE!" << endl;
            }
        }
    }
};
