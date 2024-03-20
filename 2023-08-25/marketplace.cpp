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

const int MAXN = 1e5 + 5, MAXM = 1e6 + 5;
int a[MAXN], b[MAXN], ans[MAXN];
bitset <MAXM> vis;
int n, m;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("marketplace.in", "r", stdin);
	freopen("marketplace.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	rep (i, 1, n) {
		read(a[i]), read(b[i]);
	}
	rep (i, 1, m) {
		vis.reset();
		bool flg = 0;
		while (!flg) {
			rep (j, 1, n) {
				if ((!vis[a[j]]) && a[j] != i) vis[a[j]] = 1;
				else if ((!vis[b[j]]) && b[j] != i) vis[b[j]] = 1;
				else {
					ans[j]++;
					flg = 1;
					break;
				}
			}
		}
	}
	rep (i, 1, n) {
		cout << ans[i] << endl;
	}
	return 0;
}
