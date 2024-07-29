#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#include <bits/stdc++.h>
#include <bits/extc++.h>

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

const int MAXN = 2e3 + 5;
int T, n, ans;
string a, b;

int tL[MAXN], tR[MAXN];

int calc(int x) {
	int cnt = 0, ans = 1e9, buc[MAXN] = {0};
	rep (i, 0, n - 1) if (a[i] != b[(i + x) % n]) cnt++;
	rep (i, 0, n - 1) if (a[i] != b[(i + x) % n]) buc[tR[i]] = max(buc[tR[i]], tL[i]);
	_rep (i, n - 1, x) buc[i] = max(buc[i], buc[i + 1]);
	rep (i, x, n - 1) ans = min(ans, i + buc[i + 1]);
	return (ans << 1) - x + cnt;
}

void solve() {
	cin >> a >> b;
	n = a.size();
	if (b.find('1') == string::npos) {
		if (a == b) puts("0");
		else puts("-1");
		return;
	}
	int ans = 1e9;
	rep (i, 0, n - 1) {
		memset(tL, 0, sizeof tL);
		memset(tR, 0, sizeof tR);
		int l = 0, r = 0;
		rep (i, 0, n - 1) if (b[i] ^ 48) { l = i; break; }
		_rep (i, n - 1, 0) if (b[i] ^ 48) { r = i; break; }
		tL[0] = b[0] ^ 48 ? 0 : n - r;
		rep (i, 1, n - 1) tL[i] = b[i] ^ 49 ? tL[i - 1] + 1 : 0;
		tR[n] = l;
		_rep (i, n - 1, 0) tR[i] = b[i] ^ 49 ? tR[i + 1] + 1 : 0;
		ans = min(ans, calc(i));
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	rep (i, 0, n - 1) {
		memset(tL, 0, sizeof tL);
		memset(tR, 0, sizeof tR);
		int l = 0, r = 0;
		rep (i, 0, n - 1) if (b[i] ^ 48) { l = i; break; }
		_rep (i, n - 1, 0) if (b[i] ^ 48) { r = i; break; }
		tL[0] = b[0] ^ 48 ? 0 : n - r;
		rep (i, 1, n - 1) tL[i] = b[i] ^ 49 ? tL[i - 1] + 1 : 0;
		tR[n] = l;
		_rep (i, n - 1, 0) tR[i] = b[i] ^ 49 ? tR[i + 1] + 1 : 0;
		ans = min(ans, calc(i));
	}
	print(ans), puts("");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	ignore = freopen("ring.in", "r", stdin);
	ignore = freopen("ring.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T --> 0) solve();
	return 0;
}
