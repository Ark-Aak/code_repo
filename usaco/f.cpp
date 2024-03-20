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

const int MAXN = 2e5 + 100;
int t, c;
int tar[MAXN];
string str;
const int o = 1e5 + 5;
int li[MAXN], ri[MAXN], fi[MAXN];
bitset <MAXN> hs;

int main() {
	cin >> t >> c;
	rep (i, 1, t) cin >> tar[i], tar[i] += o;
	cin >> str;
	int n = str.size();
	str = ' ' + str;
	int fans = 0;
	rep (__, 1, n) {
		int ptr = o;
		int ans = 0;
		char ori = str[__];
		rep (i, 1, t) hs[tar[i]] = 1;
		rep (i, 1, n) {
			if (str[i] == 'F') ans += hs[ptr], hs[ptr] = 0;
			else if (str[i] == 'L') ptr--;
			else ptr++;
		}
		fans = max(fans, ans);
		if (ori != 'L') {
			int ans = 0;
			int ptr = o;
			str[__] = 'L';
			rep (i, 1, t) hs[tar[i]] = 1;
			rep (i, 1, n) {
				if (str[i] == 'F') ans += hs[ptr], hs[ptr] = 0;
				else if (str[i] == 'L') ptr--;
				else ptr++;
			}
			fans = max(fans, ans);
		}
		if (ori != 'R') {
			int ans = 0;
			int ptr = o;
			str[__] = 'R';
			rep (i, 1, t) hs[tar[i]] = 1;
			rep (i, 1, n) {
				if (str[i] == 'F') ans += hs[ptr], hs[ptr] = 0;
				else if (str[i] == 'L') ptr--;
				else ptr++;
			}
			fans = max(fans, ans);
		}
		if (ori != 'F') {
			int ans = 0;
			int ptr = o;
			str[__] = 'F';
			rep (i, 1, t) hs[tar[i]] = 1;
			rep (i, 1, n) {
				if (str[i] == 'F') ans += hs[ptr], hs[ptr] = 0;
				else if (str[i] == 'L') ptr--;
				else ptr++;
			}
			fans = max(fans, ans);
		}
		str[__] = ori;
	}
	print(fans);
	return 0;
}
