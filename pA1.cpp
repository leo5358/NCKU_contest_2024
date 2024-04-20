#include<bits/stdc++.h>
#define ll long long 
#define fin ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int minDuckCoins(int n, int p) {
    
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0; 

    for (int weight = 1; weight <= n; ++weight) {

        dp[weight] = min(dp[weight], dp[weight - 1] + 1);

        if (weight % p == 0) {
            dp[weight] = min(dp[weight], dp[weight / p]);
        }


        for (int i = 1; i < weight; ++i) {
            dp[weight] = min(dp[weight], dp[i] + dp[weight - i] + 1);
        }
    }

    return dp[n];
}

int main()
{
    fin
    int n, p;
    cin >> n >> p;
    cout << minDuckCoins(n, p) << endl;
    return 0;
}
