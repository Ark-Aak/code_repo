#include<bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize(1,2,3,"Ofast","inline","-ffast-math")
#define N 2000005
char buf[1 << 20], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)
using namespace std;
int n;
struct edge{
	int to;
	char w;
};
vector<edge>p[N];
int ans[N], siz[N], dfn[N], son[N], dep[N], sum[N], cnt, h[30], tot, f[9000006], b[N];
void dfs1(int x, int fa) {
	dep[x] = dep[fa] + 1;
	dfn[x] = ++cnt;
	b[cnt] = x;
	siz[x] = 1;
	int Maxson = 0;
	for(int i = 0; i < p[x].size(); i++) {
		int y = p[x][i].to;
		if(y == fa) continue;
		sum[y] = sum[x] ^ (1 << (p[x][i].w - 'a'));
		dfs1(y, x);
		siz[x] += siz[y];
		if(siz[y] > Maxson) {
			Maxson = y;
			son[x] = y;
		}
	}
}
void dfs2(int x, int fa, bool opt) {
	for(int i = 0; i < p[x].size(); i++) {
		int y = p[x][i].to;
		if(y == fa || y == son[x]) continue;
		dfs2(y, x, 1);
		ans[x] = max(ans[x], ans[y]);
	}
	if(son[x]) dfs2(son[x], x, 0), ans[x] = max(ans[x], ans[son[x]]);

	for(int i = 0; i < p[x].size(); i++) {
		int y = p[x][i].to;
		if(y == fa || y == son[x]) continue;
		for(int l = dfn[y]; l <= dfn[y] + siz[y] - 1; l++) {
			for(int u = 1; u <= 23; u++) if(f[sum[b[l]] ^ h[u]] > 0) ans[x] = max(ans[x], f[sum[b[l]] ^ h[u]] + dep[b[l]] - 2 * dep[x]);
		}
		for(int l = dfn[y]; l <= dfn[y] + siz[y] - 1; l++) f[sum[b[l]]] = max(f[sum[b[l]]], dep[b[l]]);
	}
	f[sum[x]] = max(f[sum[x]], dep[x]);
	for(int i = 1; i <= 23;  i++) { //处理一条链下来的情况
		if(f[sum[x] ^ h[i]] > 0) ans[x] = max(ans[x], f[sum[x] ^ h[i]] - dep[x]);
	}
	if(opt) for(int l = dfn[x]; l <= dfn[x] + siz[x] - 1; l++) f[sum[b[l]]] = 0;
}

inline int read() {
	int w = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (!(ch ^ 45)) f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		w = (w << 3) + (w << 1) + (ch ^ 48);
		ch = getchar();
	}
	return w * f;
}

void print(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

signed main() {
	n = read();
    for(int i = 2, fa; i <= n; i++) {
		fa = read();
    	char c = getchar();
		while (!isalpha(c)) c = getchar();
    	p[i].push_back((edge){fa, c});
    	p[fa].push_back((edge){i, c});
	}
	h[++tot] = 0; for(int i = 0; i < 22; i++) h[++tot] = (1 << i);
	dfs1(1, 0);
	dfs2(1, 0, 1);
	for(int i = 1; i <= n; i++) print(ans[i]), putchar(32);
	return 0;
}
