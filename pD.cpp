#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define endl '\n'

struct c {
    bool left = 1;
    bool right = 1;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<c> g(n + 1);
    for (int k = 0; k < q; k++) {
        int type;
        cin >> type;
        if (type == 1) {
            int i;
            cin >> i;
            g[i].right = 1;
            if (i != n) g[i + 1].left = 1;
        }
        else if (type == 2) {
            int j;
            cin >> j;
            g[j].left = 0;
            g[j].right = 0;
            if (j != n) g[j + 1].left = 0;
            if(j!=1) g[j - 1].right = 0;
        }
        else if (type == 3) {
            int x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            int where = y;
            int flag = 0;
            while (where != x) {
                if (g[where].left == 1) {
                    where -= 1;
                }
                else {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
}