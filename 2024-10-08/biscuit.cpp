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
int n, m, k;
int a[MAXN];
multiset <int> p;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("biscuit.in", "r", stdin);
	freopen("biscuit.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), k = read();
	rep (i, 1, n) a[i] = read();
	sort(a + 1, a + 1 + n);
	int sum = 0, lst = 0;
	_rep (i, n, 1) {
		if (sum + a[i] <= m) {
			sum += a[i];
			lst = i;
		}
		else break;
	}
	int r = m - sum;
	rep (i, 1, lst - 1) {
		p.insert(a[i]);
		// cerr << i << endl;
	}
	// cerr << "???" << endl;
	while (p.size() && k && (*p.rbegin())) {
		int val = *p.rbegin();
		p.erase(p.find(val));
		p.insert(val - 1);
		k--;
		// cerr << k << endl;
	}
	int pt = 1;
	for (auto v : p) {
		a[pt++] = v;
	}
	// rep (i, 1, n) cerr << a[i] << " ";
	// cerr << endl;
	ll ans = 0;
	rep (i, 1, lst - 1) {
		ans += 1ll * (1ll + a[i]) * a[i] / 2;
		if (i == lst - 1) {
			ans -= 1ll * (1ll + r) * r / 2;
		}
	}
	print(ans), puts("");
	return 0;
}
