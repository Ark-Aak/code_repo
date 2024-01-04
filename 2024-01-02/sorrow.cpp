#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

const int MAXN = 2e5 + 5;
const int B = 450;
int n, q, a[MAXN], bel[MAXN], bk, len;
int d[MAXN], sum[B + 5], sumd[B + 5], sm[B + 5][MAXN], L[MAXN], R[MAXN];

int query(int x, int res = 0) {
	int now = bel[x];
    rep (i, 0, now - 1) res += sumd[i] * (x + 1) - sum[i];
    rep (i, L[now], x) res += d[i] * (x + 1 - i);
    return res;
}

int solve(int l, int r) {
    int ans = 0;
    rep (i, 1, bk - 1) {
        int lx = l % i, rx = i - 1, tot = 0;
        if (l + (rx - lx) >= r) {
            tot += (r - l + 1);
            ans += sm[i][lx + (r - l)] - sm[i][lx - 1];
            continue;
        }
		else {
            tot += rx - lx + 1;
            ans += sm[i][rx] - sm[i][lx - 1];
        }
        ans += sm[i][i] * ((r - (l + rx - lx)) / i);
        tot += (r - (l + rx - lx)) / i * i;
        if (tot < (r - l + 1)) {
            lx = 0, rx = r % i;
            ans += sm[i][rx];
        }
    }
    return ans + query(r) - query(l - 1);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("sorrow.in", "r", stdin);
	freopen("sorrow.out", "w", stdout);
#endif
#endif
	n = read(), q = read();
	rep (i, 1, n) a[i] = read();
	memset(L, 0x3f, sizeof L);
	len = sqrt(n + 1);
	bk = (n + 1) / len;
	if((n + 1) % len) bk++;
    rep (i, 1, n) d[i] = a[i] - a[i - 1];
    rep (i, 0, bk) {
        L[i] = i * len;
		R[i] = min((i + 1) * len - 1, n);
		rep (j, L[i], R[i]) {
            bel[j] = i;
            sumd[i] += d[j];
            sum[i] += d[j] * j;
        }
    }
	while (q --> 0) {
		int op = read();
		if (op ^ 2) {
			int k = read(), l = read(), r = read(), x = read();
			if (k >= len) {
				for (int i = 0; i + l <= n; i += k) {
					d[i + l] += x;
					if (i + r < n) d[i + r + 1] -= x;
					sumd[bel[i + l]] += x;
					if (i + r < n) sumd[bel[i + r + 1]] -= x;
					sum[bel[i + l]] += x * (i + l);
					if (i + r < n) sum[bel[i + r + 1]] -= x * (i + r + 1);
				}
			}
			else {
				rep (i, l, r) sm[k][i] += (i - l + 1) * x;
				rep (i, r + 1, k) sm[k][i] += (r - l + 1) * x;
			}
		}
		else {
			int l = read(), r = read();
			print(solve(l, r)), putchar(10);
		}
	}
	return 0;
}
