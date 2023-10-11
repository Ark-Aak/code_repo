#include<bits/stdc++.h>
using namespace std;
int P;
int s[40000005],tot;
int vis[40000005];
void Init(int x){
	for(int i=2;i<=x;i++){
		if(vis[i]==0){s[++tot]=i;vis[i]=i;}
		for(int j=1;j<=tot;j++){
			if(s[j]>vis[i])break;
			if(i*s[j]>x)break;
			vis[i*s[j]]=s[j];
		}
	}
}
int zs[40000005],t;
signed main(){
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	Init(4e7);
	int T;
	scanf("%d %d",&T,&P);
	for(int i=2;i<=4e7;i++)if(vis[i]==i||vis[i]>P)zs[++t]=i;
	while(T--){
		int x;
		scanf("%d",&x);
		printf("%d\n",zs[lower_bound(zs+1,zs+t+1,x)-zs]);
	}
}
