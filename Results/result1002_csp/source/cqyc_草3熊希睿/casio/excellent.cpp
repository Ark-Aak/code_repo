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

int Q, ans;
string ss;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("excellent.in", "r", stdin);
	freopen("excellent.out", "w", stdout);
#endif
#endif
	cin >> Q;
	while (Q --> 0) {
		ans = 0;
		cin >> ss;
		rep (L, 0, ss.size() - 1) {
			rep (R, L + 3, ss.size() - 1) {
				string s = ss.substr(L, R - L + 1);
				int n = s.size();
				if (n & 1) continue;
				rep (spliter, 2, n - 1) {
					if (spliter & 1) continue;
					string l, r, l1, l2, r1, r2;
					l = s.substr(0, spliter);
					r = s.substr(spliter);
					l1 = l.substr(0, spliter / 2);
					l2 = l.substr(spliter / 2);
					int len = n - spliter;
					r1 = r.substr(0, len / 2);
					r2 = r.substr(len / 2);
					//cout << "-----" << endl;
					//cout << s << endl;
					//cout << l << " " << r << endl;
					//cout << l1 << " " << l2 << " " << r1 << " " << r2 << endl;
					//cout << "spliter = " << spliter << endl;
					//cout << "-----" << endl;
					bool flg = 0;
					rep (i, 0, spliter / 2 - 1) {
						if (l1[i] != l2[i] && l1[i] != '?' && l2[i] != '?') {
							flg = 1;
							break;
						}
					}
					if (flg) continue;
					rep (i, 0, len / 2 - 1) {
						if (r1[i] != r2[i] && r1[i] != '?' && r2[i] != '?') {
							flg = 1;
							break;
						}
					}
					if (!flg) ans++;
				}
			}
		}
		print(ans), putchar(10);
	}
	return 0; 
}
