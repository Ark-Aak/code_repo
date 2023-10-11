#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
int a[N], Mini = 1e18, vis[N], res = 1e18, vis2[N], f[N], ff;
vector<int>v[N];
void find(int x, int fa, int op, int tmp) {
	//cout << x << endl;
	if(ff) return;
	if(vis[x]) {
		//cout << now << endl;
		int now = x;
		while(now != tmp) {
			if(op == 1) {
				Mini = min(Mini, now);
				vis[now] = 1;
			}
			else res = min(res, now);
			now = f[now];
		}
		ff = 1;
		//cout << 6666666 << " " << tmp << endl;
		if(op == 1) vis[tmp] = 1, Mini = min(Mini, tmp);
		return;
	}
	for(int i = 0; i < v[x].size(); i++) {
		if(v[x][i] == fa) continue;
		f[v[x][i]] = x;
		find(v[x][i], x, op, tmp);
	}
}
signed main() {
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	int n, Q;
	scanf("%lld%lld", &n, &Q);
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%lld%lld", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int cnt = 0;
	while(Q--) {
		++cnt;
		string op;
		int x;
		cin >> op;
		scanf("%lld", &x);
		if(cnt == 1) {
			vis[x] = 1;
			Mini = x;
			continue;
		}
		if(op == "JC") {
			if(vis[x]) continue;
			//cout << x << endl;
			ff = 0;
			find(x, 0, 1, x);
		}
		else {
			
			if(vis[x]) printf("%lld\n", Mini);
			else {
				ff = 0;
				res = 1e18;
				find(x, 0, 2, x);
				printf("%lld\n", min(res, Mini));
			}

		}
		//cout << Mini << endl;
	}
}
