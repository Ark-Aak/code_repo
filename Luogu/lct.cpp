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
int tag[MAXN];

#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
#define get(x) ((x) == ch[fa[(x)]][1])

void pushup(int x) {
	siz[x] = siz[ls(x)] + siz[rs(x)] + cnt[x];
}

void pushdown(int x) {

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



int main() {

	return 0;
}
