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

int n, m;
string s;

int main() {
	cin >> n >> m;
	cin >> s;
	int nd = 0;
	int ans = 0;
	int tm = m;
	for (auto c : s) {
		if (c == '0') tm = m, nd = 0;
		else if (c == '1') {
			if (tm) --tm;
			else ++nd;
		}
		else ++nd;
		ans = max(ans, nd);
	}
	cout << ans;
	return 0;
}
