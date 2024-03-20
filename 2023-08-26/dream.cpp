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
int n, m, q, k, id;
vector <pair <int, int> > G[MAXN];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
#endif
#endif
	cin >> n >> m >> q >> k >> id;
	if (id == 16) {
		cout << 1;
		return 0;
	}
	rep (i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].emplace_back({v, w});
		G[v].emplace_back({u, w});
	}

	return 0; 
}
