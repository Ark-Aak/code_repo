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

const int MAXN = 2.5 * 1e5;
struct point {
	int x, y, c;
} p[MAXN];
int n;
map <int, int> _Ref;
map <int, int> _Bck;
vector <int> num;
map <int, bool> vis;
int val[5005][5005];
int pref[5005][5005];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("imp.in", "r", stdin);
	freopen("imp.out", "w", stdout);
#endif
#endif
	cin >> n;
	rep (i, 1, n) cin >> p[i].x >> p[i].y >> p[i].c, num.emplace_back(p[i].x), num.emplace_back(p[i].y);
	sort(num.begin(), num.end());
	int cnt = 0;
	for (auto x : num) {
		if (vis[x]) continue;
		vis[x] = 1;
		_Ref[x] = ++cnt;
		_Bck[cnt] = x;
	}
	rep (i, 1, n) {
		val[_Ref[p[i].x]][_Ref[p[i].y]] += p[i].c;
	}
	rep (i, 1, cnt) {
		rep (j, 1, cnt) {
			pref[i][j] = val[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}
	int ans = 0;
	rep (i, 1, cnt) {
		rep (j, i, cnt) {
			//(i, i), (j, j)
			int t = pref[j][j] - pref[i - 1][j] - pref[j][i - 1] + pref[i - 1][i - 1];
			int tans = (t - _Bck[j] + _Bck[i]);
			if (tans > ans) {
				ans = tans;
			}
		}
	}
	cout << ans;
	return 0;
}
