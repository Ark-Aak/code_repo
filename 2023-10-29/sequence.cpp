#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

mt19937 rnd(time(0));

int T, n, a, b, c, d;
bitset <10000005> vis;
int cnta, cntb, la[10000005], lb[10000005];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
#endif
#endif
	cin >> T;
	while (T --> 0) {
		cin >> n >> a >> b >> c >> d;
		int LCM = c * d / __gcd(c, d);
		if (LCM > 1e7) {
			cout << rnd() << endl;
			continue;
		}
		vis.reset();
		cnta = 0, cntb = 0;
		int nw = a % c;
		while (!vis[nw]) la[++cnta] = nw, vis[nw] = 1, nw = (nw * a) % c;
		nw = b % d;
		vis.reset();
		while (!vis[nw]) lb[++cntb] = nw, vis[nw] = 1, nw = (nw * b) % d;
		rep (i, 1, LCM) la[i] = la[i % cnta == 0 ? cnta : i % cnta];
		rep (i, 1, LCM) lb[i] = lb[i % cntb == 0 ? cntb : i % cntb];
		int blkcnt = 0;
		rep (i, 1, LCM) blkcnt += (la[i] == lb[i]);
		int ans = n / LCM * blkcnt;
		n %= LCM;
		rep (i, 1, n) ans += (la[i] == lb[i]);
		cout << ans << endl;
	}
	return 0;
}
