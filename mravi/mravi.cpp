// Author: Derrick Khoo
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    vector<tuple<int, double, bool>> children;
};

vector<Node> nodes;
vector<int> requiredLiquid;

double dfs(int node) {
    if (nodes[node].children.empty()) {
        return requiredLiquid[node];
    }
    double required = 0.0;

    for (auto &child : nodes[node].children) {
        double childAmount = dfs(get<0>(child));
        if (get<2>(child)) {
            childAmount = sqrt(childAmount);
        }
        required = max(required, childAmount / get<1>(child));
    }
    return required;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin >> n;
    nodes.resize(n);
    requiredLiquid.resize(n, 0.0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        double X;
        bool t;
        cin >> a >> b >> X >> t;
        a--; // 1-indexed to 0-index
        b--; // 1-indexed to 0-index
        nodes[a].children.emplace_back(b, X/100, t);
    }
    for (int i = 0; i < n; i++) {
        double required;
        cin >> required;
        if (required != -1) {
            requiredLiquid[i] = required;
        }
    }
    double requiredAmount = dfs(0);
    cout.precision(3);
    cout << fixed << requiredAmount << "\n";
};