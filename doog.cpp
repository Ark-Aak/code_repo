#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= b; i++)
#define _rep(i, a, b) for(int i = (a); i >= b; i--)

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

int n, q;
string _s;
int a[5005], ans[1005][1005];
stack <int> s;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("doog.in", "r", stdin);
	freopen("doog.out", "w", stdout);
#endif
#endif
	cin >> n >> q;
	cin >> _s;
	rep (i, 0, _s.length() - 1) a[i + 1] = _s[i] - '0';
	if (n <= 1000 && q > 5000) {
		rep (i, 1, n) {
			while (!s.empty()) s.pop();
			rep (j, i, n) {
				if ((!s.empty()) && s.top() == a[j]) s.pop();
				else s.push(a[j]);
				if (s.empty()) ans[i][j] = 1;
				else ans[i][j] = 0;
			}
		}
		rep (i, 1, q) {
			int a, b, c;
			cin >> a >> b >> c;
			cout << (ans[b][c] ? "YES" : "NO" ) << endl;
		}
	}
	else {
		rep (i, 1, q) {
			int op, b, c;
			cin >> op >> b >> c;
			if (op == 1) {
				rep (j, b, c) {
					a[j]++;
					if (a[j] >= 3) a[j] -= 3;
				}
			}
			else {
				while (!s.empty()) s.pop();
				rep (j, b, c) {
					if ((!s.empty()) && s.top() == a[j]) s.pop();
					else s.push(a[j]);
				}
				if (s.empty()) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
	}
}
