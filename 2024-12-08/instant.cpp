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

namespace fastio {
	const int bufl = 1 << 20;
	const double base1[16] = {
		1, 1e-1, 1e-2, 1e-3, 1e-4, 1e-5, 1e-6,
		1e-7, 1e-8, 1e-9, 1e-10, 1e-11, 1e-12, 1e-13, 1e-14, 1e-15
	};
	const double base2[16] = {
		1, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7,
		1e8, 1e9, 1e10, 1e11, 1e12, 1e13, 1e14, 1e15
	};
	struct IN {
		FILE *IT;
		char ibuf[bufl], *is = ibuf, *it = ibuf;
		IN() { IT = stdin; }
		inline char getChar() {
			if (is == it) {
				it = (is = ibuf) + fread(ibuf, 1, bufl, IT);
				if (is == it) return EOF;
			}
			return *is++;
		}
		template <typename _Tp>
		inline void getInt(_Tp &a) {
			a = 0; int b = 0, c = getChar();
			while (c < 48 || c > 57) b ^= (c == 45), c = getChar();
			while (c >= 48 && c <= 57) a = (a << 1) + (a << 3) + c - 48, c = getChar();
			if (b) a = -a;
		}
		IN& operator >> (int &a) { getInt(a); return *this; }
	};
	struct OUT {
		FILE *IT;
		char obuf[bufl], *os = obuf, *ot = obuf + bufl;
		OUT() { IT = stdout; }
		inline void flush() { fwrite(obuf, 1, os - obuf, IT); os = obuf; }
		inline void putChar(int a) { *os++ = a; if (os == ot) flush(); }
		template <typename _Tp>
		inline void putInt(_Tp a) {
			if (a < 0) putChar(45), a = -a;
			if (a < 10) return putChar(a + 48);
			putInt(a / 10);
			putChar(a % 10 + 48);
		}
		OUT& operator << (char a) { putChar(a); return *this; }
		OUT& operator << (int a) { putInt(a); return *this; }
		OUT& operator << (ll a) { putInt(a); return *this; }
		~OUT() { flush(); }
	};
}
using fastio::IN;
using fastio::OUT;
IN fin;
OUT fout;

const int MAXN = 1e5 + 5;
int n, q, a[MAXN], b[MAXN], fa[MAXN];
vector <int> G[MAXN];

void init(int u, int fa) {
	a[u] += a[fa];
	b[u] += b[fa];
	::fa[u] = fa;
	for (auto v : G[u]) {
		if (v == fa) continue;
		init(v, u);
	}
}

void modify(int u, int val) {
	a[u] += val;
	for (auto v : G[u]) {
		if (v == fa[u]) continue;
		modify(v, val);
	}
}

inline int myabs(int a) { return a < 0 ? -a : a; }
inline void chmax(ll &a, ll b) { (a < b) && (a = b); }

ll query(int u) {
	ll res = 1ll * myabs(a[u]) * myabs(b[u]);
	for (auto v : G[u]) {
		if (v == fa[u]) continue;
		chmax(res, query(v));
	}
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("instant.in", "r", stdin);
	freopen("instant.out", "w", stdout);
#endif
#endif
	fin >> n >> q;
	rep (i, 2, n) {
		int f;
		fin >> f;
		G[f].push_back(i);
		G[i].push_back(f);
	}
	rep (i, 1, n) fin >> a[i];
	rep (i, 1, n) fin >> b[i];
	init(1, 0);
	while (q --> 0) {
		int op;
		fin >> op;
		if (op == 1) {
			int u, x;
			fin >> u >> x;
			modify(u, x);
		}
		else {
			int x;
			fin >> x;
			fout << query(x) << '\n';
		}
	}
	cerr << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	return 0;
}
