#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define ec first
#define fb second
#define de(x) cerr << #x << " = " << (x) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, w = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + (ch ^ 48);
		ch = getchar();
	}
	return x * w;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}



int main() {
#ifndef LOCAL
	
#endif

	return 0;
}
