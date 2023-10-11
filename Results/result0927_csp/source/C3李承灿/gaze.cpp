#include<bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;
int n,m;
int h[N];
int k[N][3],s,sum[N],vis[N];
struct node{
	int q,id;
}u[N],c[N];
bool cmp(node w,node e){
	return w.q<e.q;
}
signed main(){
	freopen("gaze.in","r",stdin);
	freopen("gaze.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&h[i]);
	h[0]=-1;
	if(n<=2000){
		while(m--){
			int o,a,b;
			scanf("%lld %lld",&o,&a);
			if(o==1){
				int ans=0;
				for(int i=1;i<=n;i++){
					if(h[i]>=a&&h[i-1]<a) ans++;
				}
				printf("%lld\n",ans);
			}
			else{
				scanf("%lld",&b);
				h[a]=b;
			}
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld %lld",&k[i][0],&k[i][1]);
		if(k[i][0]==2) scanf("%lld",&k[i][2]),s++;
	}
	if(s==0){
		for(int i=1;i<=m;i++) u[i].q=k[i][1],u[i].id=i;
		for(int i=1;i<=n;i++) c[i].q=h[i],c[i].id=i;
		sort(u+1,u+m+1,cmp);
		sort(c+1,c+n+1,cmp);
		int cnt=1,ans=1;
		vis[0]=vis[n+1]=1;
		for(int i=1;i<=m;i++){
			while(c[cnt].q<u[i].q){
				if(vis[c[cnt].id-1]==0&&vis[c[cnt].id+1]==0) ans++;
				if(vis[c[cnt].id-1]==1&&vis[c[cnt].id+1]==1) ans--;
				vis[c[cnt].id]=1;
				cnt++;
			}
			sum[u[i].id]=ans;
		}
		for(int i=1;i<=m;i++) printf("%lld\n",sum[i]);
		return 0;
	}
	return 0;
}


