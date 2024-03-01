// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool withinDistance(pair<double, double> X, pair<double, double> Y, int max = 8) {
    double dist = sqrt(((X.first - Y.first) * (X.first - Y.first)) + ((X.second - Y.second)*(X.second - Y.second)));
    if (dist <= max) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    int m;
    cin >> m;
    while (m--) {
        double A, B;
        cin >> A >> B;
        pair<double, double> X = make_pair(A, B);
        int n;
        bool flag = false;
        cin >> n;
        for (int i = 0; i < n; i++) {
            double C, D;
            cin >> C >> D;
            pair<double, double> Y = make_pair(C, D);
            if (withinDistance(X, Y) and !flag) {
                cout << "light a candle\n";
                flag = true;
            }
        }
        if (!flag) {    
            cout << "curse the darkness\n";
        }
    }
};