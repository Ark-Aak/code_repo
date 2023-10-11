#include<bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
int n;
int fa[N], x[N], y[N], b[N], ans;
int find(int x) {
	if(x == fa[x]) return fa[x];
	return fa[x] = find(fa[x]);
}
void join(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx != fy) fa[fx] = fy;
}
signed main() {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld %lld", &x[i], &y[i]);
		fa[i] = i;
	}
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++) {
		if(i == j) continue;
		if(x[i] <= x[j] && y[i] <= y[j] || x[j] <= x[i] && y[j] <= y[i])
		    join(i, j);
    }
    for(int i = 1; i <= n; i++) {
    	int x = find(i);
    	if(b[x] == 0) {
    		ans++;
    		b[x] = 1;
		}
	}
	printf("%lld", ans); 
	return 0;
}
