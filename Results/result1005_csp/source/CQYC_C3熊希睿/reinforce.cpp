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

string s;
int _id[30], id[30], ans = 1e9, cnt;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("reinforce.in", "r", stdin);
	freopen("reinforce.out", "w", stdout);
#endif
#endif
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	rep (i, 1, n) if (!_id[s[i] - 'a']) _id[s[i] - 'a'] = ++cnt;
	rep (i, 0, cnt - 1) {
		int tans = 1;
		rep (j, 0, 25) if (_id[j]) id[j] = ((_id[j] + i) > cnt ? (_id[j] + i - cnt) : _id[j] + i);
		rep (j, 2, n) {
			if (id[s[j] - 'a'] <= id[s[j - 1] - 'a']) tans++;
		}
		ans = min(ans, tans);
	}
	rep (i, 0, cnt - 1) {
		int tans = 1;
		rep (j, 0, 25) if (_id[j]) id[j] = ((_id[j] + i) > cnt ? (_id[j] + i - cnt) : _id[j] + i);
		rep (j, 2, n) {
			if (id[s[j] - 'a'] >= id[s[j - 1] - 'a']) tans++;
		}
		ans = min(ans, tans);
	}
	print(ans);
	return 0; 
}
