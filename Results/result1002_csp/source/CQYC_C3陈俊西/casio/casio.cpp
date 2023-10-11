#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e7+10,C=3e7+1;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int t,p,s[1857865],tp;
bitset<N> vis,px,minp;
bool check(int x){
	if(px[x]) return 1;
	if(minp[x]) return 1;
	return 0;
}
signed main(){
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	t=read(),p=read();
	for(int i=2;i<=min(C,p);i++){
		if(!vis[i]){
			px[i]=1;
			s[++tp]=i;	
		}
		for(int j=1;j<=tp;j++){
			int x=s[j]*i;
			if(x<=C) vis[x]=1;
			else break;
		}
	}	
	for(int i=min(C,p)+1;i<=C;i++){
		if(!vis[i]){
			px[i]=1;
			s[++tp]=i;	
			minp[i]=1;
		}
		for(int j=1;j<=tp;j++){
			int x=s[j]*i;
			if(x<=C){
				vis[x]=1;
				minp[x]=((minp[s[j]])&(minp[i]));
			}
			else break;
		}
	}
	while(t--){
		int n=read();
		while(!check(n)) n++;
		printf("%lld\n",n);
	}
	return 0;
}
