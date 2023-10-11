#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=2005;
int n;
char s[Maxn];
ll f[Maxn][Maxn];
ll ans=0;
int main(){
	freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		ans=0;
		for(int i=1;i<=n;i++)
			for(int k1=i+1;k1<=n;k1+=2){
				f[i][k1]=1;
				int k=(i+k1)/2;
				for(int z=i;z<=k;z++)
					if(s[z]!=s[z-i+k+1]&&s[z]!='?'&&s[z-i+k+1]!='?'){f[i][k1]=0;break;}
			}
		for(int i=1;i<=n;i++)
			for(int j=i+3;j<=n;j+=2){
				for(int k=i;k<=(i+j-3)/2;k++){
					ans+=f[i][2*k-i+1]*f[2*k-i+2][j];
				}
			}
		printf("%lld\n",ans);
	}
	return 0;
}
//					int cnt=1;
//					for(int z=i;z<=k;z++)
//						if(s[z]!=s[z-i+k+1]&&s[z]!='?'&&s[z-i+k+1]!='?'){cnt=0;break;}
//					if(!cnt)continue;
//					for(int z=2*k-i+2;z<=(2*k-i+2+j)/2;z++){
//						int nxt=z-(2*k-i+2)+(2*k-i+2+j)/2+1;
//						if(s[z]!=s[nxt]&&s[z]!='?'&&s[nxt]!='?'){cnt=0;break;}
//					}
