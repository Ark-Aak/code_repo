#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 305;
const int MOD = 1e9 + 7;
string s;
bitset <MAXN> vis;
int len[MAXN], cnt, f[2][MAXN][MAXN][MAXN];
int suf[2][MAXN], sum[MAXN][MAXN][MAXN];

signed main() {
	cin >> s;
	const int n = s.size();
	reverse(s.begin(), s.end());
	s = ' ' + s;
	rep (i, 1, n) {
		if (vis[i]) continue;
		if (s[i] == '0') return puts("0"), 0;
		len[++cnt] = 1;
		rep (j, i + 1, n) {
			if (vis[j]) continue;
			if ((s[j] == 48) != (len[cnt] & 1)) continue;
			len[cnt]++, vis[j] = 1;
		}
	}
	/* cout << cnt << endl; */
	rep (i, 1, n) suf[0][i] = suf[0][i - 1] + len[i] / 2;
	rep (i, 1, n) suf[1][i] = suf[1][i - 1] + (len[i] + 1) / 2;
	f[1][n][0][0] = 1;
	int ans = 0;
	rep (i, 1, n) {
		const int id = n / max(1ll, i - 1);
		memset(sum[id + 1], 0, sizeof sum[id + 1]);
		_rep (j, id, 1) {
			memcpy(f[0][j], f[1][j], sizeof f[0][j]);
			memcpy(sum[j], f[0][j], sizeof sum[j]);
			memset(f[1][j], 0, sizeof f[1][j]);
			rep (a, 0, n) {
				rep (b, 0, n) {
					sum[j][a][b] = (sum[j][a][b] + sum[j + 1][a][b]) % MOD;
				}
			}
		}
		rep (j, 1, n / i) {
			rep (a, j / 2, suf[0][i]) {
				rep (b, (j + 1) / 2, suf[1][i]) {
					f[1][j][a][b] = sum[j][a - j / 2][b - (j + 1) / 2];
				}
			}
		}
		if (i < cnt) continue;
		rep (j, 1, n / i) ans = (ans + f[1][j][suf[0][i]][suf[1][i]]) % MOD;
	}
	print(ans);
	return 0;
}
