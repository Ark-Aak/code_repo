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

int T, q;
string str;
int k, l, r;
const int MAXN = 5e5 + 5;

int ps = 1e9;

string toB(string str, int len) {
	string res;
	rep (i, 0, len - 1) {
		res += str[i % str.size()];
		if (i % str.size() == 0 && i > 1e5) ps = min(ps, i);
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

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
#endif
#endif
	cin >> T;
	while (T --> 0) {
		cin >> str;
		int q;
		cin >> q; ps = 1e9;
		str = toB(str, 5e5 + 20);
		memset(qz, 0, sizeof qz);
		rep (i, 0, 3) {
			qz[i][0] = str[0] == '(';
			rep (j, 1, str.size() - 1) qz[i][j] = qz[i][j - 1] + (str[j] == '(');
			str = trans(str);
		}
		while (q --> 0) {
			int k, l, r;
			cin >> k >> l >> r;
			k %= 4;
			l += ps - k, r += ps - k;
			cout << qz[k][r] - qz[k][l - 1] << endl;
		}
	}
	return 0;
}
