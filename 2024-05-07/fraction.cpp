#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

const int BUF_SIZ = 1 << 18;
char ibuf[BUF_SIZ], *iS = ibuf, *iT = ibuf;

#define getchar() (iS == iT && (iT = (iS = ibuf) + fread(ibuf, 1, BUF_SIZ, stdin)), iS == iT ? EOF : *iS++)

template <typename _Tp>
void read(_Tp &x) {
	char ch(getchar());
	bool f(false);
	while (!isdigit(ch)) f |= ch == 45, ch = getchar();
	x = ch & 15, ch = getchar();
	while (isdigit(ch)) x = x * 10 + (ch & 15), ch = getchar();
	if (f) x = -x;
}

template <typename _Tp, typename... Args>
void read(_Tp &t, Args &...args) {
	read(t); read(args...);
}

typedef unsigned long long ull;
int n, q;

struct MY_GENERATOR {
	int type;
	ull seed;

	inline ull nextInt() {
		ull z = (seed += 0x9E37793B5F4A7C15ULL);
		z = (z ^ (z >> 30)) * 0xBE99136D1CE4E5B9ULL;
		z = (z ^ (z >> 27)) * 0x94A749BB033BD1FBULL;
		return z ^ (z >> 31);
	}

	int get() { return nextInt() % 998244352 + 1; }

	inline void get(int lastans, int &l, int &r) {
		if (type == 2) {
			if (!type) lastans = 0;
			l = ((1 + (nextInt() >> 33)) ^ lastans) % n + 1;
			r = ((1 + (nextInt() >> 33)) ^ lastans) % n + 1;
			if (l > r) swap(l, r);
		}
		else {
			read(l), read(r);
			if (type) l ^= lastans, r ^= lastans;
		}
	}
} gen;

const int MAXN = 3000005;
const int MOD = 998244353;
int a[MAXN], p[MAXN];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (1ll * res * a) % MOD;
		a = 1ll * a * a % MOD;
		b >>= 1;
	}
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("fraction.in", "r", stdin);
	freopen("fraction.out", "w", stdout);
#endif
#endif
	read(n), read(q), read(gen.type), read(gen.seed);
	rep (i, 0, n) a[i] = gen.get();
	rep (i, 1, n) read(p[i]);

	/*
	Write your code here
	*/

	int l, r, lastans = 0;
	ull final_ans = 0;
	rep (t, 1, q) {
		gen.get(lastans, l, r);
		int ansnow = 0;
		stack <pii> stk;
		if (n <= 2000) {
			stk.push(dl(a[l - 1], 1e9));
			rep (i, l, r) {
				while (stk.size() && stk.top().fb < p[i]) {
					auto val1 = stk.top();
					stk.pop();
					auto val2 = stk.top();
					stk.pop();
					pii newval = dl(1ll * val2.ec * qpow(val1.ec, MOD - 2) % MOD, val2.fb);
					stk.push(newval);
				}
				stk.push(dl(a[i], p[i]));
			}
			while (stk.size() > 1) {
				auto val1 = stk.top();
				stk.pop();
				auto val2 = stk.top();
				stk.pop();
				pii newval = dl(1ll * val2.ec * qpow(val1.ec, MOD - 2) % MOD, val2.fb);
				stk.push(newval);
			}
			ansnow = stk.top().ec;
		}
		else {
			while (stk.size() == 0) {

			}
		}
		lastans = ansnow;
		final_ans ^= 1ull * t * ansnow;
	}
	printf("%llu\n", final_ans);
	return 0;
}
