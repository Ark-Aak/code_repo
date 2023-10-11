#include<bits/stdc++.h>
using namespace std;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, q, head[3000005], tail[4000005], nxt[4000005], tot, dis[2000005], siz[2000005], son[2000005], fa[2000005];
int top[2000005], id[2000005], cnt, minn[8000005], ww[8000005], Min, Jc;
bool JC[2000005];
void add_edge(int u, int v) {
	tail[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
	tail[++tot] = u;
	nxt[tot] = head[v];
	head[v] = tot;
	return;
}
void dfs1(int x, int f) {
	fa[x] = f;
	siz[x] = 1;
	dis[x] = dis[f] + 1;
	for(int i = head[x]; i; i = nxt[i]) {
		int ed = tail[i];
		if(ed == f)	continue;
		dfs1(ed, x);
		siz[x] += siz[ed];
		if(siz[ed] > siz[son[x]])	son[x] = ed;
	}
	return; 
}
void dfs2(int x, int topx) {
	top[x] = topx;
	id[x] = ++cnt;
	ww[cnt] = x;
	if(!son[x])	return;
	dfs2(son[x], topx);
	for(int i = head[x]; i; i = nxt[i]) {
		int ed = tail[i];
		if(ed == fa[x] || ed == son[x])	continue;
		dfs2(ed, ed);
	}
	return;
}
void build(int p, int l, int r) {
	if(l == r) {
		minn[p] = ww[l];
		return;
	}
	int mid = l + r >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	minn[p] = min(minn[p << 1], minn[p << 1 | 1]);
	return; 
}
int query(int p, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return minn[p];
	}
	int mid = l + r >> 1, res = 1e9;
	if(L <= mid)	res = min(res, query(p << 1, l, mid, L, R));
	if(R > mid)	res = min(res, query(p << 1 | 1, mid + 1, r, L, R));
	return res;
}
int get_min(int l, int r) {
	int ans = 1e9;
	while(top[l] != top[r]) {
		if(dis[top[l]] < dis[top[r]])	swap(l, r);
		ans = min(ans, query(1, 1, n, id[top[l]], id[l]));
		l = fa[top[l]];
	}
	if(dis[l] > dis[r])	swap(l, r);
	ans = min(ans, query(1, 1, n, id[l], id[r]));
	return ans; 
}
int main() {
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	n = read(); q = read();
	for(int i = 1; i < n; ++i) {
		int u, v;
		u = read(); v = read();
		add_edge(u, v);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, n);
	--q;
	string s;
	int x;
	cin>>s;
	x = read();
	JC[x] = true;
	Jc = x;
	Min = x;
	while(q--) {
		string s;
		int x;
		cin>>s;
		x = read();
		if(s == "JC") {
			if(JC[x] == false) {
				JC[x] = true;
				Min = min(Min, get_min(x, Jc));
				Jc = x;
			}
		}
		else {
			printf("%d\n", min(Min, get_min(x, Jc)));
		}
	}
	return 0;
}
