#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

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

const int MAXN = 1e6 + 5;
int T, n, d[MAXN];

int solve(vector <int> &s, bool flg) {
	int siz = s.size();
	if (siz == 1) {
		int *buc = new int[20], cnt = 0;
		rep (i, 0, 9) if (s[0] >> i & 1) buc[++cnt] = i;
		if (!cnt) return delete[] buc, !flg;
		int tmp = 0;
		if (cnt == 1) return tmp = (buc[1] ? buc[1] : 10), delete[] buc, tmp;
		if (!buc[1]) swap(buc[1], buc[2]);
		rep (i, 1, cnt) tmp = tmp * 10 + buc[i];
		delete[] buc;
		return tmp;
	}
	if (flg && !s[0]) {
		bool f = 1;
		rep (i, 1, s.size() - 1) {
			int x = i, sum = 0;
			while (x) sum |= 1 << x % 10, x /= 10;
			if ((s[i] & sum) != s[i]) { f = 0; break; }
		}
		if (f) return 0;
	}
	int ans = 1e18;
	rep (i, 0, 9) {
		if (s.size() == 2 && i == 9 && (s[0] & ~(1 << 9)) == s[0] && (s[1] & ~1) == s[1]) continue;
		vector <int> t;
		int sum = 0;
		int u = i;
		for (auto val : s) {
			if (u == 10) t.push_back(sum), sum = 0, u = 0;
			sum |= val & ~(1 << u);
			u++;
		}
		t.push_back(sum);
		ans = min(ans, solve(t, i > 0) * 10 + i);
	}
	return ans;
}

void _solve() {
	cin >> n;
	vector <int> s;
	string str;
	cin >> str;
	for (auto ch : str) s.push_back(1 << (ch - 48));
	cout << solve(s, 0) << "\n";
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("pulse.in", "r", stdin);
	freopen("pulse.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T --> 0) _solve();
	return 0;
}
