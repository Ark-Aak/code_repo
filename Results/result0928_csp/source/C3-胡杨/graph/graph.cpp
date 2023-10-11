#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	char ch = getchar();
	int f = 1;
	while (!isdigit(ch) && ch ^ '-') ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
	x *= f;
}
const int maxn = 1e5 + 10;
int n;
struct node {
	int x,y,id;
} a[maxn];
bool cmp(node q, node p) {
	if(q.x == p.x) return q.y < p.y;
	return q.x < p.x;
}
bool cmp1(node q, node p) {
    if(q.x == p.x) return q.y > p.y;
    return q.x > p.x;
}
int b[2 * maxn],tot;
struct Tree {
	int s[4 * maxn];
	int lowbit(int x) {
		return x & (-x);
	}
	void add(int x,int y,int t) {
		if(t == 1) while(x <= tot) s[x] += y, x += lowbit(x);
		else while(x) s[x] += y, x -= lowbit(x);
	}
	int query(int x,int t) {
		int sum = 0;
		if(t == 1) while(x) sum += s[x], x -= lowbit(x); 
		else while(x <= tot) sum += s[x], x += lowbit(x);
		return sum;
	}
} T,T1;
int ans;
int vis[maxn],vis1[maxn];
signed main() {
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	read(n);
	for(int i = 1 ; i <= n ; i++) {
		read(a[i].x);
		read(a[i].y);
		b[++tot] = a[i].x;
		b[++tot] = a[i].y;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	sort(b + 1, b + tot + 1);
	tot = unique(b + 1, b + tot + 1) - b - 1;
	for(int i = 1 ; i <= n ; i++) {
		a[i].x = lower_bound(b + 1, b + tot + 1, a[i].x) - b;
		a[i].y = lower_bound(b + 1, b + tot + 1, a[i].y) - b;
		if(!T.query(a[i].y,1))
			ans++;
		else{
			vis[a[i].id] = 1;
			vis1[a[i].id] = 1;
		} 
		T.add(a[i].y,1,1);
	}
	sort(a + 1, a + n + 1, cmp1);
	for(int i = 1 ; i <= n ; i++){
		if(vis[a[i].id]) {
			T1.add(a[i].y, 1, 2);
			continue;
	    }
		if(T1.query(a[i].y, 2)) {
			ans--;
			vis1[a[i].id] = 1;
		}
		T1.add(a[i].y, 1, 2);
//		for(int j = 1 ; j <= tot ; j++) cout << T1.s[j] <<" ";
//		cout << endl;
	}
	int tt = 0;
	for(int i = 1 ; i <= n ; i++) if(vis1[a[i].id]) tt = 1, i = n + 1;
	printf("%lld\n",ans + tt);
	return 0;
}
