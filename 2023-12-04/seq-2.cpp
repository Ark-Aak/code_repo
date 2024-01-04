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

int T, q;
string str;
int k, l, r;
const int MAXN = 5e5 + 5;

int ps[10];

string toB(string str, int len) {
	string res;
	rep (i, 0, len - 1) {
		res += str[i % str.size()];
	}
	return res;
}

string trans(string str) {
	string res;
	rep (i, 1, str.size() - 2) {
		res += (str[i] == '(' ? str[i + 1] : str[i - 1]);
	}
	return res;
}

int qz[10][MAXN];
int qqz[10][MAXN];

int nxtL(int num, int n) {
	if (num <= 0) {
		int tnum = -num;
		int nt = ceil(tnum * 1.0 / n);
		return -(nt * n);
	}
	else return floor(num * 1.0 / n) * n;
}

int nxtR(int num, int n) {
	if (num <= 0) {
		int tnum = -num;
		int nt = floor(tnum * 1.0 / n);
		return -(nt * n) - 1;
	}
	else return ceil(num * 1.0 / n) * n - 1;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
#endif
#endif
	cin >> T;
	while (T --> 0) {
		cin >> str;
		int q, n = str.size();
		cin >> q; ps[0] = n;
		str = toB(str, 5e5 + 20);
		memset(qz, 0, sizeof qz);
		rep (i, 0, 3) {
			qz[i][0] = str[0] == '(';
			ps[i] = ps[0] - i;
			rep (j, 1, str.size() - 1) qz[i][j] = qz[i][j - 1] + (str[j] == '(');
			qqz[i][0] = str[ps[i]] == '(';
			rep (j, ps[i] + 1, ps[i] + n - 1) {
				qqz[i][j - ps[i]] = qqz[i][j - ps[i] - 1] + (str[j] == '(');
			}
			str = trans(str);
		}
		while (q --> 0) {
			int k, l, r;
			cin >> k >> l >> r;
			k %= 4;
			l -= k, r -= k;
			int tsum = qqz[k][n - 1];
			cout << "l, r:" << l << " " << r << endl;
			int Tl = nxtL(l, n), Tr = nxtR(r, n);
			cout << "Tl, r:" << Tl << " " << Tr << endl;
			int cnt = (Tr - Tl + 1) / n;
			cout << "tsum:" << tsum << endl;
			int ans = cnt * tsum;
			cout << "ans1:" << ans << endl;
			if (l != Tl) ans -= qqz[k][l - Tl - 1];
			cout << "ans2:" << ans << endl;
			if (r != Tr) ans -= tsum - qqz[k][n - (Tr - r) - 1];
			cout << "ans3:" << ans << endl;
			cout << ans << endl;
		}
	}
	return 0;
}
