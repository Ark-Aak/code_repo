#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-')
			f = -1;
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
	if (x < 0)
		x = (~x + 1), putchar('-');
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 2005;
const int MOD = 1e9 + 7;
int n, m, a[MAXN], b[MAXN], c[MAXN];
int S2[MAXN][MAXN];
typedef vector<int> Poly;

inline void upd(int &x, const int &y) { if ((x += y) >= MOD) x -= MOD; }

int qpow(int a, int b) {
	int ans = 1;
	for (; b; b >>= 1, a = (ll)a * a % MOD)
		if (b & 1) ans = (ll)ans * a % MOD;
	return ans;
}

Poly &operator+=(Poly &F, const Poly &G) {
	int dF = F.size(), dG = G.size();
	if (dF < dG) F.resize(dG);
	for (int i = 0; i < dG; i++) upd(F[i], G[i]);
	return F;
}

Poly operator+(const Poly &F, const Poly &G) {
	int dF = F.size(), dG = G.size();
	Poly H(max(dF, dG));
	copy(F.begin(), F.end(), H.begin());
	for (int i = 0; i < dG; i++) upd(H[i], G[i]);
	return H;
}

Poly operator*(const Poly &F, const Poly &G) {
	if (F.empty() || G.empty()) return {};
	int dF = F.size(), dG = G.size();
	Poly H(min(dF + dG - 1, n + 1));
	for (int i = 0; i < dF; i++)
		for (int j = 0; j < dG && i + j <= n; j++)
			upd(H[i + j], (ll)F[i] * G[j] % MOD);
	return H;
}

const int B = 30;

Poly pw[MAXN];
Poly f[MAXN][MAXN];

signed main() {
	n = read(), m = read();
	S2[0][0] = 1;
	rep(i, 1, n) {
		rep(j, 1, i) {
			S2[i][j] = (S2[i - 1][j - 1] + S2[i - 1][j] * j % MOD) % MOD;
		}
	}
	pw[0] = {1};
	rep (i, 1, B) pw[i] = pw[i - 1] * (Poly){1, 1};
	rep (i, 1, m) {
		int a = read(), b = read(), c = read();
		int k = a / B, r = a % B;
		f[k][b] += Poly(S2[c], S2[c] + c + 1) * pw[r];
	}
	Poly ans;
	_rep (i, n / B, 0) {
		Poly res;
		_rep (j, n, 1) {
			res += f[i][j];
			int siz = res.size();
			if (siz <= n) res.resize(++siz);
			_rep (k, siz - 1, 1)
				res[k] = (res[k] * (j - 1) % MOD + res[k - 1]) % MOD;
			res[0] *= j - 1;
			res[0] %= MOD;
		}
		res += f[i][0];
		ans = ans * pw[B] + res;
	}
	ans.resize(n + 1);
	rep (i, 0, n) print(ans[i]), putchar(32);
	return 0;
}
