#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define ec first
#define fb second
#define de(x) cerr << #x << " = " << (x) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, w = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + (ch ^ 48);
		ch = getchar();
	}
	return x * w;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

const int MAXN = 2005;
int x, k, n, q;
int a[MAXN], b[MAXN], c[MAXN];

struct line {
	double k, b;

	line() { k = 0; b = 0; }

	line(int st, int ed) {
		k = 1.0 * (ed - st) / x;
		b = st;
	}

	double crossAt(line &t) {
		//k1x+b1 = k2x+b2
		//x = (b2-b1)/(k1-k2)
		return (t.b - b) / (k - t.k);
	}

	double at(double x) { return k * x + b; }
} l[MAXN];

map <double, vector <int> > mp[MAXN];

signed main() {
#ifndef LOCAL
	freopen("raid.in", "r", stdin);
	freopen("raid.out", "w", stdout);
#endif
	x = read(), k = read(), n = read(), q = read();
	rep (i, 1, n) {
		a[i] = read(), b[i] = read(), c[i] = read();
		l[i] = line(a[i], b[i]);
	}
	rep (i, 1, n) {
		rep (j, 1, n) {
			if (i == j) continue;
			int symbolA = (a[i] - a[j]) > 0;
			int symbolB = (b[i] - b[j]) > 0;
			if (symbolA == symbolB) continue;
			mp[i][l[i].crossAt(l[j])].push_back(j);
		}
	}
	while (q --> 0) {
		int p = read(), s = read();
		int fans = 0;
		for (double i = s; i <= s + k; i += 1e-5) {
			int ans = 0;
			map <double, int> vis;
			rep (j, 1, n) {
				if (j == p) continue;
				if (!vis[l[j].at(i)] && l[j].at(i) > l[p].at(i)) {
					vis[l[j].at(i)] = c[j];
					ans += c[j];
				}
				else if (l[j].at(i) > l[p].at(i)) {
					if (c[j] > vis[l[j].at(i)]) {
						ans += c[j] - vis[l[j].at(i)];
						vis[l[j].at(i)] = c[j];
					}
				}
			}
			fans = max(ans, fans);
		}
		print(fans), puts("");
	}
	return 0;
}
