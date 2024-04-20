#include<bits/stdc++.h>
#define ll long long 
#define fin ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{
    fin
    int n;
    cin >> n;

    vector<int> h(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> h[i];
    }

    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    int q;
    cin >> q;

    while (q--) {
        int d, e, m, l;
        cin >> d >> e >> m >> l;

        int cur_w = l;
        bool can_pass = true;
        int failed_bridge = -1;

        for (int i = 0; i < n; ++i) {
            if (cur_w > w[i]) {
                cur_w = w[i];
            }

            if (d == 1) { 
                e += m * m * (h[i] - h[i + 1]);
            } else {
                e += m * (h[i] - h[i + 1]);
            }

            if (e < 0 || cur_w < l) {
                can_pass = false;
                failed_bridge = i + 1;
                break;
            }
        }

        if (can_pass) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
            cout << failed_bridge << endl;
        }
    }

    return 0;
}
