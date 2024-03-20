#include <bits/stdc++.h>

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

const int MAXN = 1e3 + 5;

int n, m, a[MAXN][MAXN], p[5][5], ans[MAXN][MAXN];
string s;

signed main() {
    n = read(), m = read();
	rep (i, 1, n) rep (j, 1, n) cin >> a[i][j];
    cin >> s;
    p[1][1] = 1, p[1][2] = 2, p[1][3] = 3;
	for (auto op : s) {
        if (op == 'L') p[2][2]--;
        if (op == 'R') p[2][2]++;
        if (op == 'U') p[2][1]--;
        if (op == 'D') p[2][1]++;
        if (op == 'I') swap(p[1][2], p[1][3]), swap(p[2][2], p[2][3]);
        if (op == 'C') swap(p[1][1], p[1][3]), swap(p[2][1], p[2][3]);
    }
	rep (i, 1, n) {
        for (int j = 1, c1 = 0, c2 = 0, c3 = 0; j <= n; j++) {
            if (p[1][1] == 1) c1 = i;
            if (p[1][1] == 2) c1 = j;
            if (p[1][1] == 3) c1 = a[i][j];
            if (p[1][2] == 1) c2 = i;
            if (p[1][2] == 2) c2 = j;
            if (p[1][2] == 3) c2 = a[i][j];
            if (p[1][3] == 1) c3 = i;
            if (p[1][3] == 2) c3 = j;
            if (p[1][3] == 3) c3 = a[i][j];
            c1 += p[2][1]; c2 += p[2][2]; c3 += p[2][3];
            c1 = (c1 % n + n) % n == 0 ? n : (c1 % n + n) % n;
            c2 = (c2 % n + n) % n == 0 ? n : (c2 % n + n) % n;
            c3 = (c3 % n + n) % n == 0 ? n : (c3 % n + n) % n;
            ans[c1][c2] = c3;
        }
    }
	rep (i, 1, n) {
		rep (j, 1, n) print(ans[i][j]), putchar(32);
		putchar(10);
	}
    return 0;
}
