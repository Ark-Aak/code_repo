#include<bits/stdc++.h>
using namespace std;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0'&& ch <= '9') {
		x = (x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, m, q, head[1005], tail[500005], nxt[500005], val[500005], cnt, tot, l, r, s, t;
bool flag;
void add(int u, int v) {
	tail[++tot] = v;
	val[tot] = ++cnt;
	nxt[tot] = head[u];
	head[u] = tot;
	tail[++tot] = u;
	val[tot] = cnt;
	nxt[tot] = head[v];
	head[v] = tot;
	return;
}
void dfs(int x, int va) {
	if(va > r)	return;
	if(x == t) {
		flag = true;
		return;
	}
	for(int i = head[x]; i; i = nxt[i]) {
		int ed = tail[i];
		if(val[i] > va) {
			dfs(ed, val[i]);
		}
	}
	return;
}
int main() {
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	n = read(); m = read(); q = read();
	for(int i = 1; i <= m; ++i) {
		int u, v;
		u = read(); v = read();
		add(u, v);
	}
	while(q--) {
		l = read(); r = read(); s = read(); t = read();
		flag = false;
		dfs(s, l - 1);
		if(flag)	printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}
