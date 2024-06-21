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

const int MAXN = 2e5 + 5;
vector <tuple <int, int, int> > v;
bitset <MAXN> l, r;
int ans[MAXN];
int n, m, q;

signed main() {
    n = read(), m = read(), q = read();
	rep (i, 1, n) v.push_back(dk(1, i, 0));
    while (q --> 0) {
        int x = read(), y = read(), z = read();
        v.push_back(dk(x, y, z));
    }
    reverse(v.begin(), v.end());
    int ta = 0, tb = 0;
    for (auto [op, y, z] : v) {
        if (op == 1) {
            if (l[y]) continue;
            ans[z] += m - tb;
            l[y] = 1; ta++;
        }
        else {
            if (r[y]) continue;
            ans[z] += n - ta;
            r[y] = 1; tb++;
        }
    }
    vector <pii> tans;
    for (int i = 0; i < MAXN; i++) if (ans[i]) tans.push_back(make_pair(i, ans[i]));
    sort(tans.begin(), tans.end());
    print(tans.size()), puts("");
    for (auto k : tans) {
        print(k.first), putchar(32);
        print(k.second), puts("");
    }
    return 0;
}
