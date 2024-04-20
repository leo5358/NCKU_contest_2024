#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 500005;

vector<int> tree[MAXN]; // 樹形結構
int dist[MAXN]; // 記錄城市到根節點的距離
int benefit[MAXN]; // 記錄每個城市的額外經濟效益

// 深度優先搜索
void dfs(int u, int parent, int d, int c) {
    dist[u] = d;
    benefit[u] = c * dist[u] * dist[u]; // 計算額外經濟效益

    for (int v : tree[u]) {
        if (v != parent) {
            dfs(v, u, d + 1, c);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    // 構建樹形結構
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // 處理每個製造或查詢操作
    for (int i = 0; i < q; ++i) {
        int op, u;
        cin >> op >> u;

        if (op == 1) {
            int c;
            cin >> c;
            dfs(u, -1, 0, c);
        } else {
            cout << benefit[u] << endl;
        }
    }

    return 0;
}
