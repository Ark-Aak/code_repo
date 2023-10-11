#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MAXN = 2e5 + 5;
int n, b[MAXN], g[MAXN];
int re[MAXN], le[MAXN];

struct node {
	int l, r, id;
} p[MAXN];

int cnt[MAXN];

int lowbit(int x) {
	return x & -x;
}

void add(int x, int val) {
	while (x < MAXN) cnt[x] += val, x += lowbit(x);
}

int query(int x) {
	int sum = 0;
	while (x) sum += cnt[x], x -= lowbit(x);
	return sum;
}

int ans = 0;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("gather.in", "r", stdin);
	freopen("gather.out", "w", stdout);
#endif
#endif
	cin >> n;
	rep (i, 1, n) cin >> b[i], p[i].id = i;
	rep (i, 0, MAXN - 1) re[i] = n + 1;
	rep (i, 1, n) {
		p[i].l = le[b[i]];
		le[b[i]] = i;
	}
	_rep (i, n, 1) {
		p[i].r = re[b[i]];
		re[b[i]] = i;
	}
	//p[r].l < l, p[l].r > r的点对数量
	//if (n <= 5000) {
	//	rep (i, 1, n) {
	//		rep (j, i + 1, n) {
	//			if (p[j].l < i && p[i].r > j) ans++;
	//		}
	//	}
	//	cout << ans;
	//	return 0;
	//}
//	else {
		rep (r, 1, n) {
			ans += query(MAXN - 1) - query(p[r].l);
			cout << query(MAXN - 1) - query(p[r].l) << endl;
			cout << query(MAXN - 1) << " " << query(p[r].l) << endl;
			add(p[r].r, 1);
		}
		cout << ans;
//	}
	return 0;
}
