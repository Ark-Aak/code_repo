#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2 * 1e5 + 10;
vector<int>v[N], f[N];
int d[N], vis[N], cnt[N];
queue<int>q;
int a[N];
signed main() {
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%lld", &x);
		x += n;
		a[i] = x;
		v[x].push_back(i);
	}
	for(int i = 1; i <= k; i++) {
		string s;
		cin >> s;
		s = ' ' + s;
		for(int j = 1; j <= k; j++) {
			if(s[j] == '1') {
				int x = i + n;
				int y = j + n;
				f[x].push_back(y);
			}
		}
	}
	q.push(1);
	vis[1] = 1;
	for(int i = 1; i <= n; i++) d[i] = 1e9;
	d[1] = 0;
	while(!q.empty()) {
		int p = q.front();
		q.pop();
		++cnt[p];
		if(cnt[p] > n) {
			cout << -1;
			return 0;
		}
		vis[p] = 0;
		for(int i = 0; i < f[a[p]].size(); i++) {
			int x = f[a[p]][i];
			for(int j = 0; j < v[x].size(); j++) {
				int y = v[x][j];
				if(y == p) continue;
				if(d[p] + abs(p - y) < d[y]) {
					d[y] = d[p] + abs(p - y);
					if(!vis[y]) {
						vis[y] = 1;
						q.push(y);
					}
				}
			}
		}
	}
	if(d[n] == 1e9) cout << -1;
	else cout << d[n];
}
