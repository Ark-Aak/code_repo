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

const int MAXN = 2e5 + 5;
pair <int, int> v[MAXN];
int ord[MAXN], ban[MAXN];
int n, cnt, k;
mt19937 rnd(time(0));

signed main() {
	n = read(), k = read();
	int lstC = read(), lstV = read();
	rep (i, 2, n) {
		int c = read(), v = read();
		if (c == lstC) lstV = max(lstV, v);
		else ::v[++cnt] = dl(lstC, lstV), lstC = c, lstV = v;
	}
	v[++cnt] = dl(lstC, lstV);
	if (n - cnt > k) return puts("-1"), 0;
	else k -= n - cnt;
	n = cnt;
	ll Ans = 0;
	do {
		rep (i, 1, n) ord[i] = i;
		rep (i, 1, 100) shuffle(ord + 1, ord + 1 + n, rnd);
		rep (i, 1, k) ban[ord[i]] = 1;
		vector <pair <int, int> > vals;
		rep (i, 1, n) {
			if (ban[i]) continue;
			vals.push_back(v[i]);
		}
		bool flg = 0;
		ll ans = vals[0].fb;
		rep (i, 1, vals.size() - 1) {
			if (vals[i].ec == vals[i - 1].ec) {
				flg = 1;
				break;
			}
			ans += vals[i].fb;
		}
		rep (i, 1, k) ban[ord[i]] = 0;
		if (flg) continue;
		Ans = max(Ans, ans);
	} while (clock() * 1.0 / CLOCKS_PER_SEC <= 4.95);
	if (Ans) print(Ans);
	else puts("-1");
	return 0;
}
