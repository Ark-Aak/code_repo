#include<bits/stdc++.h>
using namespace std;

#define int long long 

#define F(i,a,b) for(int i=a;i<=b;i++)

const int N=1e6+5;

inline int read();

int n,m,a[N],l[N],r[N],tot,stk[N];
signed main(){
	freopen("mountain.in","r",stdin);
	freopen("mountain.out","w",stdout);
	n=read();
	F(i,1,n) a[i]=read();
	for(int i=1;i<=n;i++){
		while(tot&&a[stk[tot]]<a[i]){
			r[stk[tot]]=i-1;
			tot--;
		}
		stk[++tot]=i;
	}
	while(tot){
		r[stk[tot--]]=n;
	}
	for(int i=n;i>=1;i--){
		while(tot&&a[i]>a[stk[tot]]){
			l[stk[tot]]=i+1;
			tot--;
		}
		stk[++tot]=i;
	}
	while(tot){
		l[stk[tot--]]=1;
	}
	for(int i=1;i<=n;i++) cout<<r[i]-l[i]<<endl;
	return 0;
}


inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f*=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
