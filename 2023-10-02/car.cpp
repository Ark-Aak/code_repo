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

int m, t, n, q;
vector <int> G[3];
ll f[3][500005];

ll dist(int x, int y) {
	return max(0, y - x - m);
}

ll calc(int k, int x) {
	int iter = lower_bound(G[k].begin(), G[k].end(), x) - G[k].begin();
	return f[k][iter] + dist(x, G[k][iter]);
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("car.in", "r", stdin);
	freopen("car.out", "w", stdout);
#endif
#endif
	read(m), read(t), read(n), read(q);
	rep (i, 1, n) {
		int op, tt;
		string s;
		cin >> op >> s;
		if (s[1] == 'M') tt = 3;
		else if (s[1] == 'N') tt = 2;
		else tt = 1;
		if (op < t) rep (j, 0, tt - 1) G[j].emplace_back(op);
	}
	rep (i, 0, 2) {
		G[i].emplace_back(t);
		sort(G[i].begin(), G[i].end());
		_rep (j, (int) (G[i].size()) - 2, 0) {
			f[i][j] = f[i][j + 1] + dist(G[i][j], G[i][j + 1]);
		}
	}
	while (q --> 0) {
		int x;
		cin >> x;
		if (calc(0, x)) cout << "-1\n";
		else cout << calc(1, x) << " " << calc(2, x) - calc(1, x) << "\n";
	}
	return 0; 
}
