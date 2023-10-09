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

const ll MAXN = 5e5 + 5;
const ll baseSub2 = ((1 << 20) - 1);
const ll maxBase = ((1 << 30) - 1);
ll k, n, s[MAXN];
bool flgSub2 = 1;
bitset <MAXN> vis[35], tmp;
priority_queue <pair <ll, tuple <int, int, int> > > q;
vector <pair <ll, tuple <int, int, int> > > ans;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("afo.in", "r", stdin);
	freopen("afo.out", "w", stdout);
#endif
#endif
	cin >> n >> k;
	rep (i, 1, n) {
		cin >> s[i];
		if (s[i] > baseSub2) flgSub2 = 0;
	}
	if (n == 1) {
		cout << ((1 << 30) - 1);
		return 0;
	}
	if (flgSub2) {
		rep (i, 1, k) cout << i * (1 << 20) + baseSub2 << " ";
		return 0;
	}
	rep (i, 0, 29) {
		rep (j, 1, n) {
			if (s[j] & (1 << i)) vis[i][j] = 1;
		}
	}
	q.push({maxBase, {-1, -1, -1}});
	rep (i, 0, 29) {
		q.push({(ll) n - (ll) vis[i].count(), {i, -1, -1}});
	}
	rep (i, 0, 29) {
		rep (j, i + 1, 29) {
			tmp = vis[i] | vis[j];
			q.push({(ll) n - (ll) tmp.count(), {i, j, -1}});
		}
	}
	rep (i, 0, 29) {
		rep (j, i + 1, 29) {
			rep (l, j + 1, 29) {
				tmp = vis[i] | vis[j] | vis[l];
				q.push({(ll) n - (ll) tmp.count(), {i, j, l}});
			}
		}
	}
	rep (i, 1, k) {
		ans.emplace_back(q.top());
		q.pop();
	}
	for (auto x : ans) {
		int i, j, l;
		tie(i, j, l) = x.second;
		ll res = maxBase;
		if (i != -1) res -= (1 << i);
		if (j != -1) res -= (1 << j);
		if (l != -1) res -= (1 << l);
		cout << res << " ";
	}
	return 0; 
}
