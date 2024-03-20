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

#define int ll

const int MAXN = 4e3 + 5;
int n;
bitset <MAXN> vis[MAXN];
int ans;
unordered_map <pair <int, int> , bool> mk;

int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("random.in", "r", stdin);
	freopen("random.out", "w", stdout);
#endif
#endif
	read(n);
	rep (i, 1, n) {
		rep (j, 1, n) {
			char c;
			scanf("%c", &c);
			if (c == '0') vis[i][j] = 0;
			else vis[i][j] = 1;
		}
	}
	rep (i, 1, n) {
		rep (j, 1, n) {
			if (vis[i][j]) {
				rep (k, 1, n) {
					if (vis[j][k] && vis[k][i] && mk[make_tuple(i, j, k)] == 0) {
						mk[make_tuple(i, j, k)] = 1;
						mk[make_tuple(j, k, i)] = 1;
						mk[make_tuple(k, i, j)] = 1;
					}
				}
				ans %= 998244353;
			}		
		}
	}
	print(ans % 998244353);
	return 0; 
}
