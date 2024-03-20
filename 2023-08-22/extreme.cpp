#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= b; i++)
#define _rep(i, a, b) for(int i = (a); i >= b; i--)

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 1e5 + 5;
const int MOD = 998244353;
ll T, n, a[MAXN], ans;
vector <pair <ll, ll> > cur, _cur;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("extreme.in", "r", stdin);
	freopen("extreme.out", "w", stdout);
#endif
#endif
	cin >> T;
	while (T --> 0) {
		ans = 0;
		cin >> n;
		rep (i, 1, n) cin >> a[i];
		cur.clear(), _cur.clear();
		_rep (i, n, 1) {
			_cur.emplace_back(make_pair(a[i], 1));
			for (auto x : cur) {
				ll se = x.second, nxt = (a[i] + x.first - 1) / x.first;
				ll t = a[i] / nxt, _ans = (nxt - 1) * (se * i % MOD) % MOD;
				ans += _ans; ans %= MOD;
				_cur.emplace_back(make_pair(t, se));
			}
			cur.clear(); sort(_cur.begin(), _cur.end());
			ll cnt = 0;
			rep (i, 0, _cur.size() - 1) {
				cnt += _cur[i].second % MOD; cnt %= MOD;
				if (i == _cur.size() - 1 || _cur[i].first != _cur[i + 1].first) {
					cur.emplace_back(make_pair(_cur[i].first, cnt));
					cnt = 0;
				}
			}
			_cur.clear();
		}
		cout << ans << endl;
		cur.clear();
	}
	return 0; 
}
