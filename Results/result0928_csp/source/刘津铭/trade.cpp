#include<bits/stdc++.h>
#define int long long
#define N 2010
using namespace std;
int n, m, C, ans = 0;
int a[N], dis[N];
vector<int>p[N], g[N];
void bfs(int X) {
	for(int i = 1; i <= n; i++) dis[i] = -1;
	dis[X] = 0;
	queue<int>Q;
	Q.push(X);
	while(!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for(int i = 0; i < g[x].size(); i++) {
			int y = g[x][i];
			if(dis[y] == -1) {
				dis[y] = dis[x] + 1;
				Q.push(y); 
			}
		}
	}
}
int vis[N], T[N];
void dfs(int x, int t, int num) {
	if(dis[x] == -1) return;
	if(num - t * t * C < vis[x] && t > T[x] || num - t * t * C < 0) return;
	else {
		T[x] = t;
		vis[x] = num - t * t * C;
	} 
	if(x == 1) 	ans = max(ans, num - t * t * C);
	for(int i = 0; i < p[x].size(); i++) {
		int y = p[x][i];
		dfs(y, t + 1, num + a[y]);
	}
}
signed main() {
	freopen("trade.in", "r", stdin);
	freopen("trade.out", "w", stdout);
    scanf("%lld %lld %lld", &n, &m, &C);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%lld %lld", &u, &v);
		p[u].push_back(v);
		g[v].push_back(u);
	} 
	bfs(1);
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
/*
5 6 1
0 6 8 3 5
1 5
5 2
3 2
1 3
2 1
5 3


*/

/*
3 3 1
0 10 20
1 2
2 3
3 1

*/
