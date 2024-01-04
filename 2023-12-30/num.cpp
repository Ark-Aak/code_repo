#include <bits/stdc++.h>

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

#define int ll

const int MAXN = 85;
int n, k, ans = 1e18;
int a[MAXN];

map <vector <int>, int> f[2];

signed main() {
	n = read(), k = read();
	if (n == k) return puts("0"), 0;
	rep (i, 1, n) a[i] = read();
	f[0][vector <int>(k + 1)] = 0;
	sort(a + 1, a + 1 + n);
	rep (i, 1, n) {
		f[i & 1].clear();
		for (auto [v, ans] : f[~i & 1]) {
			rep (j, 1, k) {
				if (v[j] >= n / k) continue;
				if (v[j] > v[0] && i > 1 && a[i] == a[i - 1]) continue;
				vector <int> s = v;
				int nans = ans; s[j]++;
				if (s[j] == 1) nans -= a[i];
				if (s[j] == n / k) nans += a[i];
				s[0] = -1e9;
				sort(s.begin(), s.end());
				s[0] = v[j];
				if (f[i & 1].count(s)) f[i & 1][s] = min(f[i & 1][s], nans);
				else f[i & 1][s] = nans;
			}
		}
	}
	for (auto [v, ans] : f[n & 1]) ::ans = min(::ans, ans);
	print(ans);
	return 0;
}
