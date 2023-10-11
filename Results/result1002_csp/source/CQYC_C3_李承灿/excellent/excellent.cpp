#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n;
string s;
signed main(){
	freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		cin>>s;
		n=s.size();
		s=' '+s;
		int sum=0,ans=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='?') sum++;
		}
		if(n<=50||sum!=n){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n/2;j++){
					int z=0;
					for(int l=i;l<i+j;l++){
						if(s[l]!=s[l+j]&&s[l]!='?'&&s[l+j]!='?'){
							z=1;
							break;
						}
					}
					if(z==1) continue;
					for(int k=1;k<=n/2;k++){
						if(i+j*2+k*2-1>n) break;
						int z=0;
						for(int l=i+2*j;l<i+2*j+k;l++){
							if(s[l]!=s[l+k]&&s[l]!='?'&&s[l+k]!='?'){
								z=1;
								break;
							}
						}
						if(z==1) continue;
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		else if(sum==n){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i*2+j*2>n) continue;
					ans+=n-(i*2+j*2)+1;
				}
			}
			printf("%lld\n",ans);
			continue;
		}
	}
	return 0;
}


