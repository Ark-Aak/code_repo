#include<bits/stdc++.h>
#define int long long
#define debug_h for(int i=1;i<=n;i++) cout << h[i] << " ";
#define debug_l for(int i=1;i<=m;i++) cout << l[i] << " ";
using namespace std;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=1e6+5,mod=1e9+7;
int n,m,k;
int h[N],l[N];
int ksm(int x,int p){
	int ans=1;
	for(;p;p>>=1){
		if(p&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
	}
	return ans%mod;
}
int res=0;
int vis[1005][1005];
signed main(){
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[i][j]=(i-1)*m+j;
		}
	}
	for(int i=1;i<=k;i++){
		char s;
		int x,y;
		cin >> s;
		x=read();y=read();
		if(s=='R'){
			for(int i=1;i<=m;i++){
				vis[x][i]=(vis[x][i]*y)%mod;
			}
		}else{
			for(int i=1;i<=n;i++){
				vis[i][x]=(vis[i][x]*y)%mod;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			res+=vis[i][j];
			res%=mod; 
		}
	}cout << res%mod << "\n";
	return 0;
}


