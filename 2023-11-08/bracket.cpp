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

const int MAXN = 400005;
int T, n;
string s[MAXN];
int val[MAXN][2], f[MAXN], ans;

pair <int, int> calc(string s) {
	int lans = 0, rans = 0;
	stack <char> S;
	for (auto c : s) {
		if (c == '(') S.push(c);
		else {
			if (S.empty()) rans++;
			else S.pop();
		}
	}
	lans = S.size();
	return make_pair(lans, rans);
}

bool flg[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
#endif
#endif
	cin >> T;
	while (T --> 0) {
		cin >> n;
		memset(f, 0, sizeof f);
		memset(flg, 0, sizeof flg);
		ans = 0;
		f[0] = 1; flg[0] = 1;
		vector <pair <int, int> > pos;
		rep (i, 1, n) {
			cin >> s[i];
			auto x = calc(s[i]);
			val[i][0] = x.first, val[i][1] = x.second;
		}
		rep (i, 1, n) {
			vector <pair <int, int> > mdflst;
			rep (j, val[i][1], 4000) {
				if (flg[j]) mdflst.emplace_back(make_pair(j + val[i][0] - val[i][1], f[j] % 998244353));
			}
			rep (j, val[i][1], 4000) {
				if (flg[j]) flg[j + val[i][0] - val[i][1]] = 1;
			}
			for (auto x : mdflst) {
				f[x.first] += x.second;
				f[x.first] %= 998244353;
			}
		}
		print(f[0] % 998244353), putchar(10);
	}
	return 0;
}
