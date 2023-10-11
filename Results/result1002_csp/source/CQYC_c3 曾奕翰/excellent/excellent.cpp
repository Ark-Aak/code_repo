#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch-'0');ch=getchar();}
	return x*f;
}
int n;
char s[3005]; 
bool vis[3005][3005];
int l[3005],r[3005];
signed main() {
	freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout);
	int T=read();
	while(T--){
		 scanf("%s",s+1);
		n=strlen(s+1);
		bool bk=0;
		for(int i=1;i<=n;i++){
			if(s[i]!='?'){
				bk=1;
				break;
			}
		}
		if(bk==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(n-i-3>=0)ans+=(n-i-3)/2+1;
			}
			cout<<ans<<endl;
			continue;
		}
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				bool flag=1;
				if(j+j-i-1>n) continue;
				for(int t=i;t<j;t++){
					if(s[t]=='?'||s[j+i-t]=='?') continue;
					else if(s[t]!=s[j+t-i]){
						flag=0;
						break;
					}
				} 
				if(flag){
					if(j+j-i-1>n||i<1) continue;
					l[i]++;
					r[j+j-i-1]++;
					vis[i][j+j-i-1]=1;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=l[i]*r[i-1];
		}
		cout<<ans<<endl;
	} 
	return 0;
}

