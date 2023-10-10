#include <bits/stdc++.h>

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define _rep(i, a, b) for (auto i = a;i >= b; i--)

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

int T;
string t;

int main() {
	cin >> T;
	while (T --> 0) {
		cin >> t;
		int len = t.length();
		int L = 0, R = len - 1;
		while (1) {
			if (len & 1) {
				rep (i, L, R) cout << t[i];
				cout << endl;
				break;
			}
			int l = L, r = R, flg = 0;
			while (l < r) {
				if (t[l] != t[r]) {
					rep (i, L, R) cout << t[i];
					cout << endl;
					flg = 1;
					break;
				}
				l++, r--;
			}
			if (flg) break;
			len /= 2;
			R = len - 1;
		}
	}
}
