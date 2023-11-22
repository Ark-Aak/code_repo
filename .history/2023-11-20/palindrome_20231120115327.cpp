#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MAXN = 1e5 + 5;
int n, k;
const int MOD = 998244353;
int phi[MAXN];
vector <int> prime, fac[MAXN];
bool flg[MAXN];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void sieve() {
	phi[1] = 1;
	rep (i, 2, n) {
        if(!flg[i]) {
            prime.emplace_back(i);
            phi[i] = i - 1;
        }
        for (auto j : prime) {
			if (i * j > n) break;
            flg[i * j] = 1;
            if (i % j == 0) {
                phi[i * j] = phi[i] * j;
                break;
            }
            phi[i * j] = phi[i] * (j - 1);
        }
    }
}

int val[MAXN];

int calc(int x) {
	if (val[x]) return val[x];
	int ans = 0;
    if (x & 1) ans = x * qpow(k, (x + 1) >> 1) % MOD;
    else ans = (x >> 1) * (k + 1) % MOD * qpow(k, x >> 1) % MOD;
	for (auto t : fac[x]) {
		ans -= calc(t) * phi[x / t];
		ans = (ans % MOD + MOD) % MOD;
	}
	return val[x] = ans;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("palindrome.in", "r", stdin);
	freopen("palindrome.out", "w", stdout);
#endif
#endif
	cin >> n >> k;
	sieve();
	rep (i, 1, n) {
		for (int j = 2; i * j <= n; j ++) {
			fac[i * j].emplace_back(i);
		}
	}
	int ans = 0;
	rep (i, 1, n) {
		ans = (ans + calc(i)) % MOD;
	}
	print(ans);
	return 0;
}