#include <bits/stdc++.h>

#pragma GCC target("avx")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

typedef long long int ll;

using namespace std;

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

int K;
int n, q;

#define mid ((L+R)>>1)
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)

struct node{
	ll min,max;
	ll lazy;
} tree[200005 << 2];

struct node2{
	ll val;
	int id;
} a[200005];

void Build(int x, int L, int R){
	if(L == R){
		tree[x].max = a[L].val, tree[x].min = a[L].val;
		return;
	}
	Build(ls(x), L, mid); Build(rs(x), mid + 1, R);
	tree[x].max = max(tree[ls(x)].max, tree[rs(x)].max);
	tree[x].min = min(tree[ls(x)].min, tree[rs(x)].min);
}

void Modify(int x, int L, int R, int val){
	if(floor(tree[x].max / val) == floor(tree[x].min / val)){
		ll res = floor(tree[x].max / val) * val;
		tree[x].min -= res;
		tree[x].max -= res;
		tree[x].lazy -= res;
	}
	else{
		if(tree[x].lazy && L != R){
			tree[ls(x)].max += tree[x].lazy; tree[rs(x)].max += tree[x].lazy;
			tree[ls(x)].lazy += tree[x].lazy; tree[rs(x)].lazy += tree[x].lazy;
			tree[ls(x)].min += tree[x].lazy; tree[rs(x)].min += tree[x].lazy;
			tree[x].lazy = 0;
		}
		Modify(ls(x), L, mid, val);
		Modify(rs(x), mid + 1, R, val);
		tree[x].max = max(tree[ls(x)].max, tree[rs(x)].max);
		tree[x].min = min(tree[ls(x)].min, tree[rs(x)].min);
	}
}

void UpdateArray(int x, int L, int R){
	if(L == R){
		a[L].val = tree[x].max;
		return;
	}
	if(tree[x].lazy && L != R){
		tree[ls(x)].max += tree[x].lazy; tree[rs(x)].max += tree[x].lazy;
		tree[ls(x)].lazy += tree[x].lazy; tree[rs(x)].lazy += tree[x].lazy;
		tree[ls(x)].min += tree[x].lazy; tree[rs(x)].min += tree[x].lazy;
		tree[x].lazy = 0;
	}
	UpdateArray(ls(x), L, mid); UpdateArray(rs(x), mid + 1, R);
	tree[x].max = max(tree[ls(x)].max, tree[rs(x)].max);
	tree[x].min = min(tree[ls(x)].min, tree[rs(x)].min);
}

void add(int x, int L, int R, int l, int r, int val) {
	if (l <= L && R <= r) {
		tree[x].max += val;
		tree[x].min += val;
		tree[x].lazy += val;
		return;
	}
	if (tree[x].lazy && L != R) {
		tree[ls(x)].max += tree[x].lazy; tree[rs(x)].max += tree[x].lazy;
		tree[ls(x)].lazy += tree[x].lazy; tree[rs(x)].lazy += tree[x].lazy;
		tree[ls(x)].min += tree[x].lazy; tree[rs(x)].min += tree[x].lazy;
		tree[x].lazy = 0;	
	}
	if (L <= mid) add(ls(x), L, mid, l, r, val);
	if (R > mid) add(rs(x), mid + 1, R, l, r, val);
	tree[x].max = max(tree[ls(x)].max, tree[rs(x)].max);
	tree[x].min = min(tree[ls(x)].min, tree[rs(x)].min);
}

bool cmp(node2 a, node2 b){
	return a.val < b.val;
}

int cnt = 0;

int read() {
	int w = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (!(ch ^ 0x2D)) f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		w = (w << 3) + (w << 1) + (ch ^ 48);
		ch = getchar();
	}
	return w * f;
}

void print(int x) {
	if (x < 0) putchar(45), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

signed main() {
	K = 3500;
	n = read(), q = read();
	rep (i, 1, n) {
		a[i].val = read();
		a[i].id = i;
	}
	Build(1, 1, n);
	rep (i, 1, q){
		if (++cnt >= K){
			UpdateArray(1, 1, n);
			sort(a + 1, a + 1 + n, cmp);
			Build(1, 1, n);
			cnt = 0;
		}
		int opt = read(), k = read();
		if (opt == 1) {
			add(1, 1, n, 1, n, k);
		}
		else Modify(1, 1, n, k);
	}
	UpdateArray(1, 1, n);
	sort(a + 1, a + 1 + n, [](node2 a, node2 b)->bool{return a.id < b.id;});
	rep (i, 1, n) print(a[i].val), putchar(32);
	return 0;
}
/*
  3 2
  3 2 1
  1 3
  2 2
 */
