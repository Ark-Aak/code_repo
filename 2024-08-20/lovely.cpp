#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define ec first
#define fb second
#define de(x) cerr << #x << " = " << (x) << endl

using namespace std;

typedef long long ll;
typedef __int128 lll;
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


#define PRIMEN 16

int prime[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 61, 1215, 34862, 574237825};

mt19937_64 rnd(time(0));

__int128 myabs(__int128 a) {
	return a >= 0 ? a : -a;
}


int mul(int a, int b, int mod) {
	int res = 0;
	while (b) {
		if (b & 1) res = (res + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return res % mod;
}

lll qpow(ll a, ll b, ll mod) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (lll) res * a % mod;
		a = (lll) a * a % mod;
		b >>= 1;
	}
	return res % mod;
}

bool Miller_Rabin(int n, int p) {
	if (n == 1) return false;
	ll d = n - 1, r = 0;
	while(!(d & 1)) d >>= 1, r++;
	int z = qpow(p, d, n);
	if (z == 1) return true;
	rep (i, 1, r) {
	    if(z == n - 1) return true;
	    z = mul(z, z, n);
	}
	return false;
}

bool isPrime(lll n) {
	rep (i, 0, PRIMEN - 1) {
		if (n == prime[i]) return true;
		if (n % prime[i] == 0) return false;
		if (!Miller_Rabin(n, prime[i])) return false;
	}
	return true;
}

int f(int x, int c, int mod) {
	return ((lll) x * x % mod + c) % mod;
}

int PollardRho(int x) {
	int s = 0, t = 0, c = rnd() % (x - 1) + 1;
	int target = 1, val = 1, cnt = 0;
	for (target = 1; ; target <<= 1, s = t, val = 1) {
		rep(i, 1, target) {
			cnt++;
			t = f(t, c, x);
			val = (lll) val * myabs(t - s) % x;
			if (cnt % 127 == 0) {
				int gcd = __gcd(val, x);
				if (gcd > 1) return gcd;
			}
		}
		int gcd = __gcd(val, x);
		if (gcd > 1) return gcd;
	}
}

vector <pii> tp_ans;

void work(int x, int c) {
	if (x < 2) return;
	if (isPrime(x)) {
		tp_ans.push_back(dl(x, c));
		return;
	}
	int p = x, cnt = 0;
	while (p >= x) p = PollardRho(x);
	while ((x % p) == 0 ) x /= p, cnt++;
	work(x, c), work(p, c * cnt);
}

const int MAXN = 2e5 + 5;
int n;
vector <vector <pii> > fac;

map <vector <pii>, int> col;
int cid[MAXN], inv[MAXN];
int cnt, ans, buc[MAXN];

int getInv(vector <pii> &v) {
	vector <pii> inv;
	for (auto [x, y] : v) {
		inv.push_back(dl(x, 3 - y));
	}
	return col.find(inv) == col.end() ? -1 : col[inv];
}

bool pcd[MAXN];

void merge() {
	if (tp_ans.size() == 0) return;
	sort(tp_ans.begin(), tp_ans.end());
	int lst = tp_ans[0].ec, tot = 0;
	vector <pii> res;
	for (auto [fac, cnt] : tp_ans) {
		if (fac != lst) {
			if (tot % 3 != 0) res.push_back(dl(lst, tot % 3));
			tot = 0;
		}
		lst = fac, tot += cnt;
	}
	if (tot % 3) res.push_back(dl(lst, tot % 3));
	res.swap(tp_ans);
}

signed main() {
	n = read();
	rep (i, 1, n) {
		int a = read();
		tp_ans.clear();
		work(a, 1);
		merge();
		fac.push_back(tp_ans);
	}
	for (auto vec : fac) {
		if (col.find(vec) == col.end()) {
			col[vec] = ++cnt;
		}
	}
	rep (i, 1, n) cid[i] = col[fac[i - 1]], inv[i] = getInv(fac[i - 1]);
	rep (i, 1, n) buc[cid[i]]++;
	const int emptyId = col[vector <pii>()];
	rep (i, 1, n) {
		if (inv[i] == -1) { ans++; continue; }
		if (pcd[cid[i]]) continue;
		if (cid[i] == emptyId) { ans++, pcd[emptyId] = 1; continue; }
		ans += max(buc[cid[i]], buc[inv[i]]);
		pcd[cid[i]] = pcd[inv[i]] = 1;
	}
	print(ans), puts("");
	return 0;
}
