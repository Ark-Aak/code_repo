#include <bits/stdc++.h>

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


const int MAXN = 2005;
int n, m, a[MAXN][MAXN];
bitset <MAXN> p[MAXN];

signed main() {
	n = read(), m = read();
	rep (i, 1, n) {
		rep (j, 1, m) a[i][j] = read();
	}
	rep (i, 1, m) {
        bitset <MAXN> now[MAXN];
        rep (j, 1, n) now[a[j][i]][j] = 1;
        rep (j, 1, n) p[j] = p[j] ^ now[a[j][i]];
    }
    int sum = 0;
	rep (i, 1, n) {
		rep (j, 1, n) {
            if (i == j) continue;
            sum += p[i][j];
        }
    }
	print(sum / 2);
	return 0;
}
