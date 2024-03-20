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

const int MAXN = 5e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m, a[MAXN], b[MAXN], X;
int vala[MAXN], valb[MAXN];
int sa, sb;

signed main() {
	n = read(), m = read(), X = read();
	rep (i, 1, n) {
		a[i] = read();
        sa += a[i] / X;
        a[i] %= X;
    }
	rep (i, 1, m) {
		b[i] = read();
        sb += b[i] / X;
        b[i] %= X;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    if (sa < sb) {
        int cnt = (sb - sa) % n;
        rep (i, n - cnt + 1, n) a[i] -= X;
        sort(a + 1, a + n + 1);
        int minVal = a[1];
		rep (i, 1, n) a[i] -= minVal;
    }
    else if (sb < sa) {
        int cnt = (sa - sb) % m;
       	rep (i, m - cnt + 1, m) b[i] -= X;
        sort(b + 1, b + m + 1);
        int minVal = b[1];
		rep (i, 1, m) b[i] -= minVal;
    }
    vala[0] = a[n] - a[1];
    valb[0] = b[m] - b[1];
    rep (i, 1, n - 1) vala[i] = a[n - i] - a[n - i + 1] + X;
    rep (i, 1, m - 1) valb[i] = b[m - i] - b[m - i + 1] + X;
    int d = __gcd(n, m);
    int ans = (INF << 1);
	rep (r, 0, d - 1) {
        int mna = INF, mnb = INF;
        for (int i = r; i < n; i += d) mna = min(mna, vala[i]);
        for (int i = r; i < m; i += d) mnb = min(mnb, valb[i]);
        ans = min(ans, mna + mnb);
    }
	print(ans);
    return 0;
}
