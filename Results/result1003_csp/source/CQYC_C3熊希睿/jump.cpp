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

const int MAXN = 5e5 + 5;
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;
int ans[MAXN], a[MAXN], fa[MAXN], n;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
#endif
#endif
	a[0] = INT_MAX;
	read(n);
	rep (i, 1, n) read(a[i]);
	_rep (i, n, 0) {
		while ((!q.empty()) && q.top().first < a[i]) {
			auto x = q.top(); q.pop();
			fa[x.second] = i;
		}
		q.push(make_pair(a[i], i));
	}
	rep (i, 1, n) ans[i] = ans[fa[i]] + 1;
	rep (i, 1, n) print(ans[i]), putchar(32);
	return 0; 
}
