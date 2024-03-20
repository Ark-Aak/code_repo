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

ll n, g, l, ans[25];
bitset <25> sel;

void dfs(ll step, ll G, ll L) {
	if (step > n) {
		if (G == g && L == l) {
			rep (i, 1, n) if (sel[i]) ans[i]++, ans[i] %= (int) (1e9 + 7);
		}
		return;
	}
	sel[step] = 1;
	bool flg = 0;
	if (G == -1) G = step, flg = 1;
	dfs(step + 1, __gcd(G, step), step * L / __gcd(step, L));
	if (flg) G = -1;
	sel[step] = 0;
	dfs(step + 1, G, L);
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("lcm.in", "r", stdin);
	freopen("lcm.out", "w", stdout);
#endif
#endif
	read(n), read(g), read(l);
	if (n <= 20) {
		dfs(1, -1, 1);
		int Q;
		read(Q);
		while (Q --> 0) {
			int x; read(x);
			print(ans[x]), putchar(10);
		}
	}
	return 0; 
}
