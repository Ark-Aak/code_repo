#include<bits/stdc++.h>
#define int long long
#define N 2000002
#define ls (x<<1)
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
using namespace std;
int n,a[500005];
int ans[500005];
int mx[N],lazy[N];
void update(int x,int l,int r,int id,int k){
	if(l==r){
		mx[x]=k;
		return;
	}
	if(id<=mid) update(ls,l,mid,id,k);
	else update(rs,mid+1,r,id,k);
	mx[x]=max(mx[ls],mx[rs]);
}
int query(int x,int l,int r,int L,int R,int k){
	if(l==r) return l;
	if(R>mid&&mx[rs]>k) return query(rs,mid+1,r,L,R,k);
	else return query(ls,l,mid,L,R,k);
}
signed main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	a[0]=1e12;
	update(1,0,n,0,a[0]);
	for(int i=1;i<=n;i++){
		int u=query(1,0,n,0,i-1,a[i]);
		ans[i]=1+ans[u];
		update(1,0,n,i,a[i]);
	}
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}


