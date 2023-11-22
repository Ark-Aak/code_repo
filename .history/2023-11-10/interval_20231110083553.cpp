#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MAXN = 5e5 + 5;
int n, a[MAXN], st[MAXN][21];

int query(int u, int v) {
	int l = log2(v - u + 1);
	return __gcd(st[u][l], st[v - (1 << l) + 1][l]);
}

vector <int> ans;
int mx = -1;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
    freopen("interval.in", "r", stdin);
    freopen("interval.out", "w", stdout);
#endif
#endif
	read(n);
	rep (i, 1, n) read(a[i]);
	rep (i, 1, n) st[i][0] = a[i];
	rep (j, 1, log2(n)) {
		rep (i, 1, n - (1 << j) + 1) {
			st[i][j] = __gcd(st[i + (1 << (j - 1))][j - 1], st[i][j - 1]);
		}
	}
	rep (k, 1, n) {
		int l = 1, r = k, mid = (l + r) >> 1;
		while (l < r) {
            mid = (l + r) >> 1;
    		if (query(mid, k) % a[k] == 0) r = mid;
			else l = mid + 1;
		}
		int L = mid;
		l = k, r = n, mid = (l + r) >> 1;
		while (l < r) {
			mid = (l + r) >> 1;
			if (query(k, mid) % a[k] == 0) l = mid + 1;
			else r = mid;
		}
		int R = mid;
		if (R - L > mx) {
			ans.clear();
			mx = R - L;
		}
		if (R - L == mx) {
			ans.emplace_back(L);
			cout << L << " " << R;
		}
	}
	print(ans.size()), putchar(32), print(mx), putchar(10);
	for (auto x : ans) print(x), putchar(32);
	return 0;
}
