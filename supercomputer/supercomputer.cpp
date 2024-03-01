// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class FenwickTree {
private:
    int n;
    vector<int> ft;
public:
    FenwickTree(int N) {
            n = N;
            ft.assign(n + 1, 0);
    }
    // Update the Fenwick Tree: flips the value (0 to 1 or 1 to 0)
    void flip(int pos) {
        // Since we need to flip the value, the delta will be 1 if the current value is 0 (to set it to 1)
        // or -1 if the current value is 1 (to reset it to 0).
        int curr = sum(pos, pos);
        int delta = curr == 0 ? 1 : -1;
        for (; pos <= n; pos += pos & -pos) {
            ft[pos] += delta;
        }
    }

    int query(int pos) {
        int sum = 0;
        for (; pos > 0; pos -= pos & -pos) {
            sum += ft[pos];
        }
        return sum;
    }

    int sum(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;
    FenwickTree ft(N);
    for (int i = 0; i < K; i++) {
        char type;
        cin >> type;
        if (type == 'F') {
            int i;
            cin >> i;
            ft.flip(i);
        } else if (type == 'C') {
            int l, r;
            cin >> l >> r;
            cout << ft.sum(l, r) << "\n";
        }
    }
    return 0;
}
