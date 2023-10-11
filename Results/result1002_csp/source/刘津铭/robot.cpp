//Ԥ�Ƶ÷֣�5 
#include<bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;
int T, n, m;
struct node{
    int L, R;
}a[N];
int c[N];
bool cmp(node x, node y) {
	if(x.L == y.L) return x.R > y.R;
	return x.L < y.L; 
}
int lowbit(int x) {
	return x & (-x);
}
void add(int x, int y) {
	for(int i = x; i <= n; i += lowbit(i))
	    c[i] += x;
}
int query(int x) {
	int res = 0;
	for(int i = x; i; i -= lowbit(i))
	    res += c[i];
	return res;
}
signed main() {
	freopen("robot.in", "r", stdin);
	freopen("robot.out", "w", stdout);
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld", &n);
		for(int i = 1; i <= n - 1; i++) {
			int g, h;
			scanf("%lld %lld", &g, &h);
		}
		scanf("%lld", &m);
		for(int i = 1; i <= m; i++) {
			scanf("%lld %lld", &a[i].L, &a[i].R);
			if(a[i].L > a[i].R) swap(a[i].L, a[i].R);
		}
		sort(a + 1, a + m + 1, cmp);
	    bool flag = 1;
		for(int i = m; i >= 1; i--) {
			if(query(a[i].R)) {
				flag = 0;
				printf("No\n");
				break;
			}
			add(a[i].R, 1);
		}
		if(flag) printf("Yes\n");
	}
	
	return 0;
}
/*
1
5
1 2
2 3
3 4
4 5
3
1 3
3 5
3 4

*/
