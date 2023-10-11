#include<bits/stdc++.h>
using namespace std;

const int N=3e7+5,M=1e6+5;

int vis1[N],vis[N],Prime[M],ans[M],tot,cnt,u;
long long T,P,x;
inline void init(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			Prime[++cnt]=i;
			vis1[i]=1;
		}
		for(int j=1;j<=cnt;j++){
			if(i*Prime[j]>n) break;
			vis[i*Prime[j]]=1;
			if(Prime[j]>P) vis1[i*Prime[j]]=1;
			if(i%Prime[j]==0) break;
		}
	}
	return;
}

signed main(){
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	scanf("%lld%lld",&T,&P);
	init(3e7);
//	sort(ans+1,ans+tot+1);
	for(int i=0;i<=3e7;i+=4){
		if(vis1[i+1]) ans[++tot]=i+1;
		if(vis1[i+2]) ans[++tot]=i+2;
		if(vis1[i+3]) ans[++tot]=i+3;
		if(vis1[i+4]) ans[++tot]=i+4;
	}
	while(T--){
		scanf("%lld",&x);
		int p=lower_bound(ans,ans+tot+1,x)-ans;
		printf("%d\n",ans[p]);
	}
	return 0;
} 
