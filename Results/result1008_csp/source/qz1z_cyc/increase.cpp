#include<bits/stdc++.h>
using namespace std;
int n,m,ali[100005],bob[100005],t1,t2;
struct sb {
	int u,v,w;
} kk[100005];
bool cmp(sb x,sb y) {
	return x.w<y.w;
}
int main() {
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		ali[i]=1;
		bob[i]=998244353;
	}
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&kk[i].u,&kk[i].v,&kk[i].w);
	}
	sort(kk+1,kk+1+m,cmp);
	for(int i=m; i>=1; i--) {
		t1=ali[kk[i].v];
		t2=ali[kk[i].u];
		if(bob[kk[i].u]!=998244353) {
			ali[kk[i].v]=max(ali[kk[i].v],bob[kk[i].u]+1);
		} else ali[kk[i].v]=max(ali[kk[i].v],2);
		if(bob[kk[i].v]!=998244353) {
			ali[kk[i].u]=max(ali[kk[i].u],bob[kk[i].v]+1);
		} else ali[kk[i].u]=max(ali[kk[i].u],2);
		bob[kk[i].u]=min(bob[kk[i].u],t1+1);
		bob[kk[i].v]=min(bob[kk[i].v],t2+1);
	}
	for(int i=1; i<=n; i++) printf("%d ",ali[i]-1);
	return 0;
}
