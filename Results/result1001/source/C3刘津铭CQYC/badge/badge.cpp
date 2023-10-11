#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n, Q, m, x[N];
struct node{
	int l, r;
}a[N];
struct o{
	int Get, X;
}p[N];
int tot = 0;
int c[N];
int lowbit(int x) {
	return x & (-x);
}
void add(int x, int y) {
	for(int i = x; i <= n; i += lowbit(i)) c[i] += y;
}
int query(int x) {
	int res = 0;
	for(int i = x; i; i -= lowbit(i)) res += c[i];
	return res;
}
bool cmp(node x, node y) {
	if(x.l == y.l) return x.r < y.r;
	return x.l < y.l;
}
bool cmp2(o x, o y) {
	return x.Get < y.Get;
}
signed main() {
	freopen("badge.in", "r", stdin);
	freopen("badge.out", "w", stdout);
	scanf("%lld %lld", &n, &Q);
	for(int i = 1; i <= n; i++) scanf("%lld %lld", &a[i].l, &a[i].r);
	if(n <= 3000) {
		while(Q--) {
			scanf("%lld", &m);
			for(int i = 1; i <= m; i++) {
				scanf("%lld", &x[i]);
				add(x[i], 1);
			} 
			int ans = 0;
			for(int i = 1; i <= n; i++) {
				if((query(a[i].r) - query(a[i].l - 1)) % 2 == 1) ans++;
			}
			printf("%lld\n", ans);
			for(int i = 1; i <= m; i++) {
				add(x[i], -1);
			}
		}
		return 0;
	}
	/*sort(a + 1, a + n + 1, cmp);
	while(Q--) {
		scanf("%lld", &m);
		tot = 0;
		for(int i = 1; i <= m; i++) {
			scanf("%lld", &x[i]);
			int get = -1, L = 1, R = n;
			while(L <= R) {
				mid = (L + R) / 2;
				if(a[mid].l <= x[i]) {
					L = mid + 1;
					get = mid;
				} 
				else R = mid - 1;
			}
			if(get == -1) continue;
			//[1,get]
			tot++;
			p[tot].Get = get;
			p[tot].X = x[i];
		} 
		sort(p + 1, p + tot + 1, cmp2);
		int j = 1;
		for(int i = 1; i <= n; i++) {
			while(p[j].Get <= i && j <= tot) {
				//保证 [1,i]的左端点均小于等于x
				//右端点在[x,n]均满足
				add(n, 1);
				add(x - 1, -1); 
			}
		}
	}*/
	return 0;
}
