#include<bits/stdc++.h>
using namespace std;

int a[1010][1010], n, m, Q, vis[1010], vis2[1010][1010];
struct edge {
	int x, y;
}e[200010];
bool check(int now, int ent, int x, int y) {
	vis[x] = 1;
	if(x == y && now <= ent) return true;
	if(now > ent) return false;
	int Min = 1e9, Mini = -1;
	for(int i = 1; i <= n; i++) {
		if(!a[x][i] || vis[i]) continue;
		if(a[x][i] >= now) {
			int flag = check(a[x][i], ent, i, y);
			if(flag == true) return true; 
		}
	}
	return false;
}
int main() {
	freopen("journey.in", "r", stdin);
	freopen("journey.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &Q);
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = i;
		a[y][x] = i;
		e[i].x = x;
		e[i].y = y;
	}
	while(Q--) {
		int l, r, s, t;
		scanf("%d%d%d%d", &l, &r, &s, &t);
		if(l == r) {
			if(s == t) puts("Yes");
			else if(e[l].x == s && e[l].y == t) puts("Yes");
			else puts("No");
			continue;
		}
		memset(vis, 0, sizeof(vis));
		if(check(l, r, s, t)) puts("Yes");
		else puts("No");
	}

}
