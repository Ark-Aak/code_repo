#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=2e6+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,k,maxa,p[M],s[N],tp,ans,pn;
signed main(){
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	n=pn=read(),k=read();
	for(int i=1;i<=n;i++){
		int x=read();
		p[x]++;
		maxa=max(maxa,x);
	}
	for(int i=2;i<=maxa;i++)
		if(p[i]) s[++tp]=i;
	int sp=0,now=1;
	for(int i=1;i<=tp;){
		int w=s[i];
		if(sp+p[s[i]]<=k){
			if(sp*(w-now)<=p[w]*(w-1)){
				sp+=p[w];
				now=w;
				i++;
			}
			else{
				ans=ans+pn*(now-1)*2;
				pn-=sp;
				sp=0;
				now=1;
			}
		}
		else{
			int w=s[i],can=k-sp;
			if(sp*(w-now)<=can*(w-1)){
				sp=k;
				now=w;
				p[w]-=can;
			}
			ans=ans+pn*(now-1)*2;
			pn-=sp;
			sp=0;
			now=1;
		}
	}	
	if(sp) 	ans=ans+pn*(now-1)*2;
	printf("%lld",ans);
	return 0; 
}
/*
6 6
2 2 5 6 2 5
*/
