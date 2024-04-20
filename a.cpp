#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    long long ans = 0;
    for (int w = 0; w < n; ++w) {
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                for (int z = 0; z < n; ++z) {
                    int lucky = gcd(a[w], b[x]);
                    lucky = gcd(lucky, c[y]);
                    lucky = gcd(lucky, d[z]);
                    ans += lucky;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
