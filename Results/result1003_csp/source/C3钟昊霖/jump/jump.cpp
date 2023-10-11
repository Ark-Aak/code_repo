#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define F(i,a,b) for(int i=a;i<=b;i++)

const int N=5e5+5;

int l[N],stk[N],tot;

int f[N],n,a[N];

inline int read();

signed main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	n=read();
	F(i,1,n) a[i]=read();
	for(int i=n;i>=1;i--){
		while(tot&&a[i]>a[stk[tot]]){
			l[stk[tot]]=i;
			tot--;
		}
		stk[++tot]=i;
	}
	while(tot)
		l[stk[tot--]]=0;
	F(i,1,n){
		f[i]=1;
		int g=i;
		while(l[g]!=0){
			g=l[g];
			if(f[g]){
				f[i]+=f[g];
				break;
			}
			else {f[i]++;}
		}
		//printf("%lld ",f[i]);
		cout<<f[i]<<" ";
	}
	return 0;
}

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
