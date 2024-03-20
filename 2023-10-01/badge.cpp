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

const int MAXN = 3e5 + 5;
int n, q, ans;
int vis[MAXN];
int l[MAXN], r[MAXN], tt[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("badge.in", "r", stdin);
	freopen("badge.out", "w" ,stdout);
#endif
#endif
	read(n), read(q);
	rep (i, 1, n) read(l[i]), read(r[i]);
	rep (i, 1, q) {
		int m;
		read(m);
		rep (j, 1, m) read(tt[j]), vis[tt[j]]++;;
		rep (j, 1, n) {
			int cnt = 0;
			rep (k, l[j], r[j]) cnt += vis[k];
			if (cnt & 1) ans++;
		}
		cout << ans << endl;
		rep (j, 1, m) vis[tt[j]]--;
		ans = 0;
	}
	return 0; 
}
