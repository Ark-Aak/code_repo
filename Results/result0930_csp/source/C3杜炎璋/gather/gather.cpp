#include<bits/stdc++.h>
#define int long long
using namespace std;
int cnt[200005],n,bowl[200005],a[200005];
int lowbit(int x) {
	return x&(-x);
}
void add(int x,int y) {
	for(int i=x;i>=1;i-=lowbit(i)) cnt[i]+=y;
}
int find(int x) {
	int ans=0;
	for(int i=x;i<=n;i+=lowbit(i)) ans+=cnt[i];
	return ans;
}
struct node {
	int x,y;
}f[200005],q[200005];
bool cmp(node u,node v) {
	if(u.x==v.x) u.y<v.y;
	return u.x<v.x;
}
int head=1,tail=0,stk[200005];
signed main(){
	freopen("gather.in","r",stdin);
	freopen("gather.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<=n;i++) bowl[i]=0;
	for(int i=1;i<=n;i++) {
		f[i].x=bowl[a[i]]+1,f[i].y=i,bowl[a[i]]=i;		
	}
	for(int i=0;i<=n;i++) bowl[i]=n+1;
	for(int i=n;i>=1;i--) {
		q[i].x=i,q[i].y=bowl[a[i]]-1;
		bowl[a[i]]=i;
	}
	sort(f+1,f+n+1,cmp);
	sort(q+1,q+n+1,cmp);
	int k=1,ans=0;
	for(int i=1;i<=n;i++) {
		while(f[k].x<=q[i].x && k<=n) add(f[k].y,1),stk[++tail]=k,k++;
		while(f[stk[head]].y<q[i].x && head<=tail) add(f[stk[head]].y,-1),head++;
		ans+=find(q[i].x+1)-find(q[i].y+1);
	}
	printf("%lld",ans);
	return 0;
}

