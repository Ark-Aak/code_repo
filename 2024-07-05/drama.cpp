#include<bits/stdc++.h>

#define rep(i, a, b) for (auto i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (auto i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, w = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') w = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = x * 10 + (c ^ 48);
		c = getchar();
	}
	return  x * w;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

const int MAXN = 1e5 + 5;
int n, m, a[MAXN];
int f[MAXN][130];
vector <int> perms[130];
const int MOD = 998244353;

int h(vector <int> &v) {
	int sum = 0;
	for (auto x : v) sum = (sum * 10) + x;
	return sum;
}

int rnk[1000005];

signed main() {
#ifndef LOCAL
	freopen("drama.in", "r", stdin);
	freopen("drama.out", "w", stdout);
#endif
	n = read(), m = read();
	int fac = 1;
	rep (i, 2, n) fac *= i;
	rep (i, 1, n) a[i] = i;
	int id = 0;
	do {
		id++;
		vector <int> vec;
		rep (i, 1, n) vec.push_back(a[i]);
		perms[id] = vec;
		rnk[h(vec)] = id;
	} while (next_permutation(a + 1, a + 1 + n));
	f[0][1] = 1;
	rep (i, 0, m - 1) {
		rep (j, 1, fac) {
			vector <int> v = perms[j];
			f[i + 1][j] = (f[i + 1][j] + f[i][j]) % MOD;
			int p = 0;
			rep (k, 1, n - 1) {
				swap(v[p], v[p + 1]);
				p++;
				const int _rnk = rnk[h(v)];
				f[i + 1][_rnk] =  (f[i + 1][_rnk] + f[i][j]) % MOD;
			}
		}
	}
	cout << f[m][1] << endl;
	return 0;
}
