// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,bmi,bmi2,lzcnt")
using namespace std;
#define ll long long

class FenwickTree {
    private:
        int n;
        vector<ll> ft;
    public:
        FenwickTree(int N) {
            n = N;
            ft.assign(n + 1, 0);
        }

        void update(int idx, ll value) {
            for (int i = idx; i <= n; i += i & -i) {
                ft[i] += value;
            }
        }

        ll query(int idx) {
            ll sum = 0;
            for (int i = idx; i > 0; i -= i & -i) {
                sum += ft[i];
            }
            return sum;
        }
};

long long countTripleInversions(vector<int>& seq) {
    // We need to use 2 fenwick trees 
    int n = seq.size();
    FenwickTree ft(n);
    FenwickTree ft2(n);
    ll invCount = 0;

    for (int i = n - 1; i >= 0; --i) {
        invCount += ft2.query(seq[i] - 1);
        ft2.update(seq[i], ft.query(seq[i] - 1));
        ft.update(seq[i], 1);
    }

    return invCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i<n; i++) {
        cin >> seq[i];
    }

    cout << countTripleInversions(seq) << "\n";
};
