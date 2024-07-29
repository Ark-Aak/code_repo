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

int n;
string s;
const int MAXN = 5.6e6;
int ch[MAXN][2], tot = 1;
vector <pii> v[MAXN];
vector <int> v0[MAXN], v1[MAXN];

void insert(int l, int r) {
	int cur = 1;
	rep (i, l, r) {
		int cr = s[i] - 48;
		if (!ch[cur][cr]) ch[cur][cr] = ++tot;
		cur = ch[cur][cr];
		v[cur].push_back(dl(l, i));
	}
}

int mx[MAXN];
int l[MAXN], cnt;

#define lowbit(x) ((x) & -(x))

void update(int x, int val) {
	while (x <= cnt) {
		mx[x] = max(mx[x], val);
		x += lowbit(x);
	}
}

int query(int x) {
	int res = 0;
	while (x) {
		res = max(res, mx[x]);
		x -= lowbit(x);
	}
	return res;
}

int dp[MAXN];

void dfs(int x) {
	int pr = cnt;
	for (auto [x, y] : v[x]) {
		cnt++;
		l[cnt] = pr;
		v0[x].push_back(cnt);
		v1[y].push_back(cnt);
	}
	if (ch[x][0]) dfs(ch[x][0]);
	if (ch[x][1]) dfs(ch[x][1]);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	ignore = freopen("string.in", "r", stdin);
	ignore = freopen("string.out", "w", stdout);
#endif
#endif
	cin >> n >> s;
	s = ' ' + s;
	const int B = sqrt(n * 2);
	rep (i, 1, n) insert(i, min(i + B - 1, n));
	int ans = 0;
	dfs(1);
	rep (i, 1, n) {
		for (auto j : v0[i]) {
			dp[j] = query(l[j]) + 1;
			ans = max(ans, dp[j]);
		}
		for (auto j : v1[i]) {
			update(j, dp[j]);
		}
	}
	print(ans), puts("");
	return 0;
}
