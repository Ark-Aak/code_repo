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

const int MAXN = 2e5 + 5;

int c[MAXN];
int f[MAXN][2][2];

void upd(int &x, int y) { x = min(x, y); }

signed main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = ' ' + s;
	memset(f, 0x3f, sizeof f);
	rep (i, 1, n) cin >> c[i];
    f[1][0][0] = 0, f[1][0][1] = c[1];
	rep (i, 2, n) {
        int ta = s[i] - '0', tb = s[i - 1] - '0';
        if (ta == tb) {
            upd(f[i][1][0], f[i - 1][0][0]);
            upd(f[i][0][1], f[i - 1][0][0] + c[i]);
            upd(f[i][1][1], f[i - 1][1][0] + c[i]);
            upd(f[i][0][0], f[i - 1][0][1]);
            upd(f[i][1][0], f[i - 1][1][1]);
            upd(f[i][1][1], f[i - 1][0][1] + c[i]);
        }
        else {
            upd(f[i][0][0], f[i - 1][0][0]);
            upd(f[i][1][0], f[i - 1][1][0]);
            upd(f[i][1][1], f[i - 1][0][0] + c[i]);
            upd(f[i][1][0], f[i - 1][0][1]);
            upd(f[i][0][1], f[i - 1][0][1] + c[i]);
            upd(f[i][1][1], f[i - 1][1][1] + c[i]);
        }
    }
    print(min(f[n][1][0], f[n][1][1]));
    return 0;
}
