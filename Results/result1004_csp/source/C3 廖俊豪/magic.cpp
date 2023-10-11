#include<bits/stdc++.h>
using namespace std;
int n,ans;
struct node{
	int s;
	int p[5];
}a[100005];
inline bool cmp(node A,node B){
	return A.s<B.s;
}
int fa[200005];
inline int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
inline void meg(int x,int y){
	x=find(x);
	y=find(y);
	fa[x]=y;
}
signed main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		scanf("%d %d %d %d %d",&a[i].s,&a[i].p[1],&a[i].p[2],&a[i].p[3],&a[i].p[4]);
		meg(a[i].p[1],a[i].p[2]);
		meg(a[i].p[3],a[i].p[4]);
	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<":"<<find(i)<<endl;
//	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int ops=0;//是否需要改变
		int j_1,k_1;
		for(int j=1;j<=4;j++){
			for(int k=1;k<=4;k++){
				if(find(a[i].p[j])!=find(a[i].p[k])){
					j_1=j;
					k_1=k;
					ops=1;
				}
			}
		}
		ans+=ops*a[i].s;
		if(ops)fa[find(a[i].p[j_1])]=find(a[i].p[k_1]);
	}
	cout<<ans;
	return 0;
}
