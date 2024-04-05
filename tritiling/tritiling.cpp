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
        // We are stacking we 2x1 dominoes
        // Inspiration taken from: https://www.quora.com/POJ-2663-Tri-tiling-Can-someone-describe-the-solution-in-detail-about-this-problem
        // For a 3xN board, we can either:
        // 1) Place 3 dominoes horizontally to cover 3x2 area and solve the remaining 3x(N-2) area
        // 2) Place 1 dominoes vertically and 1 domino horizontally to cover area and solve the remaining 3x(N-1) area with corner removed
        // and we can note that, this unique pattern can only be solved with another similar unique pattern to resolve a N x 3 area.
        // Thus, we can denote the first problem here as g and the mirrored pattern as h
        // Hence, the overarching recurrence for this problem is dp[n] = dp[n-2] + 2 * g[n-1]
        // where g[n] = dp[n-1] + h[n-1]
        // and h[n] = g[n-1]
        // Rewriting everything:
        // dp[n] = dp[n-2] + 2 * g[n-1]
        // g[n] = dp[n-1] + h[n-1]
        // h[n] = g[n-1]
        // thus, dp[n] = dp[n-2] + 2 * (dp[n-1] + h[n-1]) = dp[n-2] + 2 * dp[n-1] + 2 * h[n-1]
        // and resolving the recurrence: dp[n] = 4 * dp[n-2] - dp[n-4] (Since when N is odd, there is no solution available)
        while(true) {
            int n;
            cin >> n;
            if (n == -1) {
                break;
            }
            vector<ll> dp(30, 0);
            dp[0] = 1;
            dp[2] = 3;
            for (int i = 4; i <= n; i +=2) {
                dp[i] = 4 * dp[i - 2] - dp[i - 4];
            }
            cout << dp[n] << "\n";
        }
    };
