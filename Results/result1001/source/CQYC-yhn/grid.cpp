#include<bits/stdc++.h>
#define int long long
using namespace std;
const double eps=1e-9;
int T,n,m;
struct ok{
	int x,y;
	bool operator < (const ok &A) const{
		return x<A.x;
	}
}a[5]; 
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
signed main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read();
		if(n>m) swap(n,m);
		if(n==1) puts("0");
		else{
			int ans=0;
			for(int i=m;i>=2;i--){
				int d=(int)(2+i)*(i-2+1)/2+i-1;
				ans+=(d*m);
			}
			cout<<ans*(int)2<<"\n";
		}
	}
    return 0;
}

