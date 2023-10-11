#include<bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;
int n, cnt, ans;
int a[N], lst[N], nxt[N], rt[N];
int vis1[N], vis2[N];
struct node{
	int c, ls, rs;
}t[N * 30];
void build(int &o, int L, int R) {
	o = ++cnt;
	if(L == R) return;
	int mid = (L + R) / 2;
	build(t[o].ls, L, mid);
	build(t[o].rs, mid + 1, R);
}
void pushup(int u) {
    t[u].c = t[t[u].ls].c + t[t[u].rs].c;
}
void update(int lsto, int &o, int L, int R, int x, int y) { //a[x] += y;
    o = ++cnt; 
    t[o].c = t[lsto].c;
	if(L == R) {
		t[o].c += y;
		return;
	}
	int mid = (L + R) / 2;
	if(x <= mid) {
		t[o].rs = t[lsto].rs;
		update(t[lsto].ls, t[o].ls, L, mid, x, y);
	}
	else {
		t[o].ls = t[lsto].ls;
		update(t[lsto].rs, t[o].rs, mid + 1, R, x, y);
	}
	pushup(o);
}
int query(int lsto, int o, int L, int R, int l, int r) {
	if(l <= L && R <= r) return t[lsto].c - t[o].c;
	if(r < L || R < l) return 0;
	int mid = (L + R) / 2;
	return query(t[lsto].ls, t[o].ls, L, mid, l, r) + query(t[lsto].rs, t[o].rs, mid + 1, R, l, r);
}
signed main() {
	freopen("gather.in", "r", stdin);
	freopen("gather.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= n; i++) {
		if(vis1[a[i]] == 0) lst[i] = 0;
		else lst[i] = vis1[a[i]];
		vis1[a[i]] = i;
	}
	for(int i = n; i >= 1; i--) {
		if(vis2[a[i]] == 0) nxt[i] = n + 1;
		else nxt[i] = vis2[a[i]];
		vis2[a[i]] = i;
	}
	build(rt[0], 0, n + 1);
	for(int i = 1; i <= n; i++) {
		update(rt[i - 1], rt[i], 0, n + 1, lst[i], 1);
	}
	for(int i = 1; i <= n; i++) {
		ans += query(rt[nxt[i] - 1], rt[i + 1 - 1], 0, n + 1, 0, i - 1);
	}
	cout << ans;
	return 0;
} 
/*
7
1 2 3 4 3 2 5
*/
