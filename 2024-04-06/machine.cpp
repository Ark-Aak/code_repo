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

const int MAXN = 705;
int n, m, Q, a[MAXN];
string s;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("machine.in", "r", stdin);
	freopen("machine.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	rep (i, 1, m) cin >> a[i];
	cin >> Q;
	while (Q --> 0) {
		int l, r;
		cin >> l >> r;
		string str;
		str = s;
		rep (i, l, r) {
			int ps = a[i];
			str[ps] = 'R';
			while (ps <= n && ps >= 1) {
				if (str[ps] == 'R') {
					str[ps] = 'B';
					ps++;
				}
				else {
					str[ps] = 'R';
					ps--;
				}
			}
		}
		int cnt = 0;
		for (auto c : str) if (c == 'R') cnt++;
		cout << cnt << "\n";
	}
	return 0;
}
