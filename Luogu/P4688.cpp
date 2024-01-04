#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int len;
const int MAXN = 1e5 + 5, MAXM = MAXN / 3 + 10;

#define which(x) ((x) / len)

struct Query {
	int l, r, id;

	bool operator <(const Query &t) const {
		if (which(l) != which(t.l)) return l < t.l;
		return which(l) & 1 ? r < t.r : r > t.r;
	}
} q[MAXM * 3];

int n, m, a[MAXN], cnt[MAXN], ans[MAXN];
bitset <MAXN> sum[MAXM], now;

void add(int x) {
	now[x + cnt[x]] = 1;
	cnt[x]++;
}

void del(int x) {
	cnt[x]--;
	now[x + cnt[x]] = 0;
}

void solve(int deb) {
	int cnt = 0, tot = 0;
	now.reset();
	for (tot = 1; m && tot <= MAXM - 4; tot++, m--) {
		ans[tot] = 0;
		sum[tot].set();
		rep (j, 1, 3) {
			++cnt;
			read(q[cnt].l), read(q[cnt].r);
			q[cnt].id = tot;
			ans[tot] += q[cnt].r - q[cnt].l + 1;
		}
	}
	--tot;
	sort(q + 1, q + 1 + cnt);

	for (int i = 1, l = 1, r = 0; i <= cnt; i++) {
		while (l > q[i].l) add(a[--l]);
		while (r < q[i].r) add(a[++r]);
		while (l < q[i].l) del(a[l++]);
		while (r > q[i].r) del(a[r--]);
		sum[q[i].id] &= now;
	}
	rep (i, 1, tot) {
		print(ans[i] - 3 * sum[i].count()), putchar(10);
	}
}

vector <int> h;

int main() {
	read(n), read(m);
	len = sqrt(n);
	rep (i, 1, n) read(a[i]), h.push_back(a[i]);
	sort(h.begin(), h.end());
	rep (i, 1, n) a[i] = lower_bound(h.begin(), h.end(), a[i]) - h.begin() + 1;
	solve(1);
	memset(cnt, 0, sizeof cnt);
	solve(2);
	memset(cnt, 0, sizeof cnt);
	solve(3);
	return 0;
}
