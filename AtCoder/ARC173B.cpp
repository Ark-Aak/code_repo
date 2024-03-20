#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <immintrin.h>
#include <emmintrin.h>

#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
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

const int MAXN = 305;
int x[MAXN], y[MAXN], id[MAXN];
int n, vis[MAXN], ans;

int ord[MAXN], tx[MAXN], ty[MAXN];
mt19937 rnd(time(0));

inline bool check(int i, int j, int k) {
	if(tx[i] == tx[j] && tx[j] == tx[k]) return 1;
	long double k1 = (ty[i] - ty[j]) * 1.00 / (tx[i] - tx[j]);
	long double k2 = (ty[k] - ty[j]) * 1.00 / (tx[k] - tx[j]);
	long double b1 = ty[i] - k1 * tx[i];
	long double b2 = ty[j] - k2 * tx[j];
	if(abs(k1 - k2) < 0.000001 && abs(b1 - b2) < 0.000001) return 1;
	return 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	rep (i, 1, n) ord[i] = i;
	do {
		memset(vis, 0, sizeof vis);
		shuffle(ord + 1, ord + n + 1, rnd);
		rep (i, 1, n) tx[i] = x[ord[i]], ty[i] = y[ord[i]];
		int tans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				for(int k = j + 1; k <= n; k++) {
					if(vis[i] || vis[j] || vis[k]) continue;
					if(check(i, j, k)) continue;
					tans++;
					vis[i] = vis[j] = vis[k] = 1;
				}
			}
		}
		ans = max(tans, ans);
	} while (clock() * 1.0 / CLOCKS_PER_SEC < 1.9);
	cout << ans;
	return 0;
}
