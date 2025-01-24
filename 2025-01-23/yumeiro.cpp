#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

string s, t;
int n, m;
bool swaped = 0;
const int MAXN = 3005;
int kmp[MAXN];

vector <pii> match(string s, string t) {
	s = ' ' + s, t = ' ' + t;
	int n = s.size() - 1, m = t.size() - 1;
	memset(kmp, 0, sizeof kmp);
	for (int i = 2, j = 0; i <= m; i++) {
		while (j && t[j + 1] != t[i]) j = kmp[j];
		if (t[j + 1] == t[i]) j++;
		kmp[i] = j;
	}
	vector <pii> res;
	for (int i = 1, j = 0; i <= n; i++) {
		if (j && t[j + 1] != s[i]) {
			// failed
			// i - 1 matched j
			int st = i - j;
			res.emplace_back(st, j);
		}
		while (j && t[j + 1] != s[i]) j = kmp[j];
		if (t[j + 1] == s[i]) j++;
		if (j == m) {
			res.emplace_back(i - m + 1, m);
			j = kmp[j];
		}
	}
	return res;
}

#include <bits/extc++.h>

__gnu_pbds::cc_hash_table <int, int> poss[MAXN], post[MAXN];

tuple <int, int, int> solve(string s, string _t) {
	rep (i, 1, n) poss[i].clear(), post[i].clear();
	tuple <int, int, int> res = { 0, 0, 0 };
	const auto update = [&](int len, int s1, int s2) {
		if (len > get<0>(res)) res = dk(len, s1, s2);
	};
	rep (st, 1, m) {
		string t = _t.substr(st - 1, m - st + 1);
		vector <pii> res = match(s, t);
		for (auto [s, len] : res) {
			update(len, st - 1, s - 1);
			poss[s][st] = len;
			post[s + len - 1][st] = len;
		}
	}
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (!poss[i][j]) continue;
			int len = poss[i][j];
			int nxt = j + len;
			if (nxt > m) continue;
			if (!post[i - 1][nxt]) continue;
			int pl = i - post[i - 1][nxt];
			int pr = i + len - 1;
			update(pr - pl + 1, j - 1, pl - 1);
		}
	}
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("yumeiro.in", "r", stdin);
	freopen("yumeiro.out", "w", stdout);
#endif
#endif
	cin >> s >> t;
	if (s.size() < t.size()) {
		swap(s, t);
		swaped = 1;
	}
	n = s.size(), m = t.size();
	tuple <int, int, int> ans;
	tuple <int, int, int> ans1 = solve(s, t);
	reverse(s.begin(), s.end());
	tuple <int, int, int> ans2 = solve(s, t);
	reverse(t.begin(), t.end());
	tuple <int, int, int> ans3 = solve(s, t);
	reverse(s.begin(), s.end());
	tuple <int, int, int> ans4 = solve(s, t);
	get<2>(ans2) = n - get<2>(ans2) - get<0>(ans2);
	get<1>(ans3) = m - get<1>(ans3) - get<0>(ans3);
	get<2>(ans3) = n - get<2>(ans3) - get<0>(ans3);
	get<1>(ans4) = m - get<1>(ans4) - get<0>(ans4);
	ans = max(ans, ans1);
	ans = max(ans, ans2);
	ans = max(ans, ans3);
	ans = max(ans, ans4);
	cout << get<0>(ans) << endl;
	if (swaped) cout << get<1>(ans) << " " << get<2>(ans) << endl;
	else cout << get<2>(ans) << " " << get<1>(ans) << endl;
	return 0;
}
