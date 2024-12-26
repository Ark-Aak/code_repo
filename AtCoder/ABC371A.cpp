#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

char a, b, c;

signed main() {
	cin >> a >> b >> c;
	//a A B
	//b A C
	//c B C
	if (a == '<') {
		if (b == '<') {
			if (c == '<') {
				puts("B");
			}
			else {
				puts("C");
			}
		}
		else {
			puts("A");
		}
	}
	else {
		// A 比 B 大
		if (b == '<') {
			// A 比 C 小
			puts("A");
		}
		else {
			// A 比 C 大
			if (c == '<') {
				// B 比 C 小
				puts("C");
			}
			else puts("B");
		}
	}
	return 0;
}
