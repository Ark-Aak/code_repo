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

const int MAXN = 1e3 + 5;
int n, l[MAXN], r[MAXN], c[MAXN], ord[MAXN];
int val[MAXN], ans, dead[MAXN];

bool flg = 1;

mt19937 rnd(time(0));

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
#endif
#endif
	cin >> n;
	rep (i, 1, n) {
		cin >> l[i] >> r[i] >> c[i];
		if (l[i] != r[i]) flg = 0;
	}
	rep (i, 1, n) ord[i] = i;
	if (n <= 10) {
		do {
			memset(val, 0, sizeof val);
			memset(dead, 0, sizeof dead);
			rep (i, 1, n) {
				dead[ord[i]] = 1;
				rep (j, l[ord[i]], r[ord[i]]) {
					if (!dead[j]) val[j] += c[ord[i]];
				}
			}
			int sum = 0;
			rep (i, 1, n) sum += val[i];
			ans = max(ans, sum);
		} while (next_permutation(ord + 1, ord + 1 + n));
		print(ans);
	}
	else {
		do {
			shuffle(ord + 1, ord + 1 + n, rnd);
			memset(val, 0, sizeof val);
			memset(dead, 0, sizeof dead);
			rep (i, 1, n) {
				dead[ord[i]] = 1;
				rep (j, l[ord[i]], r[ord[i]]) {
					if (!dead[j]) val[j] += c[ord[i]];
				}
			}
			int sum = 0;
			rep (i, 1, n) sum += val[i];
			ans = max(ans, sum);//1e6 次运算 -> 0.05s
		} while ((double) clock() / CLOCKS_PER_SEC < 1.95);
		print(ans);
	}
	return 0;
}
