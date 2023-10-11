#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

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

const int MAXN = 1e3 + 5;
int n, m, q;
vector <pair <int, int> > G[MAXN];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("journey.in", "r", stdin);
	freopen("journey.out", "w", stdout);
#endif
#endif
	read(n), read(m), read(q);
	rep (i, 1, m) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(make_pair(v, i));
		G[v].emplace_back(make_pair(u, i));
	}
	rep (i, 1, q) {
		int l, r, s, t;
		read(l), read(r), read(s), read(t);
		if (s == t) cout << "Yes\n";
		else {
			bool flg = 0;
			for (auto v : G[s]) {
				if (v.first == t && v.second == l) {
					flg = 1, cout << "Yes\n";
					break;
				}
			}
			if (!flg) cout << "No\n";
		}
	}
	return 0; 
}
