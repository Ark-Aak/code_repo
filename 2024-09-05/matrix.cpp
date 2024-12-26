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

using u32 = unsigned;
struct IO_Tp {
	const static int _I_Buffer_Size = 30 << 20;
	char _I_Buffer[_I_Buffer_Size], *_I_pos = _I_Buffer;

	const static int _O_Buffer_Size = 8 << 20;
	char _O_Buffer[_O_Buffer_Size], *_O_pos = _O_Buffer;

	u32 m[10000];

	IO_Tp() {
		constexpr u32 e0 = '\0\0\0\1', e1 = '\0\0\1\0', e2 = '\0\1\0\0', e3 = '\1\0\0\0';
		int x = 0;
		for (u32 i = 0, c0 = '0000'; i != 10; ++i, c0 += e0)
			for (u32 j = 0, c1 = c0; j != 10; ++j, c1 += e1)
				for (u32 k = 0, c2 = c1; k != 10; ++k, c2 += e2)
					for (u32 l = 0, c3 = c2; l != 10; ++l, c3 += e3)
						m[x++] = c3;

		fread(_I_Buffer, 1, _I_Buffer_Size, stdin);
	}
	~IO_Tp() { fwrite(_O_Buffer, 1, _O_pos - _O_Buffer, stdout); }

	IO_Tp &operator>>(int &res) {
		while (!isdigit(*_I_pos))
			++_I_pos;
		res = *_I_pos++ - '0';
		while (isdigit(*_I_pos))
			res = res * 10 + (*_I_pos++ - '0');
		return *this;
	}

	IO_Tp &operator<<(int x) {
		if (x == 0) {
			*_O_pos++ = '0';
			return *this;
		}
		static char _buf[35];
		char *_pos = _buf + 35;
		while (x >= 10000)
			*--reinterpret_cast<u32 *&>(_pos) = m[x % 10000], x /= 10000;
		*--reinterpret_cast<u32 *&>(_pos) = m[x];
		_pos += (x < 1000) + (x < 100) + (x < 10);
		_O_pos = std::copy(_pos, _buf + 35, _O_pos);
		return *this;
	}

	IO_Tp &operator<<(char ch)
	{
		*_O_pos++ = ch;
		return *this;
	}
} IO;

const int MAXN = 1005;
int T, n, mod;
int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];
int sumrow[MAXN], sumcol[MAXN], exprow[MAXN], expcol[MAXN];
int ansrow[MAXN], anscol[MAXN];

void solve() {
	IO >> mod;
	IO >> n;
	rep (i, 1, n) sumrow[i] = sumcol[i] = 0;
	rep (i, 1, n) exprow[i] = expcol[i] = 0;
	rep (i, 1, n) ansrow[i] = anscol[i] = 0;
	rep (i, 1, n) rep (j, 1, n) IO >> a[i][j];
	rep (i, 1, n) rep (j, 1, n) IO >> b[i][j];
	rep (i, 1, n) rep (j, 1, n) IO >> c[i][j];
	rep (i, 1, n) rep (j, 1, n) {
		sumrow[i] = (sumrow[i] + b[i][j]) % mod;
		sumcol[j] = (sumcol[j] + a[i][j]) % mod;
		ansrow[i] = (ansrow[i] + c[i][j]) % mod;
		anscol[j] = (anscol[j] + c[i][j]) % mod;
	}
	rep (i, 1, n) rep (j, 1, n) exprow[i] = (1ll * exprow[i] + 1ll * a[i][j] * sumrow[j]) % mod;
	rep (i, 1, n) rep (j, 1, n) expcol[j] = (1ll * expcol[j] + 1ll * b[i][j] * sumcol[i]) % mod;
	bool flg = 1;
	rep (i, 1, n) flg &= exprow[i] == ansrow[i];
	rep (i, 1, n) flg &= expcol[i] == anscol[i];
	if (flg) IO << 'Y' << 'e' << 's' << '\n';
	else IO << 'N' << 'o' << '\n';
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
#endif
#endif
	IO >> T;
	while (T --> 0) solve();
	return 0;
}
