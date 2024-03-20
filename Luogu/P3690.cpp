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
int n, m;

namespace LCT {

	int rt, tot, fa[MAXN], ch[MAXN][2], val[MAXN], cnt[MAXN], siz[MAXN];
	int id[MAXN];

#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
#define get(x) ((x) == ch[fa[x]][1])
#define isRoot(x) (ch[fa[x]][0] != x && ch[fa[x]][1] != x)

	void pushup(int x) {
		siz[x] = siz[ls(x)] + siz[rs(x)] + cnt[x];
		id[x] = val[id[ls(x)]] > val[id[rs(x)]] ? id[ls(x)] : id[rs(x)];
		if (val[x] > val[id[x]]) id[x] = x;
	}

	int tag[MAXN];

	void rev(int x) {
		swap(ls(x), rs(x)), tag[x] ^= 1;
	}

	void pushdown(int x) {
		if (tag[x]) {
			if (ls(x)) rev(ls(x));
			if (rs(x)) rev(rs(x));
			tag[x] = 0;
		}
	}

	void clear(int x) {
		ls(x) = rs(x) = fa[x] = val[x] = siz[x] = cnt[x] = 0;
	}

	void rotate(int x) {
		int y = fa[x], z = fa[y], tp = get(x);
		if (!isRoot(y)) ch[z][ch[z][1] == y] = x;
		ch[y][tp] = ch[x][tp ^ 1], fa[ch[x][tp ^ 1]] = y;
		ch[x][tp ^ 1] = y;
		fa[y] = x, fa[x] = z;
		pushup(y), pushup(x);
	}

	void pushall(int x) {
		if (!isRoot(x)) pushall(fa[x]);
		pushdown(x);
	}

	void splay(int x) {
		pushall(x);
		for (int f = fa[x]; (f = fa[x]), !isRoot(x); rotate(x))
			if (!isRoot(f)) rotate(get(x) == get(f) ? f : x);
	}

	int access(int x, int p = 0) {
		for (p = 0; x; p = x, x = fa[x])
			splay(x), rs(x) = p, pushup(x);
		return p;
	}

	void makeRoot(int x) {
		access(x), splay(x), rev(x);
	}

} // namespace LCT

int main() {
	n = read(), m = read();
	while (m --> 0) {

	}
	return 0;
}
