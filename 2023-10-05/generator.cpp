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

mt19937 rnd(time(0));
int a[105], b[105];

int main() {
	int n = abs((int) rnd()) % 10 + 91;
	print(n), putchar(10);
	rep (i, 1, n) a[i] = b[i] = i;
	shuffle(a + 1, a + 1 + n, rnd);
	shuffle(b + 1, b + 1 + n, rnd);
	rep (i, 1, n) print(a[i]), putchar(32);
	putchar(10);
	rep (i, 1, n) print(b[i]), putchar(32);
	return 0; 
}
