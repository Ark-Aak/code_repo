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

int n, q;
string s;
int qz[300005];

int main() {
	cin >> n >> q >> s;
	rep (i, 1, n - 1) qz[i] = qz[i - 1] + (s[i] == s[i - 1]);
	rep (i, 0, n - 1) cout << qz[i] << " ";
	cout << endl;
	rep (i, 1, q) {
		int l, r;
		cin >> l >> r;
		cout << qz[r - 1] - qz[l - 1] << endl;
	}
	return 0;
}