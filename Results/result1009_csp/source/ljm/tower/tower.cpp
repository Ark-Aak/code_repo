#include<bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
int n, k;
int f[60][60], a[N];
int dis[N], vis[N];
vector<int>g[60], p[N];
struct node{
	int v, w;
	friend bool  operator < (node a, node b) {
		return a.w > b.w;
	}
};
signed main() {
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
    scanf("%lld %lld", &n, &k);
    for(int i = 1; i <= n; i++) {
    	int x;
    	scanf("%lld", &x);
    	g[x].push_back(i);
    	a[i] = x;
	}
	for(int i = 1; i <= k; i++) 
	for(int j = 1; j <= k; j++) {
		char x;
	    cin >> x;
	    if(x == '1') f[i][j] = 1;
	}
	if(f[a[1]][a[n]] == 1) {
		printf("%lld", n - 1);
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			if(!f[a[i]][j]) continue;
			for(int l = 0; l < g[j].size(); l++) {
				int y = g[j][l];	
			    p[i].push_back(y);
			}
		}
	}
	priority_queue<node>Q;
	Q.push((node){1, 0});
	for(int i = 1; i <= n; i++) dis[i] = 1e18;
	dis[1] = 0;
	while(!Q.empty()) {
		int x = Q.top().v;
		Q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = 0; i < p[x].size(); i++) {
			int y = p[x][i];
			if(dis[y] > dis[x] + abs(x - y)) {
				dis[y] = dis[x] + abs(x - y);
				Q.push((node){y, dis[y]});
			}
		}
	}

	cout << dis[n];
	return 0;
}
/*
5 4 
1 4 2 3 4
1010
0001
0110
0100
*/





