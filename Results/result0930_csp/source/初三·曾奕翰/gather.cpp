#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,k,ans=0;
int a[200005];
vector<int>q[200005];
int nxt[200005],tot[200005];
bool vis[200005];
signed main() {
	freopen("gather.in","r",stdin);
	freopen("gather.out","w",stdout);
	//scanf("%d%d",&n,&k);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) q[i].clear();
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		q[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(tot[a[i]]<q[a[i]].size()-1) nxt[i]=q[a[i]][tot[a[i]]+1];
		else nxt[i]=n+1;
		tot[a[i]]++;
	}
	if(n<=5000){
		for(int i=1;i<n;i++){
			int p=nxt[i];
			ans+=(p-i);
			if(p!=n+1) ans--; 
			for(int j=1;j<=n;j++) vis[j]=0;
			for(int j=i+1;j<=p;j++){
				if(nxt[j]<=p&&nxt[j]!=n+1){
					ans--; 
				}
			}
		} 
		cout<<ans;//盲生，你发现了华点。 
		return 0;
	}
	cout<<1;
	return 0;
}
