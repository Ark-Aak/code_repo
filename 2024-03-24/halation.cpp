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

const int MAXN = 2e5 + 5, N = 1e5;
int n, q, b[MAXN], k, r, pre[MAXN], t[MAXN];

signed main() {
	n = read(), q = read();
	int tp = n, sum = 0;
	rep (i, 1, N) {
		if (!tp) break;
		int x = min(tp, (i + 1) / 2);
		if (x == tp) k = i - 1, r = x;
		tp -= x, sum += x * i;
	}
	print(sum), puts("");
	rep (i, 0, k) pre[i] = (k - i + 1) / 2;
	int ttp = k;
	_rep (i, r, 1) pre[ttp]++, ttp -= 2;
	rep (i, 0, k) t[i] = pre[i];
	rep (i, 1, k) pre[i] += pre[i - 1];
	rep (i, 1, q) {
		int ans = 0, p = read(), pos = lower_bound(pre, pre + k + 1, p) - pre;
		pos = max(0ll, pos - 3);
		if (pos > 0) p -= pre[pos - 1];
		rep (i, pos, N) {
			if (p > 2 * t[i] - 1) p -= t[i];
			else {
				if (p & 1) {
					ans = p + i;
					break;
				}
				else p /= 2;
			}
		}
		print(ans), puts("");
	}
	return 0;
}
