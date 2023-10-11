#include<bits/stdc++.h>
#define int long long
#define N 1000100
using namespace std;
int n, m, q;
struct node{
	int to, val;
};
struct genshine{
	int l, r, t, v;
}a[N];
vector<node>p[N];
bool vis[2000];
int dis[2000], ans[1000006];
struct ys{
	int v, w;
	friend bool operator < (ys a, ys b) {
		return a.w > b.w;
	}  
};
priority_queue<ys>Q; 
bool dij(int s, int t, int l, int r) {
	for(int i = 1; i <= n; i++) dis[i] = -1, vis[i] = 0;
	while(!Q.empty()) Q.pop();
	Q.push((ys){s, l});
	dis[s] = l;
	while(!Q.empty()) {
		int x = Q.top().v;
		//cout << x <<" "<<dis[x]<< endl;
		Q.pop();
		vis[x] = 1;
		for(int i = 0; i < p[x].size(); i++) {
			int y = p[x][i].to, b = p[x][i].val;
			if(dis[x] > b || vis[y] == 1) continue;
			if(b <= dis[y] || dis[y] == -1) {
				dis[y] = b;
			    Q.push((ys){y, b});
			}
		}
	}
	if(dis[t] <= r && dis[t] != -1) return 1;
	return 0;
}
vector<genshine>g[2000]; 
signed main() {
	freopen("journey.in", "r", stdin);
	freopen("journey.out", "w", stdout);
    scanf("%lld %lld %lld", &n, &m, &q);
    for(int i = 1; i <= m; i++) {
    	int u, v;
    	scanf("%lld %lld", &u, &v);
    	p[u].push_back((node){v, i});
    	p[v].push_back((node){u, i});
	}
	for(int i = 1; i <= q; i++) {
		int l, r, s, t;
		scanf("%lld %lld %lld %lld", &l, &r, &s, &t);
		if(dij(s, t, l, r)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	/*for(int i = 1; i <= q; i++) {
		int l, r, s, t;
		scanf("%lld %lld %lld %lld", &l, &r, &s, &t);
		g[s].push_back((genshine){l, r, t, i});
	}
	int tot = 0;
	for(int i = 1; i <= n; i++) {
		cout << i << endl;
		if(g[i].size() == 0) continue;
		for(int j = 0; j < p[i].size(); j++) {
		    int y = p[i][j].to;
		    dij(y, p[i][j].val);
		}
		for(int j = 0; j < g[i].size(); j++) {
			int l = g[i][j].l, r = g[i][j].r, t = g[i][j].t, v = g[i][j].v;
			for(int k = 0; k < p[i].size(); k++) {
				int y = p[i][k].to;
				if(l <= p[i][k].val) {
					if(dis[y][t] <= r && dis[y][t] != -1) {
						ans[v] = 1;
						goto end; 
					} 
				}
			}
			end:;
		}
	}
	for(int i = 1; i <= q; i++) {
		if(ans[i]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}*/ 
	return 0;
}
/*
5 4 1
1 2
2 3
3 4
3 5
1 4 4 1
*/

