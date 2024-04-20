#include<bits/stdc++.h>
#define ll long long 
#define fin ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{
	int n;
	int h[10005],w[10005];
	cin>>n;
	for(auto i=0 ,j=0;i<=n,j<n;i++,j++){
		cin>>h[i];
		cin>>w[i];
	}
	int q;
	//d e m l
	while(q--){
		int d,e,m,l;i
	}
}

```c++
#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define endl '\n'


int c[4] = {};
int a[4] = {};
vector<vector<int>> s(100, vector<int>(4));
vector<int> temp;
int t = 0;
void dfs(int x) {
    if (x >= 4) {
        s[t] = temp;
        t++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        
        if (c[i] == 0) {
            c[i] = 1;
            temp.push_back(a[i]);
            dfs(x + 1);
            temp.pop_back();
            c[i] = 0;
        }

    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    dfs(0);
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 4; j++) {
            cout << s[i][j] << ' ';
        }
        cout << endl;
    }
}
```