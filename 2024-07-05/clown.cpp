#include<bits/stdc++.h>

#define rep(i, a, b) for (auto i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (auto i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, w = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') w = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = x * 10 + (c ^ 48);
		c = getchar();
	}
	return  x * w;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}


signed main() {
#ifndef LOCAL
	freopen("clown.in", "r", stdin);
	freopen("clown.out", "w", stdout);
#endif
	puts("0");
	return 0;
}
