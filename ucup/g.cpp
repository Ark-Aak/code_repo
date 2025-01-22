#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int ll

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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int minOps(int N, int A, int B) {
	int g = gcd(A, B);
	if (N % g != 0) return -1;
	int B_ = B / g, A_ = A / g, N_ = -N / g;
	int x, y;
	exgcd(B_, A_, x, y);
	x = (1LL * x * N_) % A_;
	if (x < 0) x += A_;
	return x;
}

signed main() {
	int T = read();
	while (T --> 0) {
		__gnu_pbds::cc_hash_table <int, int> hsh;
		int a, b, n;
		a = read(), b = read(), n = read();
		int fn = n;
		bool flg = 0;
		if (minOps(n, a, b) == -1) {
			puts("No");
			flg = 1;
			continue;
		}
		hsh[n] = 1;
		n = (minOps(n, a, b) * b + n) / a;
		hsh[n] = 1;
		rep (i, 1, 100) {
			int nxt = minOps(n, a, b);
			if (nxt == -1) {
				puts("No");
				flg = 1;
				break;
			}
			int addTo = n + b * nxt;
			if (n <= fn && fn <= addTo && (fn - n) % b == 0) {
				puts("Yes");
				flg = 1;
				break;
			}
			if (hsh[addTo]) {
				puts("No");
				flg = 1;
				break;
			}
			n = addTo / a;
			hsh[n] = 1;
		}
		if (!flg) puts("No");
	}
	return 0;
}
