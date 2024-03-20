#include <bits/stdc++.h>

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

const int MAXN = 5e5 + 5;
const int MAXB = 32;
int n, q, a[MAXN];

struct Basis {

	int p[MAXB], pos[MAXB];

	void insert(int ps, int val) {
		_rep (i, 31, 0) {
			if (val >> i & 1) {
				if (!p[i]) return p[i] = val, pos[i] = ps, void();
				else if (pos[i] < ps) swap(pos[i], ps), swap(p[i], val);
				val ^= p[i];
			}
		}
	}

	int query(int l) {
		int ans = 0;
		_rep (i, 31, 0) if (pos[i] >= l)
			ans = max(ans, ans ^ p[i]);
		return ans;
	}
} pre[MAXN];

signed main() {
	n = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) {
		pre[i] = pre[i - 1];
		pre[i].insert(i, a[i]);
	}
	q = read();
	while (q --> 0) {
		int l = read(), r = read();
		print(pre[r].query(l)), putchar(10);
	}
	return 0;
}
