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

int T;
string a, b, c;
ll ans = 0;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("pali.in", "r", stdin);
	freopen("pali.out", "w", stdout);
#endif
#endif
	cin >> T;
	while (T --> 0) {
		cin >> a >> b >> c;
		int lena = a.length(), lenb = b.length(), lenc = c.length();
		a = ' ' + a, b = ' ' + b, c = ' ' + c;
		rep (la, 1, lena) {
			string ta = "";
			rep (ra, la, lena) {
				ta += a[ra];
				rep (lb, 1, lenb) {
					string tb = "";
					rep (rb, lb, lenb) {
						tb += b[rb];
						rep (lc, 1, lenc) {
							string tc = "";
							rep (rc, lc, lenc) {
								tc += c[rc];
								string t = ta + tb + tc;
								int len = t.length();
								t = ' ' + t;
								int l = 1, r = len, flg = 0;
								while (l <= r) {
									if (t[l] != t[r]) {
										flg = 1; break;
									}
									l++, r--;
								}
								if (!flg) ans++;
							}
						}
					}
				}
			}
		}
		cout << ans << endl;
		ans = 0;
	}
	return 0; 
}
