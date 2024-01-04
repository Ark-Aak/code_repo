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

const int MAXN = 1e5 + 5;
int rt, tot, fa[MAXN], ch[MAXN][2], val[MAXN], cnt[MAXN], siz[MAXN];

#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
#define get(x) ((x) == ch[fa[(x)]][1])

void pushup(int x) {
	siz[x] = siz[ls(x)] + siz[rs(x)] + cnt[x];
}

void clear(int x) {
	ls(x) = rs(x) = fa[x] = val[x] = siz[x] = cnt[x] = 0;
}

void rotate(int x) {
	int y = fa[x], z = fa[y], tp = get(x);
	ch[y][tp] = ch[x][tp ^ 1];
	if (ch[x][tp ^ 1]) fa[ch[x][tp ^ 1]] = y;
	ch[x][tp ^ 1] = y;
	fa[y] = x, fa[x] = z;
	if (z) ch[z][y == rs(z)] = x;
	pushup(y), pushup(x);
}

void splay(int x) {
	for (int f = fa[x]; (f = fa[x]); rotate(x))
		if (fa[f]) rotate(get(x) == get(f) ? f : x);
	rt = x;
}

void insert(int x) {
	if (!rt) {
		val[++tot] = x; cnt[tot]++;
		rt = tot; pushup(rt);
		return;
	}
	int cur = rt, f = 0;
	while (1) {
		if (val[cur] == x) {
			cnt[cur]++;
			pushup(cur), pushup(f);
			splay(cur); break;
		}
		f = cur, cur = ch[cur][val[cur] < x];
		if (!cur) {
			val[++tot] = x; cnt[tot]++;
			fa[tot] = f, ch[f][val[f] < x] = tot;
			pushup(tot), pushup(f);
			splay(tot); break;
		}
	}
}

int rnk(int x) {
	int res = 0, cur = rt;
	while (1) {
		if (x < val[cur]) cur = ls(cur);
		else {
			res += siz[ls(cur)];
			if (val[cur] == x)
				return splay(cur), res + 1;
			res += cnt[cur];
			if (!rs(cur)) {
				if (cur) splay(cur);
				return res + 1;
			}
			cur = rs(cur);
		}
	}
}

int kth(int x) {
	int cur = rt;
	while (1) {
		if (ls(cur) && x <= siz[ls(cur)]) cur = ls(cur);
		else {
			x -= cnt[cur] + siz[ls(cur)];
			if (x <= 0) return splay(cur), val[cur];
			cur = rs(cur);
		}
	}
}

void toRoot(int x) {
	int cur = rt;
	while (1) {
		if (x < val[cur]) cur = ls(cur);
		else {
			if (x == val[cur]) return splay(cur);
			if (!rs(cur)) return;
			cur = rs(cur);
		}
	}
}

int pre() {
	int cur = ls(rt);
	if (!cur) return cur;
	while (rs(cur)) cur = rs(cur);
	splay(cur);
	return cur;
}

int nxt() {
	int cur = rs(rt);
	if (!cur) return cur;
	while (ls(cur)) cur = ls(cur);
	splay(cur);
	return cur;
}

void del(int x) {
	toRoot(x);
	if (cnt[rt] > 1) {
		cnt[rt]--;
		pushup(rt);
		return;
	}
	if (!ls(rt) && !rs(rt)) {
		clear(rt);
		rt = 0;
		return;
	}
	if (!ls(rt)) {
		int cur = rt;
		rt = rs(rt), fa[rt] = 0;
		clear(cur);
		return;
	}
	if (!rs(rt)) {
		int cur = rt;
		rt = ls(rt), fa[rt] = 0;
		clear(cur);
		return;
	}
	int cur = rt, t = pre();
	fa[rs(cur)] = t;
	rs(t) = rs(cur);
	clear(cur), pushup(rt);
}

int main() {
	int n, opt, x;
	for (scanf("%d", &n); n; --n) {
		scanf("%d%d", &opt, &x);
		if (opt == 1) insert(x);
		else if (opt == 2) del(x);
		else if (opt == 3) printf("%d\n", rnk(x));
		else if (opt == 4) printf("%d\n", kth(x));
		else if (opt == 5) insert(x), printf("%d\n", val[pre()]), del(x);
		else insert(x), printf("%d\n", val[nxt()]), del(x);
	}
	return 0;
}
