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

const int MAXN = 205;
int n, k;
int a[MAXN], b[MAXN];
int prefa[MAXN], suffa[MAXN], prefb[MAXN], suffb[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("diameter.in", "r", stdin);
	freopen("diameter.out", "w", stdout);
#endif
#endif
	read(n), read(k);
	++n;
	rep (i, 1, n - 1) read(a[i]);
	rep (i, 1, n - 1) read(b[i]);
	rep (i, 2, n) prefa[i] = prefa[i - 1] + a[i - 1];
	_rep (i, n - 1, 1) suffa[i] = suffa[i + 1] + a[i];
	rep (i, 2, n) prefb[i] = prefb[i - 1] + b[i - 1];
	_rep (i, n - 1, 1) suffb[i] = suffb[i + 1] + b[i];

	int ans = 1e18;
	if (k == 1) {
		rep (i, 1, n) {
			ans = min(ans, max(max(max(prefa[n], suffa[i] + suffb[i]), prefa[i] + prefb[i]), max(prefb[n], max(prefa[i] + suffb[i], prefb[i] + suffa[i]))));
		}
		cout << ans;
		return 0;
	}
	rep (i, 1, n) {
		rep (j, i + 1, n) {
			ans = min(ans, max(
				min(prefa[n], prefa[i] + prefb[j] - prefb[i] + suffa[j]),
				max(
					min(prefb[n], prefb[i] + prefa[j] - prefa[i] + suffb[j]),
					max(
						max(
							min(prefa[j] + suffb[j], prefa[i] + suffb[i]),
							min(prefb[j] + suffa[j], prefb[i] + suffa[i])
						),
						max(prefa[i] + prefb[i], suffa[j] + suffb[j])
					)
				)
			));
		}
	}
	cout << ans;
	return 0;
}
