#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 1e5 + 5;

bool stmer;

int n, w[MAXN];
vector <int> G[MAXN];
int ch[MAXN * 20][2];
int cnt = 0, siz[MAXN], nc[MAXN * 20], dep[MAXN * 20];
int root[MAXN], ans[MAXN], tp[MAXN * 20];

bool edmer;

void init(int d, int cur, int x) {
	int w = (x >> d) & 1;
	if (!ch[cur][w]) ch[cur][w] = ++cnt;
	if (w == 1) dep[cur] = d;
	tp[cur] = w;
	if (d > 0) init(d - 1, ch[cur][w], x);
	else nc[ch[cur][w]] = 1;
	dep[cur] = max(dep[cur], dep[ch[cur][w]]);
	nc[cur] = nc[ch[cur][w]];
}

int merge(int d, int cura, int curb) {
	if (d < 0) return 0;
	if (!cura) return curb;
	if (!curb) return cura;
	if (d == 0) {
		nc[cura] = nc[cura] + nc[curb];
		// cout << "!!!" << cura << " " << nc[cura] << endl;
		dep[cura] = -1;
		if (nc[cura] == 1 && tp[cura] == 1) dep[cura] = 0;
		return cura;
	}
	ch[cura][0] = merge(d - 1, ch[cura][0], ch[curb][0]);
	ch[cura][1] = merge(d - 1, ch[cura][1], ch[curb][1]);
	nc[cura] = nc[ch[cura][0]] + nc[ch[cura][1]];
	dep[cura] = max(dep[ch[cura][0]], dep[ch[cura][1]]);
	if (nc[cura] == 1 && tp[cura] == 1) dep[cura] = d;
	return cura;
}

bool flg = 0;

void check(int u, int fa, int val) {
	if (w[u] == val) flg = 1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		check(v, u, val);
	}
}

void dfs(int u, int fa) {
	siz[u] = 1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(v, u);
		siz[u] += siz[v];
		root[u] = merge(18, root[u], root[v]);
	}
	if (siz[u] == 1) {
		ans[u] = -1;
		return;
	}
	int cura = root[u], curb = root[u];
	int cha = 0, chb = 0;
	_rep (i, 17, 0) {
		cha <<= 1, chb <<= 1;
		// cerr << u << ": " << i << " " << cura << " " << dep[ch[cura][0]] << " " << dep[ch[cura][1]] << " " << nc[ch[cura][0]] << " " << nc[ch[cura][1]] << " " << ch[cura][0] << " " << ch[cura][1] << endl;
		if (dep[ch[cura][0]] > dep[ch[cura][1]] || nc[ch[cura][1]] == 0) {
			cura = ch[cura][0];
			// cout << "go 0" << endl;
			if (ch[curb][0] == cura && nc[cura] == 1) curb = ch[curb][1], chb |= 1;
			else if (ch[curb][0] == cura && nc[cura] > 1) curb = ch[curb][0];
			else if (ch[curb][0] != cura && nc[ch[curb][0]] > 0) curb = ch[curb][0];
			else curb = ch[curb][1], chb |= 1;
		}
		else {
			cha |= 1;
			cura = ch[cura][1];
			// cout << "go 1" << endl;
			if (ch[curb][1] == cura && nc[cura] == 1) curb = ch[curb][0];
			else if (ch[curb][1] == cura && nc[cura] > 1) curb = ch[curb][1], chb |= 1;
			else if (ch[curb][1] != cura && nc[ch[curb][1]] > 0) curb = ch[curb][1], chb |= 1;
			else curb = ch[curb][0];
		}
	}
	// cerr << u << ":" << cha << " " << chb << endl;
	ans[u] = cha ^ chb;
}

signed main() {
	cerr << ((&stmer) - (&edmer)) / 1024.0 / 1024.0 << " MiB" << endl;
	n = read();
	memset(dep, -1, sizeof dep);
	rep (i, 1, n) w[i] = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep (i, 1, n) {
		root[i] = ++cnt;
		init(17, root[i], w[i]);
	}
	dfs(1, 0);
	rep (i, 1, n) print(ans[i]), puts("");
	return 0;
}
