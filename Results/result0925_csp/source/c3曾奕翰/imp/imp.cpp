#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
ll ans=0;
struct XXX{
	int a,b,c;
}z[250005];
bool cmp(XXX x,XXX y ){
	return x.c>y.c;
}
signed main(){
	freopen("imp.in","r",stdin);
	freopen("imp.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&z[i].a,&z[i].b,&z[i].c);
	}
	sort(z+1,z+n+1,cmp);
	
	for(int i=1;i<=n;++i){
		if(z[i].c<=0) break;
		for(int j=i+1;j<=n;++j){
			if(z[j].c<=0) break;
			int luy,lux=min(z[i].a,min(z[j].a,min(z[i].b,z[j].b)));
			int roy,rox=max(z[i].a,max(z[j].a,max(z[i].b,z[j].b)));
			luy=lux;
			roy=rox;
			ll bian=roy-luy;
			ll jz=0;
			for(int t=1;t<=n;++t){
				if(z[t].a>=lux&&z[t].a<=rox&&z[t].b>=luy&&z[t].b<=roy){
					jz+=z[t].c;
				}
				if(z[t].c<=0&&jz-bian<=ans) break;
			}
			//cout<<lux<<" "<<roy<<" "<<bian<<" "<<jz-bian<<endl;
			ans=max(ans,jz-bian);
		}
	}
	printf("%d",ans);
	return 0;
}
/*
6
2 3 4
1 4 -4
0 0 2
1 0 -5
3 1 -1
1 1 3
 
 */
