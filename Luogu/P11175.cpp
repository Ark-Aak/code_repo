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

int P, g, h0, H;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return res;
}

namespace BSGS {

	int T, g, p, inv;
	__gnu_pbds::cc_hash_table <int, int> val;

	void init(int g0, int p0, int B) {
		val.clear();
		p = p0, g = g0;
		T = B;
		int v = 1;
		inv = qpow(qpow(g, B), p - 2);
		rep (j, 0, T - 1) {
			val[v] = j;
			v = v * g % p;
		}
	}

	int solve(int x) {
		int v = x;
		rep (i, 0, p / T) {
			if (val.find(v) != val.end()) {
				return i * T + val[v];
			}
			v = v * inv % p;
		}
		return -1;
	}

} // namespace BSGS

const int MAXN = 1e5 + 5;
int val[MAXN];
bool vis[MAXN];
vector <int> p;

int solve(int x) {
	if (x <= H) return val[x];
	int v = P / x, r = P % x;
	if (r < x - r) {
		return ((h0 + solve(r)) % (P - 1) - val[v] + P - 1) % (P - 1);
    } else {
        return (solve(x - r) - val[v + 1] + P - 1) % (P - 1);
    }
}

signed main() {
	P = read(), g = read();
	int q = read();
	BSGS::init(g, P, sqrt(P * sqrt(P) / log(P)));
	h0 = BSGS::solve(P - 1);
	H = sqrt(P) + 1;
	val[1] = 0;
	rep (i, 2, H) {
		if (!vis[i]) {
			p.push_back(i);
			val[i] = BSGS::solve(i);
		}
		for (auto j : p) {
			if (i * j > H) break;
			vis[i * j] = 1;
			val[i * j] = (val[i] + val[j]) % (P - 1);
			if (i % j == 0) break;
		}
	}
	while (q --> 0) {
		int x = read();
		print(solve(x)), puts("");
	}
	return 0;
}
