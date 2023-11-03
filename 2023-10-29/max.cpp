#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;


typedef long long ll;
typedef pair <int, int> pii;

#define int ll

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

const int MAXN = 1e5 + 5;
int n, a[MAXN];
char opset[10];
string s;
int ans = 0, ops;
string ansstr;
int stat = 0;

int calc(string s) {
	stack <int> stk;
	bool flg = 0;
	int tp = 0;
	for (char c : s) {
		if (isdigit(c)) stk.push(flg ? (c - 48) * tp : (c - 48)), flg = 0;
		else {
			if (c == '*') {
				tp = stk.top();
				stk.pop();
				flg = 1;
			}
			else if (c == '-') tp = -1, flg = 1;
		}
	}
	ll res = 0;
	while (stk.size()) res += stk.top(), stk.pop();
	return res;
}

map <char, int> _Ref;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("max.in", "r", stdin);
	freopen("max.out", "w", stdout);
#endif
#endif
	_Ref['+'] = 1, _Ref['-'] = 2, _Ref['*'] = 4;
	read(n);
	rep (i, 1, n) read(a[i]);
	cin >> s;
	rep (i, 1, (int) s.size()) {
		opset[i] = s[i - 1];
		stat += _Ref[opset[i]];
	}
	ops = s.size();
	if (s.size() == 1) {//stat = 1, 2, 4
		rep (i, 1, n) {
			cout << a[i];
			if (i != n) cout << s[0];
		}
		return 0;
	}
	if (stat == 3) {
		rep (i, 1, n) {
			cout << a[i];
			if (i != n) putchar('+');
		}
		return 0;
	}
	if (stat == 5 || stat == 7) {
		string s;
		rep (i, 1, n) {
			s += a[i] + 48;
			if (i != n) s += '*';
		}
		rep (i, 0, (int) s.size() - 1) {
			if (isdigit(s[i])) {
				if (s[i] == '0' || s[i] == '1') {
					if (i != 0) s[i - 1] = '+';
					if (i != (int) s.size() - 1) s[i + 1] = '+';
				}
			}
		}
		cout << s;
		return 0;
	}
	if (stat == 6) {
		string s;
		rep (i, 1, n) {
			s += a[i] + 48;
			if (i != n) s += '*';
		}
		rep (i, 0, (int) s.size() - 1) {
			if (isdigit(s[i])) {
				if (s[i] == '0') {
					if (i != 0) s[i - 1] = '-';
				}
			}
		}
		cout << s;
		return 0;
	}
	return 0;
}
