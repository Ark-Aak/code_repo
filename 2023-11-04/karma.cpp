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

const int MAXN = 2e5 + 5;
int n, m;
string str[MAXN];

int calc(string str) {
	int cnt = 0, ans = 0;
	rep (i, 0, (int) str.size() - 1) {
		if (str[i] == '1') ++cnt;
		else ans += cnt;
	}
	return ans;
}

namespace subtask1 {
	bitset <MAXN> vis;
	int ord[MAXN], ans = 1e9;
	string ansstr;
	void dfs(int step) {
		if (step > n) {
			string s;
			rep (i, 1, n) {
				s += str[ord[i]];
			}
			if (ans > calc(s)) ansstr = s;
			ans = min(ans, calc(s));
			return;
		}
		rep (i, 1, n) {
			if (!vis[i]) {
				vis[i] = 1;
				ord[step] = i;
				dfs(step + 1);
				vis[i] = 0;
			}
		}
	}
}

bool cmp(pair <int, pair <int, int> > a, pair <int, pair <int, int> > b) {
	return a.first + a.first * b.second.first > b.first + b.first * a.second.first;
}

vector <pair <int, pair <int, int> > > sss;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("karma.in", "r", stdin);
	freopen("karma.out", "w", stdout);
#endif
#endif
	cin >> n;
	rep (i, 1, n) {
		cin >> str[i], m += str[i].size();
		int cnt = 0;
		rep (j, 0, str[i].size() - 1) {
			if (str[i][j] == '0') cnt++;
		}
		sss.emplace_back(make_pair(cnt, make_pair(str[i].size() - cnt, i)));
	}
	sort(sss.begin(), sss.end(), cmp);
	string fans;
	for (auto x : sss) {
		int id = x.second.second;
		fans += str[id];
	}
	cout << calc(fans);
	return 0;
}
