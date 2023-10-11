#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int fa[200005];
int ans;
struct node{
	int c,a[5];
}t[100005];
bool cmp(node x,node y){
	return x.c<y.c;
}
int Find(int x){
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
signed main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&t[i].c);
		for(int j=1;j<=4;j++) scanf("%lld",&t[i].a[j]);
	}
	sort(t+1,t+n+1,cmp);
	for(int i=1;i<=2*n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		fa[Find(t[i].a[1])]=fa[Find(t[i].a[2])];
		fa[Find(t[i].a[3])]=fa[Find(t[i].a[4])];
	}
	for(int i=1;i<=n;i++){
		if(fa[Find(t[i].a[1])]!=fa[Find(t[i].a[3])]){
			ans+=t[i].c;
			fa[Find(t[i].a[1])]=fa[Find(t[i].a[3])];
		}
	}
	printf("%lld",ans);
	return 0;
}


