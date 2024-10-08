#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 100005;
const int INF = 1e12;

struct edge{
	int nxt, v;
	ll c;
} e[10 * MAXN];

int cnt = 1, then[MAXN], dis[MAXN];

queue<int> q;

void _add(int u, int v, ll c){e[++cnt]=(edge){then[u], v, c}; then[u]=cnt;}
void add(int u, int v, ll c){_add(u, v, c); _add(v, u, 0);}

int S = 0, T = 1e5, cur[MAXN];
int n, m, a[MAXN], b[MAXN], x[MAXN], y[MAXN];

bool dinic_bfs(){
	fill(dis, dis + MAXN, -1);
	dis[S] = 0; q.push(S);
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(int u = then[t]; u; u = e[u].nxt){
			if(e[u].c > 0 && dis[e[u].v] == -1){
				dis[e[u].v] = dis[t] + 1;
				q.push(e[u].v);
			}
		}
	}
	return dis[T] != -1;
}

ll dinic_dfs(int x, ll flow){
	if(x == T) return flow;
	ll rf = flow;
	for(int &u = cur[x]; u; u = e[u].nxt){
		if(rf <= 0) break;
		cur[x] = u;
		ll rf_x = e[u].c;
		if(rf_x > 0 && dis[e[u].v] > dis[x]){
			ll transfer = dinic_dfs(e[u].v, min(rf_x, rf));
			rf -= transfer;
			e[u].c -= transfer;
			e[u ^ 1].c += transfer;
		}
	}
	return flow - rf;
}

ll dinic(){
	ll ans = 0;
	while(dinic_bfs()){
		copy(then, then + MAXN, cur);
		ans += dinic_dfs(S, INF);
	}
	return ans;
}

int val[MAXN];

int nd;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("gentle.in", "r", stdin);
	freopen("gentle.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) a[i] = read(), b[i] = read(), val[i] = a[i];
	m = read();
	rep (i, 1, m) {
		x[i] = read(), y[i] = read();
		val[x[i]] = max(val[x[i]], b[x[i]]);
		val[y[i]] = max(val[y[i]], b[x[i]]);
	}
	return 0;
}
