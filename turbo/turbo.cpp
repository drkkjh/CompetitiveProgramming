// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max 100001

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

        ll sum(int l, int r) {
            return query(r) - query(l - 1);
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin >> N;
    FenwickTree ft(N);
    vector<int> nums(max);
    vector<int> pos(max);
    for (int i = 1; i <= N; i++) {
        int X;
        cin >> X;
        nums[i] = X;
        pos[X] = i;
        ft.add(i, 1);
    }
    int left = 1;
    int right = N;
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 1) {
            ft.add(pos[left], -1);
            cout << ft.sum(1, pos[left]) << "\n";
            left += 1;
        } else {
            ft.add(pos[right], -1);
            cout << ft.sum(pos[right], N) << "\n";
            right -= 1;
        }
    }
};
