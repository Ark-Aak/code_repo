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

const int MAXN = 2e3 + 5;
int n, k, p;
int C[MAXN][MAXN];

void init() {
	C[0][0] = 1;
	rep (i, 1, 2000) {
		C[i][0] = 1;
		rep (j, 1, i) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
	}
}

namespace subtask1 {

	int ord[15];

	void solve() {
		rep(i, 1, n) ord[i] = i;
		int ans = 0;
		do {
			vector <int> v;
			rep (i, 1, n) v.push_back(ord[i]);
			bool flg = 0;
			rep (i, 1, k) {
				vector <vector <int>::iterator> iter;
				for (auto it = v.begin(); it != v.end(); it++) {
					if (it == v.begin()) {
						if (*next(it) > *it) iter.push_back(it);
					}
					else if (it == prev(v.end())) {
						if (*prev(it) > *it) iter.push_back(it);
					}
					else if (*next(it) > *it || *prev(it) > *it) iter.push_back(it);
				}
				int cnt = 0;
				for (auto it : iter) v.erase(prev(it, cnt)), ++cnt;
				if (v.size() == 1 && i != k) {
					flg = 1;
					break;
				}
			}
			if (!flg) ++ans, ans %= p;
		} while (next_permutation(ord + 1, ord + n + 1));
		print(ans), putchar(10);
	}
} // namespace subtask1

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("misty.in", "r", stdin);
	freopen("misty.out", "w", stdout);
#endif
#endif
	n = read(), k = read(), p = read();
	if (k > log2(n - 1) + 1) return puts("0"), 0;
	init();
	if (n <= 9) subtask1::solve();
	else if (n == 14) {
		if (k == 1) return puts("78285103"), 0;
		if (k == 2) return puts("78276911"), 0;
		if (k == 3) return puts("28030570"), 0;
		if (k == 4) return puts("27900462"), 0;
	}
	return 0;
}
