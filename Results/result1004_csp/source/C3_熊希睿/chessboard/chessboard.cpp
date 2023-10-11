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

int bd[2005][2005];
int n, m;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("chessboard.in", "r", stdin);
	freopen("chessboard.out", "w", stdout);
#endif
#endif
	memset(bd, 0x3f, sizeof bd);
	cin >> n >> m;
	rep (i, 1, n) rep (j, 1, m) {
		char c;
		cin >> c;
		if (c == '0') bd[i][j] = 0;
		else if (c == '1') bd[i][j] = 1;
		else bd[i][j] = 2;
	}
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (bd[i][j] == 1) {
				if (bd[i + 1][j + 1] == 1 && bd[i][j + 1] == 0 && bd[i + 1][j] == 0)
					return (cout << "No", 0);
				else if (bd[i + 1][j + 1] == 0 || bd[i][j + 1] == 1 || bd[i + 1][j] == 1) continue;
				else if (bd[i + 1][j + 1] == 1 && bd[i][j + 1] == 0 && bd[i + 1][j] == 2) bd[i + 1][j] = 1;
				else if (bd[i + 1][j + 1] == 2 && bd[i][j + 1] == 0 && bd[i + 1][j] == 0) bd[i + 1][j + 1] = 0;
				else if (bd[i + 1][j + 1] == 1 && bd[i][j + 1] == 2 && bd[i + 1][j] == 0) bd[i][j + 1] = 1;
			}
			else if (bd[i][j] == 0) {
				if (bd[i + 1][j + 1] == 0 && bd[i][j + 1] == 1 && bd[i + 1][j] == 1)
					return (cout << "No", 0);
				else if (bd[i + 1][j + 1] == 1 || bd[i][j + 1] == 0 || bd[i + 1][j] == 0) continue;
				else if (bd[i + 1][j + 1] == 0 && bd[i][j + 1] == 1 && bd[i + 1][j] == 2) bd[i + 1][j] = 0;
				else if (bd[i + 1][j + 1] == 2 && bd[i][j + 1] == 1 && bd[i + 1][j] == 1) bd[i + 1][j + 1] = 1;
				else if (bd[i + 1][j + 1] == 0 && bd[i][j + 1] == 2 && bd[i + 1][j] == 1) bd[i][j + 1] = 0;
			}
			else if (bd[i][j] == 2) {
				if (bd[i - 1][j - 1] == 1 && bd[i - 1][j] == 0 && bd[i][j - 1] == 0) bd[i][j] = 0;
				if (bd[i - 1][j - 1] == 0 && bd[i - 1][j] == 1 && bd[i][j - 1] == 1) bd[i][j] = 1;
				if (bd[i - 1][j - 1] == 2 && bd[i - 1][j] == 0 && bd[i][j - 1] == 0) bd[i - 1][j - 1] = bd[i][j] = 0;
				if (bd[i - 1][j - 1] == 2 && bd[i - 1][j] == 1 && bd[i][j - 1] == 1) bd[i - 1][j - 1] = bd[i][j] = 1;
				if (bd[i][j] == 2 && (bd[i][j + 1] == 2 || bd[i + 1][j] == 2)) bd[i][j] = 0;
			}
		}
	}
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (bd[i][j] == 1) {
				if (bd[i + 1][j + 1] == 1 && bd[i][j + 1] == 0 && bd[i + 1][j] == 0)
					return (cout << "No", 0);
				else if (bd[i + 1][j + 1] == 0 || bd[i][j + 1] == 1 || bd[i + 1][j] == 1) continue;
			}
			else if (bd[i][j] == 0) {
				if (bd[i + 1][j + 1] == 0 && bd[i][j + 1] == 1 && bd[i + 1][j] == 1)
					return (cout << "No", 0);
			}
		}
	}
	cout << "Yes" << "\n";
	rep (i, 1, n) {
		rep (j, 1, m) cout << (bd[i][j] == 2 ? 0 : bd[i][j]);
		cout << "\n";
	}
	return 0; 
}
