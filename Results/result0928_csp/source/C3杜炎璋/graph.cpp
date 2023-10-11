#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node {
	int x,y,id;
} a[100005];
int vis[100005],f[100005];
vector<int> q[100005];
void dfs(int x) {
	vis[x]=1;
	for(int i=0; i<q[x].size(); i++) {
		if(!vis[q[x][i]]) {
			dfs(q[x][i]);
		}
	}
}
int find(int x) {
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
bool cmp(node x,node y) {
	return x.x<y.x;
} 
bool cmp2(node u,node v) {
	return u.y<v.y;
}
int n;
void solve(int l,int r) {
	int mid=(l+r)/2;
	if(l==r) return ; 
	sort(a+l,a+mid+1,cmp2);
	sort(a+mid+1,a+r+1,cmp2);
	int	rx=mid+1,k=mid+1,c=mid+1;
	for(int i=l;i<=mid;i++) {
		while(rx<=r && a[i].y>a[rx].y) rx++;
		if(rx==r+1) k=min(k,i);
		if(i==l) c=rx;
	}
	int fath=find(a[l].id);
	for(int i=l;i<k;i++) f[find(a[i].id)]=fath;
	for(int i=c;i<=r;i++) f[find(a[i].id)]=fath;
	sort(a+l,a+mid+1,cmp);
	sort(a+mid+1,a+r+1,cmp);
	solve(l,mid);
	solve(mid+1,r);	
}
int cnt;
signed main() {
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) scanf("%lld %lld",&a[i].x,&a[i].y),f[i]=i,a[i].id=i;
	if(n<=1000) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i==j) continue;
				if(a[i].x<=a[j].x && a[i].y<=a[j].y) {
					q[i].push_back(j);
					q[j].push_back(i);
				}
			}
		}
		for(int i=1; i<=n; i++) {
			if(!vis[i]) {
				cnt++;
				dfs(i);
			}
		}
	} else {
		sort(a+1,a+n+1,cmp);
		solve(1,n);
		for(int i=1;i<=n;i++) {
			if(!vis[find(i)]) cnt++,vis[find(i)]=1;
		}
	}
	printf("%lld\n",cnt);
	return 0;
}

