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

struct element {
	int a, b, c;
	int res, cnt;
	bool operator != (element t) {
		if (a != t.a) return true;
		if (b != t.b) return true;
		if (c != t.c) return true;
		return false;
	}
} e[MAXN], ue[MAXN];

int sum[MAXN], m, n, k, ans[MAXN];

int lowbit(int x) {
	return x & -x;
}

void add(int x, int val) {
	while (x < MAXN) sum[x] += val, x += lowbit(x);
}

int query(int x) {
	int s = 0;
	while (x) s += sum[x], x -= lowbit(x);
	return s;
}

void CDQ(int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;
	CDQ(l, mid), CDQ(mid + 1, r);
	sort(ue + l, ue + mid + 1, [](element a, element b) {
		return a.b == b.b ? a.c < b.c : a.b < b.b;
	});
	sort(ue + mid + 1, ue + r + 1, [](element a, element b) {
		return a.b == b.b ? a.c < b.c : a.b < b.b;	
	});
	int i = l, j = mid + 1;
	while (j <= r) {
		while (i <= mid && ue[i].b <= ue[j].b) add(ue[i].c, ue[i].cnt), i++;
		ue[j].res += query(ue[j].c), j++;
	}
	rep (k, l, i - 1) add(ue[k].c, -ue[k].cnt);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	rep (i, 1, n) cin >> e[i].a >> e[i].b >> e[i].c;
	sort(e + 1, e + 1 + n, [](element a, element b) {
		return a.a == b.a ? a.b == b.b ? a.c < b.c : a.b < b.b : a.a < b.a;
	});
	int tmp = 0;
	rep (i, 1, n) {
		tmp++;
		if (e[i] != e[i + 1]) {
			m++;
			ue[m].a = e[i].a;
			ue[m].b = e[i].b;
			ue[m].c = e[i].c;
			ue[m].cnt = tmp;
			tmp = 0;
		}
	}
	CDQ(1, m);
	rep (i, 1, m) ans[ue[i].res + ue[i].cnt - 1] += ue[i].cnt;
	rep (i, 0, n - 1) cout << ans[i] << endl;
	return 0; 
}
