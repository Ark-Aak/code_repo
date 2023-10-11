#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
int a[200005];
int zaa[200005];
bool vis[200005];
//char s[1000005];
//int l0,r0,l1,r1;
struct XXX{
	int a,id;
}z[200005];
bool cmp(XXX x,XXX y){
	return x.a<y.a;
}
signed main(){
	freopen("gaze.in","r",stdin);
	freopen("gaze.out","w",stdout);
	int T=1;
	//scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			z[i].a=a[i],z[i].id=i;
		}
		a[0]=0;
		if(n<=2000&&k<=2000){
			int x=0;
			for(int asfasf=1;asfasf<=k;asfasf++){
				int opt;
				scanf("%lld",&opt);
				if(opt==1){
					scanf("%lld",&x);
					ans=0;
					for(int i=1;i<=n;i++){
						if(a[i]>=x&&a[i-1]<x) ans++;
					}
					printf("%lld\n",ans);
				}
				else{
					int gg,toa;
					scanf("%lld%lld",&gg,&toa);
					a[gg]=toa;
				}
			}
			return 0;
		}
		sort(z+1,z+n+1,cmp);
		zaa[0]=1;
		for(int i=1;i<=n;i++){
			vis[z[i].id]=1;
			zaa[i]=zaa[i-1];
			if(vis[z[i].id-1]==0&&vis[z[i].id+1]==0&&z[i].id!=n&&z[i].id!=1)
				zaa[i]++;
			if(vis[z[i].id-1]==1&&vis[z[i].id+1]==1)
				zaa[i]--;
			a[i]=z[i].a;
		}
		int x;
		while(k--){
			int opt;
			scanf("%lld",&opt);
			if(opt==1){
				scanf("%lld",&x);
				ans=0;
				int pp=upper_bound(a+1,a+n+1,x-1)-a-1;
				printf("%lld\n",zaa[pp]);
			}
			else{
				int gg,toa;
				scanf("%lld%lld",&gg,&toa);
				a[gg]=toa;
			}
		}
	}
	return 0;
}
