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

mt19937 rnd(time(0));

int main() {
	int n = abs((int) rnd()) % 500000;
	cout << n << endl;
	int cnt = 0;
	int i = 1;
	while (cnt < n - 1) {
		cout << i << " " << (i << 1) << endl;
		++cnt;
		if (cnt >= n - 1) break;
		cout << i << " " << (i << 1 | 1) << endl;
		++cnt;
		++i;
	}
	return 0;
}
