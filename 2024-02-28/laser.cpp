#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

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

const int MAXN = 4e3 + 5;
int n, m, q;
int h[300005], Q[300005];
int minh, minp, stt[300005], edt[300005], sm[300005];
int edd[300005], cc[300005];
vector <int> det[300005], pf[300005];

bool isminp(int x) {
	return (x % m == 0 ? m : x % m) == minp;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("laser.in", "r", stdin);
	freopen("laser.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), q = read();
	memset(stt, 0x3f, sizeof stt);
	minh = 1e18;
	if (q == 0) return 0;
	rep (i, 1, n) det[i].resize(m + 10);
	rep (i, 1, n) pf[i].resize(m + 10);
	rep (i, 1, m) {
		h[i] = read();
		if (minh > h[i]) minh = h[i], minp = i;
	}
	rep (i, 1, q) Q[i] = read();
	rep (i, 1, n) {
		int tick = ceil (minh * 1.0 / i);
		int height = (tick - 1) * i;
		int st = (tick % m == 0 ? m : tick % m);
		int sum = 0;
		int j = st, cnt = 0;
		cc[i] = tick;
		while (!(cnt && isminp(j))) {
			int pt = (j % m == 0 ? m : j % m);
			height += i;
			if (j - st + 1 <= m) pf[i][j - st + 1] = pf[i][j - st];
			if (edd[i] && j - edd[i] + 1 <= m) det[i][j - edd[i] + 1] = det[i][j - edd[i]];
			if (height > h[pt]) {
				if (isminp(j)) {
					cnt++;
					if (!edt[i]) {
						edt[i] = tick + j - st - 1, edd[i] = j;
					}
				}
				stt[i] = min(stt[i], tick + j - st);
				height = min(height, h[pt]);
				if (cnt) sum++, det[i][j - edd[i] + 1]++;
				else pf[i][j - st + 1]++;
			}
			j++;
		}
		sm[i] = sum;
	}
	rep (i, 1, q) {
		int ans = 0;
		rep (j, 1, n) {
			int t = Q[i];
			if (t < stt[j]) continue;
			if (t <= edt[j]) {
				ans += pf[j][t - cc[j] + 1];
				/* print(ans), putchar(10); */
				continue;
			}
			ans += pf[j][m];
			/* print(ans), putchar(10); */
			t -= edt[j];
			ans += (t / m) * sm[j];
			/* print(ans), putchar(10); */
			t %= m;
			ans += det[j][t];
			/* print(ans), putchar(10); */
		}
		print(ans), putchar(10);
	}
	return 0;
}
