#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,Q;
int m,a[500002];
int o[500002];
int ans;
int z;
struct node{
	int l,r;
}q[500002];
bool cmp(node x,node y){
	if(x.r==y.r) return x.l<y.l;
	return x.r>y.r;
}
int lowbit(int x){
	return x&(-x);
}
void add(int x,int k){
	for(;x<=n;x+=lowbit(x)) o[x]+=k;
}
int sum(int x){
	int res=0;
	for(;x>0;x-=lowbit(x)) res+=o[x];
	return res;
}
signed main(){
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	scanf("%lld %lld",&n,&Q);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&q[i].l,&q[i].r);
		if(q[i].r-q[i].l>5) z=1;
	}
	while(Q--){
		scanf("%lld",&m);
		for(int i=1;i<=m;i++){
			scanf("%lld",&a[i]);
			add(a[i],1);
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(((sum(q[i].r)-sum(q[i].l-1))&1)==1) ans++;
		}
		for(int i=1;i<=m;i++) add(a[i],-1);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
5 2
4 5
3 5
2 4
1 3
5 5
4
1 2 3 4
1
4
*/


