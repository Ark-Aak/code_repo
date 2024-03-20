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

int n, m;
multiset <int> s[2][2];

vector <pii> l[2];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("derby.in", "r", stdin);
	freopen("derby.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	rep (i, 1, n) {
		int op, v;
		read(op), read(v);
		s[0][op].insert(v);
		l[0].push_back({op, v});
	}
	rep (i, 1, m) {
		int op, v;
		read(op), read(v);
		s[1][op].insert(v);
		l[1].push_back({op, v});
	}
	int ans = 0;
	sort(l[0].begin(), l[0].end(), [](pii a, pii b) {
		return a.second > b.second;
	});
	for (auto v : l[0]) {
		int op = v.first, val = v.second;
		if (op) {
			if (s[1][!op].size() == 0) continue;
			auto iter = s[1][!op].lower_bound(val);
			if (iter == s[1][!op].begin()) continue;
			iter--;
			ans += val + (*iter);
			s[1][!op].erase(iter);
		}
		else {
			if (s[1][!op].size() == 0) continue;
			auto iter = s[1][!op].rbegin();
			if ((*iter) <= val) continue;
			ans += val + (*iter);
			s[1][!op].erase(s[1][!op].lower_bound(*iter));
		}
	}
	cout << ans << endl;
	return 0;
}
