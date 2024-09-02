#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
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

const int MAXN = 2e5 + 5;
int T, n, k, a[MAXN], isp[MAXN];
int sum[MAXN], id[MAXN];

bool check(int x) {
	set <int> s;
	int cnt = 0;
	rep (i, 1, n) {
		if (!s.size()) { s.insert(i); continue; }
		bool flg = 0;
		rep (j, 1, n) {
			int v = id[j];
			if (sum[i] - sum[v] < x) break;
			if (i <= v) continue;
			if (s.find(v) == s.end()) continue;
			if (!isp[i - j]) continue;
			flg = 1;
			s.clear();
			++cnt;
		}
		if (cnt == k) return 1;
		if (!flg) s.insert(i);
	}
	return 0;
}

void solve() {
	n = read(), k = read();
	rep (i, 1, n) a[i] = read(), sum[i] = sum[i - 1] + a[i];
	rep (i, 1, n) id[i] = i;
	sort(id + 1, id + 1 + n, [&](int a, int b) { return sum[a] < sum[b]; });
	int l = -1e9, r = 1e9;
	int ans = -1e9;
	while (l <= r) {
		int mid = l + ((r - l) >> 1);
		if (check(mid)) ans = max(ans, mid), l = mid + 1;
		else r = mid - 1;
	}
	print(ans), puts("");
}

signed main() {
	fill(isp + 1, isp + 1 + 200000, 1);
	isp[1] = 0;
	rep (i, 2, 200000) {
		for (int j = i * 2; j <= 200000; j += i) {
			isp[j] = 0;
		}
	}
	T = read();
	while (T --> 0) solve();
	return 0;
}
