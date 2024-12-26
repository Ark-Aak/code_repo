#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

#include "graph.h"

const int MAXN = 205;

int e[MAXN][MAXN], deg[MAXN];
int f[MAXN], isp[MAXN][MAXN];
int cnt = 1;
vector <pii> G[MAXN];

void dfs(int u, int fa) {
	int k = LastRoad();
	if (~k) e[u][k] = fa, f[u] = k;
	int siz = NumberOfRoads();
	deg[u] = siz;
	rep (i, 1, siz) {
		if (i == k) continue;
		Move(i, 2);
		int col = Color();
		if (col == 1) {
			e[u][i] = ++cnt;
			G[u].emplace_back(cnt, i);
			dfs(cnt, u);
		}
		else {
			int lst = LastRoad();
			if (col == 2) isp[u][i] = lst;
			Move(lst, col);
		}
	}
	if (f[u]) Move(f[u], 3);
}

int base = 1;
int dis[MAXN][MAXN];

void get(int u) {
	int x = (u % (base * 3)) / base + 1;
	rep (i, 1, deg[u]) {
		if (!isp[u][i]) continue;
		Move(i, 1);
		int col = Color();
		Move(LastRoad(), col);
		e[u][i] += base * (col - 1);
	}
	for (auto [v, id] : G[u]) {
		Move(id, x);
		get(v);
	}
	if (f[u]) Move(f[u], x);
}

int ans[MAXN];

void Inspect(int R) {
	dfs(1, 0);
	rep (i, 1, 5) {
		get(1);
		base *= 3;
	}
	rep (i, 1, cnt) {
		rep (j, 1, deg[i]) {
			if (!isp[i][j]) continue;
			e[e[i][j]][isp[i][j]] = i;
		}
	}
	memset(dis, 0x3f, sizeof dis);
	rep (i, 1, cnt) dis[i][i] = 0;
	rep (i, 1, cnt) {
		rep (j, 1, deg[i]) {
			dis[i][e[i][j]] = dis[e[i][j]][i] = 1;
		}
	}
	rep (k, 1, cnt) {
		rep (i, 1, cnt) {
			rep (j, 1, cnt) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	rep (i, 1, cnt) {
		rep (j, i + 1, cnt) {
			ans[dis[i][j]]++;
		}
	}
	rep (i, 1, R) Answer(i, ans[i]);
}
