#include<bits/stdc++.h>

using namespace std;

struct node {
	int x, y, cnt, ans;
}p[100005], P[100005];
int n, maxx, lsh[200005], id, t[200005], P_id, fa[200005], ans;
vector<int> v[200005];
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9') {
		if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0'&&ch <='9') {
		x=(x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
bool cmp(node x, node y) {
	if(x.x == y.x)	return x.y < y.y;
	return x.x < y.x;
}
int get_root (int x) {
	if(fa[x] == x)	return x;
	return fa[x] = get_root(fa[x]);
}
int lowbit(int x) {
	return x&(-x);
}
void add(int ID, int x, int y) {
	for(int i = x; i <= id; i += lowbit(i)) {
		t[i] += y;
		v[i].push_back(ID);
	}
	return;
}
void merge(int x, int y) {
	int u = get_root(x), v = get_root(y);
	if(u != v)	fa[u] = v;
	return;
}
int ask(int ID, int x) {
	int ans = 0;
	for(int i = x; i; i -= lowbit(i)) {
		ans += t[i];
		for(int j = 0; j < v[i].size(); ++j) merge(ID, v[i][j]);
	}
	return ans;
}
int main() {
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n = read();
	for(int i = 1; i <= n; ++i) {
		fa[i] = i;
		p[i].x = read();
		p[i].y = read();
		lsh[i * 2 - 1] = p[i].x;
		lsh[i * 2] = p[i].y;
	}
	sort(lsh + 1, lsh + 2*n + 1);
	id = unique(lsh + 1, lsh + 2*n + 1) - lsh - 1;
	for(int i = 1; i <= n; ++i) {
		p[i].x = lower_bound(lsh + 1, lsh + id + 1, p[i].x) - lsh;
		p[i].y = lower_bound(lsh + 1, lsh + id + 1, p[i].y) - lsh;
	}
	sort(p + 1, p + n + 1, cmp);
	int cnt = 1;
	for(int i = 1; i < n; ++i) {
		if(p[i].x == p[i+1].x && p[i].y == p[i+1].y) {
			cnt++;
		}
		else {
			P[++P_id] = p[i];
			P[P_id].cnt = cnt;
			cnt = 1;
		}
	}
	P[++P_id] = p[n];
	P[P_id].cnt = cnt;
	for(int i = 1; i <= P_id; ++i) {
		add(i, P[i].y, P[i].cnt);
		P[i].ans = ask(i, P[i].y) - P[i].cnt;
	}
	for(int i = 1; i <= n; ++i) {
		if(fa[i] == i)	ans++;
	}
	printf("%d",ans);
	return 0;
}
