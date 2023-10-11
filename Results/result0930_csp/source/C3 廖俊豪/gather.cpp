#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,ans;
int a[200005];
int last[200005];
int tree[200005];
inline int lowbit(int x){return x&(-x);}
inline void modify(int x,int y){
	if(!x)return;
	while(x<=n){
		tree[x]+=y;
		x+=lowbit(x);
	}
	return;
}
inline int query(int x){
	int sum=0;
	while(x){
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}
signed main(){
	freopen("gather.in","r",stdin);
	freopen("gather.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		modify(last[a[i]],-1);
		ans+=query(i-1)-query(last[a[i]]);
		last[a[i]]=i;
//		printf("%lld:\n",i);
//		for(int j=1;j<=n;j++)printf("%lld ",j);printf("\n");
//		for(int j=1;j<=n;j++)printf("%lld ",query(j)-query(j-1));printf("\n");
		modify(i,1);
	}
	printf("%lld",ans);
	return 0;
}/*
7
1 2 3 4 3 2 5
*/
