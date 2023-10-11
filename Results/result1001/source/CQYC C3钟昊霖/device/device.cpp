#include<bits/stdc++.h>
using namespace std;

#define int long long 

inline int read();

const int N=2e5+5;

int T,k,n;

signed main(){
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	T=read();
	while(T--){
		n=read(),k=read();
		if(k==0){
			cout<<1<<endl;
			continue;
		}
		int x=n/100,y=n/10%10,z=n%10;
		if(x==y&&y==z){
			cout<<1<<endl;
			continue;
		}
		if(x!=y&&y!=z&&x!=z){
			if(k==1) cout<<24<<endl;
			else cout<<27<<endl;
			continue;
		}
		if(x==y&&y!=z) {if(k==1)cout<<7<<endl;else cout<<8<<endl;continue;}
		if(x==z&&y!=z) {if(k==1)cout<<7<<endl;else cout<<8<<endl;continue;}
		if(y==z&&x!=z) {if(k==1)cout<<7<<endl;else cout<<8<<endl;continue;}
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

