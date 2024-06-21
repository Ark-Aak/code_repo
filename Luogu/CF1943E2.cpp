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
int T, m, k;
int f[MAXN], g[MAXN], id[MAXN];
int h[MAXN], pre[MAXN];

bool check(int p) {
	int cnt = 0;
	rep (i, 0, m) {
		if (id[i] <= p) {
			h[cnt] = f[id[i]];
			pre[cnt] = cnt ? pre[cnt - 1] : 0;
			pre[cnt] += h[cnt];
			cnt++;
		}
	}
	if (h[0] == 0) return 1;
	int ptr = 1;
	rep (i, 1, p) {
		while ((pre[i] - pre[ptr - 1] - ptr * k) / (i - ptr + 1) > h[ptr]) ptr++;
		if ((pre[i] - pre[ptr - 1] - ptr * k) <= g[i - ptr + 1]) return 1;
	}
	return 0;
}

void solve() {
	m = read(), k = read();
	rep (i, 0, m) f[i] = read();
	rep (i, 0, m) id[i] = i;
	sort(id, id + 1 + m, [=](int a, int b) { return f[a] < f[b]; });
	rep (i, 2, m + 1) {
		int x = g[i - 1] + k;
		g[i] = x + (x / (i - 1));
	}
	int L = 0, R = m + 1, mid = 0;
	while (L < R) {
		mid = (L + R) >> 1;
		if (check(mid)) R = mid;
		else L = mid + 1;
	}
	print(L), puts("");
}

signed main() {
	T = read();
	while (T --> 0) solve();
	return 0;
}
