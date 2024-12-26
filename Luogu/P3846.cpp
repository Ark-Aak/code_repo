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

int p, a, b;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

namespace BSGS {

	int T, a, b;
	__gnu_pbds::cc_hash_table <int, int> val;

	void init(int a, int b, int p) {
		val.clear();
		T = ceil(sqrt(p));
		BSGS::a = a, BSGS::b = b;
		rep (j, 0, T) {
			val[qpow(a, j) * b % p] = j;
		}
	}

	int solve() {
		rep (i, 0, T) {
			int tmp = qpow(a, i * T);
			if (val.find(tmp) != val.end() && i * T >= val[tmp])
				return i * T - val[tmp];
		}
		return -1;
	}

} // namespace BSGS

signed main() {
	p = read(), a = read(), b = read();
	BSGS::init(a, b, p);
	int val = BSGS::solve();
	if (val == -1) puts("no solution");
	else print(val), puts("");
	return 0;
}
