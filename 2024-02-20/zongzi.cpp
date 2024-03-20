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

const int MAXN = 6e5 + 5;
int n, a[MAXN];
map <int, int> mp;
unordered_map <int, int> v[MAXN];
int id[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	/* freopen("zongzi.in", "r", stdin); */
	/* freopen("zongzi.out", "w", stdout); */
#endif
#endif
	n = read();
	rep (i, 1, 2 * n - 1) a[i] = read(), id[i] = i;
	sort(id + 1, id + 2 * n, [&](int x, int y) { return a[x] < a[y]; });
	int sum = 0;
	rep (i, 1, n) sum = (sum + a[id[i]]) % n;
	rep (i, 1, n) {
		mp[(a[id[i]] + n - sum) % n] = 1;
		v[1][(a[id[i]] + n - sum) % n] = id[i];
		if (a[id[i]] - n + sum < 0) continue;
		mp[a[id[i]] - n + sum] = 1;
		v[1][a[id[i]] - n + sum] = id[i];
	}
	if (sum == 0) {
		rep (i, 1, n) print(id[i]), putchar(32);
		return 0;
	}
	rep (i, 2, n) {
		int l = i, r = i + n - 1;
		sum -= a[id[l - 1]];
		sum = (sum + a[id[r]] + n) % n;
		if (sum == 0) {
			rep (i, l, r) {
				print(id[i]), putchar(32);
			}
			return 0;
		}
		if (mp[a[id[r]]]) {
			int L = mp[a[id[r]]];
			int val = v[L][a[id[r]]];
			bool flg = 1;
			rep (j, L, L + n - 1) {
				if (flg && id[j] == val) flg = 0, print(id[r]), putchar(32);
				else print(id[j]), putchar(32);
			}
			return 0;
		}
		mp[(a[id[r]] + n - sum) % n] = i;
		v[i][(a[id[r]] + n - sum) % n] = id[r];
		if (a[id[r]] - n + sum < 0) continue;
		mp[a[id[r]] - n + sum] = i;
		v[i][a[id[r]] - n + sum] = id[r];
	}
	return 0;
}
