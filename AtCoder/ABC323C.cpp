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

int n, m, v[105], ans[105];
struct node {
	int val, id;
	bool operator < (const node &t) const {
		return val > t.val;
	}
} nd[105];
string s[105];

int main() {
	cin >> n >> m;
	rep (i, 1, m) cin >> nd[i].val, nd[i].id = i, v[i] = nd[i].val;
	sort(nd + 1, nd + 1 + n);
	int mx = 0;
	rep (i, 1, n) {
		cin >> s[i];
		int ans = i;
		rep (j, 0, s[i].size() - 1) {
			ans += (s[i][j] == 'o' ? v[j + 1] : 0);
		}
		mx = max(ans, mx);
		::ans[i] = ans;
	}
	rep (i, 1, n) {
		if (ans[i] == mx) cout << 0 << endl;
		else {
			int t = mx - ans[i];
			int cnt = 0, tans = 0;
			rep (j, 1, n) {
				if (cnt < t && s[i][nd[j].id - 1] == 'x') cnt += nd[j].val, tans++;
			}
			cout << tans << endl;
		}
	}
	return 0; 
}
