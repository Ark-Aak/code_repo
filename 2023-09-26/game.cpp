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

int T, n, k, pre[1145141];
string s;

int main() {
	cin >> T;
	while (T --> 0) {
		cin >> n >> k >> s;
		s = ' ' + s;
		int l1 = 0, r1, l2 = 0, r2;
		rep (i, 1, n) {
			if (s[i] == '0') {
				l1 = i; break;
			}
		}
		rep (i, 1, n) {
			if (s[i] == '1') {
				l2 = i; break;
			}
		}
		_rep (i, n, 1) {
			if (s[i] == '0') {
				r1 = i; break;
			}
		}
		_rep (i, n, 1) {
			if (s[i] == '1') {
				r2 = i; break;
			}
		}
		if (r1 - l1 + 1 <= k || r2 - l2 + 1 <= k) {
			cout << "win" << endl;
		}
		else if (r1 - l1 <= k && r2 - l2 <= k) {
			cout << "lose" << endl;
		}
		else cout << "tie" << endl;
	}
	return 0; 
}
