
#include<bits/stdc++.h>
#define ll long long 
#define fin ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    int maxState = (1 << 3) - 1;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int state = 0; state <= maxState; ++state) {
            int cost = 0;

            if (state & 1) {
                cost += 1;
            }

            if (state & 2) {
                int prevWeight = i - 1;
                while (prevWeight % p == 0 && prevWeight > 0) {
                    prevWeight /= p;
                    cost += 1;
                }
            }

            if (state & 4) {
                for (int j = 1; j <= i / 2; ++j) {
                    cost += dp[j] + dp[i - j];
                }
                cost += 1;
            }

            dp[i] = min(dp[i], cost);
        }
    }

    cout << dp[n] << endl;

    return 0;
}