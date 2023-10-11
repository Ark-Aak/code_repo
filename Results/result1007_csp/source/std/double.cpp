#include <bits/stdc++.h>

#define eb emplace_back
#define ep emplace
#define fi first
#define se second
#define in read<int>()
#define lin read<ll>()
#define rep(i, x, y) for(int i = (x); i <= (y); i++)
#define per(i, x, y) for(int i = (x); i >= (y); i--)

using namespace std;

using ll = long long;
using db = double;
using pii = pair < int, ll >;
using vec = vector < int >;
using veg = vector < pii >;

template < typename T > T read() {
	T x = 0; bool f = 0; char ch = getchar();
	while(!isdigit(ch)) f |= ch == '-', ch = getchar();
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

template < typename T > void chkmax(T &x, const T &y) { x = x > y ? x : y; }
template < typename T > void chkmin(T &x, const T &y) { x = x < y ? x : y; }

const int N = 1e5 + 10;
const int K = 20;

int n, Q, dep[N], fa[K][N];
ll swi[N];
vector < tuple < int, ll, ll > > G[N];

struct node {
	ll dis[2][2];
	int u, v;
	node() { memset(dis, 0x3f, sizeof dis); }
	void setcur(int x, int stx) { dis[stx][stx] = 0, dis[stx][stx ^ 1] = swi[x], u = v = x; }
	friend node operator + (node a, node b) {
		node c; c.u = a.u, c.v = b.v;
		rep(i, 0, 1) rep(j, 0, 1) rep(k, 0, 1) 
			chkmin(c.dis[i][k], a.dis[i][j] + b.dis[j][k]),
			chkmin(c.dis[i][k], a.dis[i][j] + b.dis[j ^ 1][k] + swi[a.v]);
		rep(i, 0, 1) rep(j, 0, 1)
			chkmin(c.dis[i][j], c.dis[i ^ 1][j] + swi[a.u]),
			chkmin(c.dis[i][j], c.dis[i][j ^ 1] + swi[b.v]),
			chkmin(c.dis[i][j], c.dis[i ^ 1][j ^ 1] + swi[a.u] + swi[b.v]);
		return c;
	}
} f[K][N];

node rev(node x) { swap(x.dis[0][1], x.dis[1][0]); swap(x.u, x.v); return x; }

void init(int y, int x, ll w1, ll w2) {
	auto &ret = f[0][y];
	ret.dis[0][0] = min(w1, w2 + swi[y] + swi[x]), ret.dis[1][1] = min(w2, w1 + swi[y] + swi[x]);
	ret.dis[0][1] = min(w1 + swi[x], w2 + swi[y]), ret.dis[1][0] = min(w2 + swi[x], w1 + swi[y]);
	ret.u = y, ret.v = x;
}

void pdfs(int x, int p) {
	for(auto v : G[x]) if(get<0>(v) != p) {
		int y; ll w1, w2; tie(y, w1, w2) = v;
		pdfs(y, x); chkmin(swi[x], swi[y] + w1 + w2);
	}
}

void tdfs(int x, int p) {
	for(auto v : G[x]) if(get<0>(v) != p) {
		int y; ll w1, w2; tie(y, w1, w2) = v;
		chkmin(swi[y], swi[x] + w1 + w2); tdfs(y, x);
	}
}

void dfs(int x, int p) {
	dep[x] = dep[p] + 1, fa[0][x] = p;
	for(auto v : G[x]) if(get<0>(v) != p) {
		int y; ll w1, w2; tie(y, w1, w2) = v;
		dfs(y, x); init(y, x, w1, w2);
	}
}

ll get(int x, int y, int stx, int sty) {
	if(dep[x] < dep[y]) swap(x, y), swap(stx, sty);
	node ret1, ret2; ret1.setcur(x, stx), ret2.setcur(y, sty);
	per(i, K - 1, 0) if(dep[fa[i][x]] >= dep[y]) ret1 = ret1 + f[i][x], x = fa[i][x];
	if(x == y) return ret1.dis[stx][sty];
	per(i, K - 1, 0) if(fa[i][x] != fa[i][y]) ret1 = ret1 + f[i][x], ret2 = ret2 + f[i][y], x = fa[i][x], y = fa[i][y];
	ret1 = ret1 + f[0][x] + rev(ret2 + f[0][y]); return ret1.dis[stx][sty];
}

int main() {
	freopen("double.in", "r", stdin); freopen("double.out", "w", stdout);
	n = in; rep(i, 1, n) swi[i] = lin;
	rep(i, 2, n) {
		int u = in, v = in; ll w1 = lin, w2 = lin;
		G[u].eb(v, w1, w2), G[v].eb(u, w1, w2);
	}
	pdfs(1, 0), tdfs(1, 0), dfs(1, 0); f[0][1].u = 1, f[0][1].v = 0;
	rep(i, 1, K - 1) rep(j, 1, n) 
		f[i][j] = f[i - 1][j] + f[i - 1][fa[i - 1][j]],
		fa[i][j] = fa[i - 1][fa[i - 1][j]];
	Q = in;
	while(Q--) {
		int x, y, stx, sty;
		x = in, y = in;
		if(x & 1) stx = 0; else stx = 1;
		if(y & 1) sty = 0; else sty = 1;
		x = (x + 1) >> 1, y = (y + 1) >> 1;
		printf("%lld\n", get(x, y, stx, sty));
	}
	return 0;
}
