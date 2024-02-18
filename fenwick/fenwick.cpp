// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
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
        void add(int pos, ll delta) {
            for (int i = pos; i <= n; i += i & -i) {
                ft[i] += delta;
            }
        }
        ll query(int pos) {
            ll sum = 0;
            for (int i = pos; i > 0; i -= i & -i) {
                sum += ft[i];
            }
            return sum;
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    FenwickTree ft(N);
    for (int i = 0; i < Q; i++) {
        char type;
        cin >> type;
        if (type == '+') {
            int pos; 
            ll delta;
            cin >> pos >> delta;
            ft.add(pos + 1, delta);
        } else {
            int pos;
            cin >> pos;
            if (pos == 0) {
                cout << 0 << "\n";
            }
            else {
                cout << ft.query(pos) << "\n";
            }
        }
    }
    return 0;
};
