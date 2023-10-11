#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,q,a[N],b[N];
map<pair<int,int>,int> m;
signed main(){
	freopen("act.in","r",stdin);
	freopen("act.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	if((!q)||(!n)){
		while(q--){
			int a=read(),b=read();
			if(a==b) printf("Bob\n");
			else printf("Alice\n");
		}	
	}
	else{
		for(int i=0;i<=n;i++){
			int x=a[i],y=b[i];
			m[{x,y}]=1;
		}
		while(q--){
			int a=read(),b=read();
			if(m[{a,b}]) printf("Bob\n");
			else printf("Alice\n");
		}
	}
	return 0;
}
