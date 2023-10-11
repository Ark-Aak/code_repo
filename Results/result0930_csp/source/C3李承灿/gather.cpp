#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005]; 
int l[200005];
int vis[200005];
int o[200005];
int ans;
signed main(){
	freopen("gather.in","r",stdin);
	freopen("gather.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		l[i]=vis[a[i]];
		vis[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		ans+=i-l[i]-1;
		for(int j=i-1;j>l[i];j--){
			if(o[a[j]]!=i) o[a[j]]=i;
			else ans--;
		}
	}
	printf("%lld",ans);
	return 0;
}


