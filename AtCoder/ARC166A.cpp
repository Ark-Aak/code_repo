#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

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
int n;
string x, y;

int main() {
	cin >> T;
	while (T --> 0) {
		cin >> n >> x >> y;
		if (x == y) {
			cout << "Yes\n";
			continue;
		}
		x = ' ' + x, y = ' ' + y;
		bool flg = 1, flg2 = 0;
		int cnta[2] = {0}, cntb[2] = {0}, cntc[2] = {0};
		rep (i, 1, n) {
			if (x[i] == 'A') cnta[0]++;
			if (x[i] == 'B') cntb[0]++;
			if (x[i] == 'C') cntc[0]++;
			if (y[i] == 'A') cnta[1]++;
			if (y[i] == 'B') cntb[1]++;
			if (y[i] == 'C') cntc[1]++;
			if (x[i] != 'C' && y[i] == 'C') {
				cout << "No\n"; flg = 0;
				break;
			}
			if (i != n && x[i] == 'A' && x[i + 1] == 'B') flg2 = 1;
		}
		if (!flg) continue;
		if (cnta[0] > cnta[1]) {
			cout << "No\n";
			continue;
		}
		if (cntb[0] > cntb[1]) {
			cout << "No\n";
			continue;
		}
		if (cnta[1] - cnta[0] + cntb[1] - cntb[0] != cntc[0] - cntc[1]) {
			cout << "No\n";
			continue;
		}

		continue;
	}
	return 0; 
}
