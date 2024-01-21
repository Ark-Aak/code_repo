#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

const int MAXN = 500005;
int n, w[MAXN];

struct ele {
	int w, a, b;

	bool operator < (const ele &t) const {
		return w != t.w ? w > t.w : a != t.a ? a > t.a : b > t.b;
	}
};

int lowbit(int x) {
	return x & -x;
}

bool vis[705];
vector <ele> s;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("outing.in", "r", stdin);
	freopen("outing.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) w[i] = read();
	if (n <= 700) {
		rep (j, 1, n) {
			rep (k, 1, n) {
				if (j == k) continue;
				int val = lowbit(w[j] ^ w[k]);
				int cnt = 0;
				while (val > 1) cnt++, val >>= 1;
				s.push_back((ele) {cnt, j, k});
			}
		}
		sort(s.begin(), s.end());
		rep (i, 1, n) {
			memset(vis, 0, sizeof vis);
			int ans = 0;
			vis[i] = 1;
			for (auto e : s) {
				int a = e.a, b = e.b;
				if (vis[a] || vis[b]) continue;
				vis[a] = 1, vis[b] = 1;
				ans ^= (w[a] ^ w[b]) - 1;
			}
			rep (j, 1, n) if (!vis[j] && j != i) ans ^= w[j];
			print(ans), putchar(32);
		}
	}
	else {
		_rep (i, n - 1, 0) print(i), putchar(32);
	}
	return 0;
}
