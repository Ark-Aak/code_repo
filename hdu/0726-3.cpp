#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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

#define int ll

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

int T;
int n, m;

void solve() {
	n = read(), m = read();
	set <pii> s;
	int isBad = 0, mx = 1e9, ps = 1e9, lst = -1;
	/* de(n), de(m); */
	rep (i, 1, m) {
		int op = read();
		if (op == 0) {
			int p = read(), q = read();
			if (p - 1 > q) { isBad = 1; continue; }
			if (p > 1) {
				ps = min(ps, q);
				mx = min(mx, q - p + 1);
			}
			auto iter = s.insert(dl(q, p)).ec;
			if (iter != s.begin() && next(iter) != s.end() && lst == next(iter) -> ec) lst = -1;
			if (iter != s.begin()) {
				auto it = *prev(iter);
				if (((it.ec + it.fb) ^ (iter -> ec + iter -> fb)) & 1) lst = max(lst, q);
				if (abs(it.fb - p) > abs(it.ec - q)) { isBad = 1; continue; }
			}
			if (next(iter) != s.end()) {
				auto it = *next(iter);
				if (((it.ec + it.fb) ^ (iter -> ec + iter -> fb)) & 1) lst = max(lst, it.ec);
				if (abs(it.fb - p) > abs(it.ec - q)) { isBad = 1; continue; }
			}
			if (lst > ps) { isBad = 1; continue; }
		}
		if (op == 1) {
			/* de(s.size()); */
			/* de(lst); */
			if (isBad) { puts("bad"); continue; }
			if (!(~lst)) {
				if (!s.size()) { puts("0"); continue; }
				print((s.begin() -> ec + s.begin() -> fb + 1) & 1);
				puts("");
			}
			else print(prev(s.lower_bound(dl(lst, 0))) -> ec + 1), puts("");
		}
		if (op == 2) {
			if (isBad) { puts("bad"); continue; }
			if (mx == 1e9) { puts("inf"); continue; }
			print(mx), puts("");
		}
	}
}

signed main() {
	T = read();
	while (T --> 0) solve();
	return 0;
}
