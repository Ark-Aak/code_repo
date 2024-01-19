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
const int B = 1028;

#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
#define get(x) ((x) == ch[fa[(x)]][1])

class Splay {

	int rt, tot, fa[B + 5], ch[B + 5][2], val[B + 5], cnt[B + 5], siz[B + 5];

	void pushup(int x) { siz[x] = siz[ls(x)] + siz[rs(x)] + cnt[x]; }
	void clear(int x) { ls(x) = rs(x) = fa[x] = val[x] = siz[x] = cnt[x] = 0;}
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

	int toRoot(int x) {
		int cur = rt;
		while (1) {
			if (x < val[cur]) cur = ls(cur);
			else {
				if (x == val[cur]) return splay(cur), cur;
				if (!rs(cur)) { if (cur) splay(cur); return cur; }
				cur = rs(cur);
			}
		}
		return cur;
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


	int merge(int x, int y) {
		if (!x || !y) return x + y;
		int cur = x, mx = val[x];
		while (rs(cur)) cur = rs(cur), mx = max(val[cur], mx);
		int rt = toRoot(mx);
		rs(rt) = y, fa[y] = rt;
		pushup(rt);
		return rt;
	}

	void del(int x) {
		toRoot(x);
		if (cnt[rt] > 1) return (void) (cnt[rt]--, pushup(rt));
		if (!ls(rt) && !rs(rt)) return (void) (clear(rt), rt = 0);
		if (!ls(rt)) {
			int cur = rt;
			rt = rs(rt), fa[rt] = 0;
			return clear(cur);
		}
		if (!rs(rt)) {
			int cur = rt;
			rt = ls(rt), fa[rt] = 0;
			return clear(cur);
		}
		int tmp = rt;
		rt = merge(ls(rt), rs(rt));
		clear(tmp);
	}

} splay[2005];

int main() {

	return 0;
}
