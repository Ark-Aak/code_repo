#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define F(i,a,b) for(int i=a;i<=b;i++) 
const int N=2e5+5,Mod=998244353;

int n,m,k;

inline int read();

void Subtask1(){
	F(i,1,m){
		int u,v,x;
		u=read(),v=read(),x=read();
		if(x==0) continue;
		else {
		cout<<0;
		return;
		}
	}
	cout<<1;
	return;
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read(),k=read();
	if(k==0){
		Subtask1();
		return 0;
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
