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

int n;
string s;
vector <pii> seg;

signed main() {
	cin >> n >> s;
	int st = 0;
	s = ' ' + s;
	s += '0';
	rep (i, 1, n + 1) {
		if (s[i] == '1') {
			if (st == 0) st = i;
		}
		else {
			if (st != 0) seg.push_back({st, i - 1}), st = 0;
		}
	}
	sort(seg.begin(), seg.end(), [](pii a, pii b) {return a.second - a.first < b.second - b.first;});
	int day = 1e9, ans = 0, mnlen = seg[0].second - seg[0].first + 1;
	int fl = 0, fr = 0;
	for (auto v : seg) {
		int len = v.second - v.first + 1;
		int st = v.first, ed = v.second;
			if (len & 1) {
			   if (st != 1 && ed != n) {
				   if (day > len / 2) day = len / 2, fl = st, fr = ed, ans = 1;
				   else if (day == len / 2 && ans > 1) fl = st, fr = ed, ans = 1;
			   }
			   else {
				   if (day > len - 1) day = len - 1, fl = st, fr = ed, ans = 1;
				   if (day == len - 1 && ans > 1) fl = st, fr = ed, ans = 1;
			   }
			}
			else {
				if (st != 1 && ed != n) {
					if (day > len / 2 - 1) day = len / 2 - 1, fl = st, fr = ed, ans = 2;
				}
				else {
					if (day > len - 1) day = len - 1, fl = st, fr = ed, ans = 1;
					if (day == len - 1 && ans > 1) fl = st, fr = ed, ans = 1;
				}
			}
	}
	for (auto v : seg) {
		int st = v.first, ed = v.second;
		int len = ed - st + 1;
		if (st == fl && ed == fr) continue;
		ans += ceil(len * 1.0 / (day * 2.0 + 1.0));
	}
	print(ans);
	return 0;
}
