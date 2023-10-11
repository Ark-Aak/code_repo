#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int t;
string s;
signed main(){
	freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout);
	t=read();
	while(t--){
		cin>>s;
		int n=s.size();
		s=' '+s;
		int sss=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='?') sss++;
		if(sss==n){
			int ans=0;
			for(int l1=1;l1<=n/2;l1++){
				for(int l2=1;l2<=n/2;l2++){
					if(l1*2+l2*2>n) continue;
					ans=ans+(n-l1*2-l2*2+1);
				}			
			}
			printf("%lld\n",ans);			
		}
		else{
			int ans=0;
			for(int l1=1;l1<=(n-2)/2;l1++){
				for(int l2=1;l2<=(n-l1*2)/2;l2++){
					for(int ks=1;ks<=n-l1*2-l2*2+1;ks++){
						bool ov=0;
						for(int i=1;i<=l1;i++){
							int c1=ks+i-1,c2=ks+l1+i-1;
							if(s[c1]!=s[c2]&&s[c1]!='?'&&s[c2]!='?'){
								ov=1;
								break;
							} 
						}
						if(ov) continue;
						int ks2=ks+2*l1;
						for(int i=1;i<=l2;i++){
							int c1=ks2+i-1,c2=ks2+l2+i-1;
							if(s[c1]!=s[c2]&&s[c1]!='?'&&s[c2]!='?'){
								ov=1;
								break;
							} 
						}					
						if(ov) continue;
						ans++;
					}
				}			
			}
			printf("%lld\n",ans);			
		}
	}
	return 0;
}
