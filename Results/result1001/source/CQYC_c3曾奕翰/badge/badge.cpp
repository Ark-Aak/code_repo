#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int Mod=1e9+7;
int n,m;
int ans;
int l[500005],r[500005]; 
int a[500005]; 
int qzh[500005]; 
int gg[500005];
bool vis[500005]; 
vector<int>bkl[500005];
bool bk[500005];
signed main() {
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	bool flag=1;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		
		scanf("%lld%lld",&l[i],&r[i]);
		bkl[l[i]].push_back(i);
		if(r[i]-l[i]>5) flag=0;
	}
	while(m--){
		int x;
		int ans=0;
		scanf("%lld",&x);
		for(int i=1;i<=x;i++){
			scanf("%lld",&a[i]);
			vis[a[i]]=1;
			if(flag==1){
				for(int j=a[i]-6;j<=a[i];j++){
					if(j<0) continue;
					if(bkl[j].size()){
						for(auto v:bkl[j]){
							if(r[v]>=a[i]){
								bk[v]=1-bk[v];
								if(bk[v]==1){
									ans++;
								}
								else ans--;
							}
						}
						
					}
				}
			}
		}
		if(flag){
			cout<<ans<<endl;
			for(int i=1;i<=x;i++){
				for(int j=a[i]-6;j<=a[i];j++){
					if(bkl[j].size()){
						for(auto v:bkl[j]){
							bk[v]=0;
						}
					}
				}
			}
			continue;
		}
		if(n<=3000){
			qzh[0]=0;
			for(int i=1;i<=n;i++){
				qzh[i]=qzh[i-1];
				if(vis[i]) qzh[i]++;
				vis[i]=0;
			}
			for(int i=1;i<=n;i++){
				if((qzh[r[i]]-qzh[l[i]-1])&1==1){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
