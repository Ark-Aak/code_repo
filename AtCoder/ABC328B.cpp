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

int n;

int main() {
	int tot = 0;
	cin >> n;
	rep (i, 1, n) {
		int c;
		cin >> c;
		int t = i;
		int num = t % 10;
		while (t) if (t % 10 != num) break; else t /= 10;
		if (t) continue;
		t = num;
		while (t <= c) tot++, t = t * 10 + num;
	}
	cout << tot;
	return 0;
}