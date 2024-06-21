#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

bool stmer;

namespace fastio
{
    const int bufl=1<<20;
    const double base1[16]={1,1e-1,1e-2,1e-3,1e-4,1e-5,1e-6,1e-7,1e-8,1e-9,1e-10,1e-11,1e-12,1e-13,1e-14,1e-15};
    const double base2[16]={1,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9,1e10,1e11,1e12,1e13,1e14,1e15};
    struct IN{
        FILE *IT;char ibuf[bufl],*is=ibuf,*it=ibuf;
        IN(){IT=stdin;}IN(char *a){IT=fopen(a,"r");}
        inline char getChar(){if(is==it){it=(is=ibuf)+fread(ibuf,1,bufl,IT);if(is==it)return EOF;}return *is++;}
        template<typename Temp>inline void getInt(Temp &a){a=0;int b=0,c=getChar();while(c<48||c>57)b^=(c==45),c=getChar();while(c>=48&&c<=57)a=(a<<1)+(a<<3)+c-48,c=getChar();if(b)a=-a;}
        template<typename Temp>inline void getDouble(Temp &a){a=0;int b=0,c=getChar(),d=0;__int128 e=0,f=0;while(c<48||c>57)b^=(c==45),c=getChar();while(c>=48&&c<=57)e=(e<<1)+(e<<3)+c-48,c=getChar();if(c==46){c=getChar();while(c>=48&&c<=57)d++,f=(f<<1)+(f<<3)+c-48,c=getChar();}a=e+base1[d]*f;if(b)a=-a;}
        IN& operator>>(char &a){a=getChar();return *this;}
        IN& operator>>(char *a){do{*a=getChar();}while(*a<=32);while(*a>32)*++a=getChar();*a=0;return *this;}
        IN& operator>>(string &a){char b=getChar();while(b<=32)b=getChar();while(b>32)a+=b,b=getChar();return *this;}
        IN& operator>>(int &a){getInt(a);return *this;}
        IN& operator>>(long long &a){getInt(a);return *this;}
        IN& operator>>(__int128 &a){getInt(a);return *this;}
        IN& operator>>(float &a){getDouble(a);return *this;}
        IN& operator>>(double &a){getDouble(a);return *this;}
        IN& operator>>(long double &a){getDouble(a);return *this;}
    };
}
using fastio::IN;
IN fin;

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 5e5 + 5;

int mod, n, m, q;
int pw[MAXN], pre[MAXN];
i128 mu;

inline ll reduce(i128 x) {
	i128 r = x - (mu * x >> 64) * mod;
	return r;
}

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define ls(x) p[x].ls
#define rs(x) p[x].rs

struct node { int val, key, siz, ls, rs, sum, lazy, h; } p[MAXN * 11];
int cnt = 0, root[15];

int Rnd(int l, int r) {
	return abs((int) rnd()) % (r - l + 1) + l;
}

namespace Treap {

	inline int newNode(int val) {
		int x = ++cnt;
		p[x].val = p[x].sum = val, p[x].key = rnd(), p[x].siz = 1;
		p[x].ls = p[x].rs = p[x].lazy = 0;
		p[x].h = val;
		return x;
	}

	void pushup(int x) {
		p[x].sum = reduce(1ll * p[ls(x)].sum + p[rs(x)].sum + p[x].val);
		p[x].siz = p[ls(x)].siz + p[rs(x)].siz + 1;
		p[x].h = reduce(1ll * p[ls(x)].h * pw[0] + p[x].val);
		p[x].h = reduce(1ll * p[x].h * pw[p[rs(x)].siz] + p[rs(x)].h);
	}

	void add(int x, int val) {
		p[x].val = reduce(1ll * p[x].val + val);
		p[x].sum = reduce(1ll * p[x].sum + reduce(1ll * val * p[x].siz));
		p[x].lazy = reduce(1ll * p[x].lazy + val);
		p[x].h = reduce(1ll * pre[p[x].siz - 1] * val + p[x].h);
	}

	void pushdown(int x) {
		if (!x) return;
		if (p[x].lazy) {
			if (ls(x)) add(ls(x), p[x].lazy);
			if (rs(x)) add(rs(x), p[x].lazy);
			p[x].lazy = 0;
		}
	}

	void split(int cur, int k, int &x, int &y) {
		if (!cur) return x = y = 0, void();
		pushdown(cur);
		if (p[ls(cur)].siz < k) x = cur, split(rs(cur), k - p[ls(cur)].siz - 1, rs(cur), y);
		else y = cur, split(ls(cur), k, x, ls(cur));
		pushup(cur);
	}

	int merge(int x, int y) {
		if (!x || !y) return x + y;
		if (p[x].key < p[y].key) return pushdown(x), rs(x) = merge(rs(x), y), pushup(x), x;
		else return pushdown(y), ls(y) = merge(x, ls(y)), pushup(y), y;
	}

	void build(int &root, vector <int> v) {
		for (auto i : v) root = merge(root, newNode(i));
	}

	void add(int &root, int L, int R, int val) {
		int x = 0, y = 0, z = 0;
		split(root, L - 1, x, y);
		split(y, R - L + 1, y, z);
		add(y, val);
		root = merge(merge(x, y), z);
	}

	int sum(int &root, int L, int R) {
		int x = 0, y = 0, z = 0;
		split(root, L - 1, x, y);
		split(y, R - L + 1, y, z);
		int res = p[y].sum;
		root = merge(merge(x, y), z);
		return res;
	}

	void swap(int &x, int &y, int L, int R) {
		int X0 = 0, Y0 = 0, Z0 = 0;
		split(x, L - 1, X0, Y0);
		split(Y0, R - L + 1, Y0, Z0);
		int X1 = 0, Y1 = 0, Z1 = 0;
		split(y, L - 1, X1, Y1);
		split(Y1, R - L + 1, Y1, Z1);
		x = merge(merge(X0, Y1), Z0);
		y = merge(merge(X1, Y0), Z1);
	}

	int qh(int &root, int L, int R) {
		int x = 0, y = 0, z = 0;
		split(root, L - 1, x, y);
		split(y, R - L + 1, y, z);
		int res = p[y].h;
		root = merge(merge(x, y), z);
		return res;
	}
}

bool edmer;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("remember.in", "r", stdin);
	freopen("remember.out", "w", stdout);
#endif
#endif
	cerr << (&stmer - &edmer) / 1024.0 / 1024.0 << "MB" << endl;
	fin >> n >> m >> q >> mod;
	mu = (i128) (((i128) 1) << 64) / mod;
	pw[0] = pre[0] = 1;
	rep (i, 1, n) pw[i] = reduce(1ll * pw[i - 1] * 2);
	rep (i, 1, n) pre[i] = reduce(1ll * pre[i - 1] + pw[i]);
	rep (i, 1, m) {
		vector <int> v;
		int x;
		rep (j, 1, n) fin >> x, v.push_back(x);
		Treap::build(root[i], v);
	}
	rep (i, 1, q) {
		int op;
		fin >> op;
		if (op == 1) {
			int x, l, r;
			fin >> x >> l >> r;
			print(Treap::sum(root[x], l, r)), puts("");
		}
		else if (op == 2) {
			int x, l, r, f;
			fin >> x >> l >> r >> f;
			if (r - l + 1 <= f) {
				puts("where is self?");
				continue;
			}
			bool flg = 0;
			if (r - l + 1 <= 0) {
				rep (i, l, r - f) {
					int ps = i;
					int sum = Treap::sum(root[x], ps, ps + f - 1);
					int val = Treap::sum(root[x], ps + f, ps + f);
					if (sum != val) {
						flg = 1;
						puts("infinity loop!");
						break;
					}
				}
			}
			else {
				/*
				rep (i, 1, D) {
					int ps = Rnd(l, r - f);
					int sum = Treap::sum(root[x], ps, ps + f - 1);
					int val = Treap::sum(root[x], ps + f, ps + f);
					if (sum != val) {
						flg = 1;
						puts("infinity loop!");
						break;
					}
				}
				*/
				const int pt = Treap::qh(root[x], l + f, l + f);
				if (Treap::sum(root[x], l, l + f - 1) != pt) {
					flg = 1;
					puts("infinity loop!");
				}
				if (!flg) {
					int val = Treap::qh(root[x], l, r - f - 1);
					int len = reduce(1ll * pw[r - f - 1] * pt);
					if (reduce(reduce(len - val) + mod) != Treap::qh(root[x], r, r)) {
						flg = 1;
						puts("infinity loop!");
					}
				}
			}
			if (flg) continue;
			puts("where is self?");
		}
		else if (op == 3) {
			int x, l, r, k;
			fin >> x >> l >> r >> k;
			Treap::add(root[x], l, r, k);
		}
		else {
			int x, y, l, r;
			fin >> x >> y >> l >> r;
			Treap::swap(root[x], root[y], l, r);
		}
	}
	cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	return 0;
}
