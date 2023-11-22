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

const int MAXN = 1e6 + 5;
int T;
int n, k;
int s[MAXN], b[MAXN], a[MAXN];
int sum[MAXN];

int lowbit(int x) {
	return x & -x;
}

void add(int x, int val) {
	++x;
	while (x <= k) {
		sum[x] += val;
		x += lowbit(x);
	}
}

int query(int x) {
	++x;
	int res = 0;
	while (x) {
	cout << x << endl;
		res += sum[x];
		x -= lowbit(x);
	}
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("fang.in", "r", stdin);
	freopen("fang.out", "w", stdout);
#endif
#endif
	read(T);
	rep (__, 1, T) {
		memset(sum, 0, sizeof sum);
		read(n), read(k);
		int ans = 0;
		rep (i, 1, n) {
			int st = (i * i + 1) % k;
			int ed = st + i - 1;
			assert(st >= 0);
			if (ed < k) {
				add(st, 1);
				add(ed + 1, -1);
			}
			else {
				add(st, 1);
				add(k, -1);
				add(0, (ed + 1) / k - 1);
				add(k, -((ed + 1) / k - 1));
				add(0, 1);
				add((ed + 1) % k, -1);
			}
			int CNMCTR = i * i % k * i % k;
			ans += query(CNMCTR);
		}
		cout << "Case " << __ << ": " << ans << endl;
	}
	return 0;
}