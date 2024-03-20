#include <bits/stdc++.h>

/* #define int ll */

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

namespace IO{

char ibuf[1 << 21], *p1 = ibuf, *p2 = ibuf;
char obuf[1 << 21], *p3 = obuf;

char getch() {
	return p1 == p2 && (p2 = ((p1 = ibuf) +
		fread(ibuf, 1, 1 << 21, stdin)), p1 == p2)
		? EOF : *p1++;
}

int read() {
	char ch = getch();
	int fl = 1, x = 0;
	while (!isdigit(ch)) {
		if(ch == '-') fl = -1;
		ch = getch();
	}
	while (isdigit(ch)) {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getch();
	}
	x *= fl;
	return x;
}

void flush() { fwrite(obuf, p3 - obuf, 1, stdout);}

void putch(char ch) {
	if (p3 - obuf < (1 << 21)) *p3++ = ch;
	else flush(), p3 = obuf, *p3++ = ch;
}

char stk[128];

template <typename _Tp>
void print(_Tp x) {
	if (!x) return putch('0');
	if (x < 0) putch('-'), x *= -1;
	int top = 0;
	while (x) stk[++top] = x % 10 + 48, x /= 10;
	while (top) putch(stk[top]), top--;
}

} // namespace IO

using namespace IO;

const int MAXN = 2e5 + 5, MAXM = MAXN << 5;

int n, m, a[MAXN];

namespace PSEG {

#define ls(x) mem[x].ls
#define rs(x) mem[x].rs
#define mid ((L + R) >> 1)
#define val(x) mem[x].sum

	struct node {
		int ls, rs, sum;
	} mem[MAXM];

	int cnt = 0;

	int get() { return ++cnt; }

	int insert(int x, int L, int R, int p, int val) {
		int nx = get();
		val(nx) = val(x) + val;
		ls(nx) = ls(x), rs(nx) = rs(x);
		if (L == R) return nx;
		if (p <= mid) ls(nx) = insert(ls(x), L, mid, p, val);
		else rs(nx) = insert(rs(x), mid + 1, R, p, val);
		return nx;
	}

	int query(int pl, int pr, int L, int R, int l, int r) {
		if (!(val(pr) - val(pl))) return 0;
		if (l <= L && R <= r) return val(pr) - val(pl);
		int res = 0;
		if (l <= mid) res += query(ls(pl), ls(pr), L, mid, l, r);
		if (r > mid) res += query(rs(pl), rs(pr), mid + 1, R, l, r);
		return res;
	}
} // namespace PSEG

int rt[MAXN];

const int MAXP = 1e9;

signed main() {
	n = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) rt[i] = PSEG::insert(rt[i - 1], 1, MAXP, a[i], a[i]);
	m = read();
	rep (i, 1, m) {
		int l = read(), r = read();
		int lst = 0, now = 0;
		while (1) {
			int tval = PSEG::query(rt[l - 1], rt[r], 1, MAXP, lst + 1, now + 1);
			if (!tval) break;
			lst = now + 1;
			now += tval;
		}
		print(now + 1), putch('\n');
	}
	flush();
	return 0;
}
