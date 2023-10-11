#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,mod=11;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,a[N],pw10[N];
string s,t;
bool dpo[20],dpy[20],zy[20];
signed main(){
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	n=read();
	cin>>s>>t;
	s=' '+s;
	t=' '+t;
	pw10[1]=1;
	for(int i=2;i<=n;i++) pw10[i]=(pw10[i-1]*10)%mod;
	for(int i=1;i<=n;i++)
		a[i]=(s[i]-'0')*pw10[n-i+1]%mod;
	dpy[0]=dpo[0]=1;
	for(int i=1;i<=n;i++){
		if(t[i]=='y'){
			for(int j=0;j<11;j++) zy[j]=0;
			for(int j=0;j<11;j++)
				if(dpy[j]) zy[(j+a[i])%mod]=1;
			for(int j=0;j<11;j++) dpy[j]|=zy[j]; 
		}
		if(t[i]=='o'){
			for(int j=0;j<11;j++) zy[j]=0;
			for(int j=0;j<11;j++)
				if(dpo[j]) zy[(j+a[i])%mod]=1;
			for(int j=0;j<11;j++) dpo[j]|=zy[j];
		}
	}
	for(int i=1;i<11;i++){
		if(dpo[i]&&!dpy[11-i]){
			puts("oimiya");
			return 0;
		}	
	}
	puts("yoimiya");
	return 0;
}
/*
5
19755
yoyyy
*/
