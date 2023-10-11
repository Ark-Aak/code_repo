#include<bits/stdc++.h>
using namespace std;
namespace fastio {
	struct {
		template<typename T>operator T() {
			T x=0;
			char f=0,c=getchar();
			while(c<'0'||c>'9') {
				if(c=='-')f=1;
				c=getchar();
			}
			while(c>='0'&&c<='9') {
				x=x*10+(c^48);
				c=getchar();
			}
			return f?-x:x;
		}
	} in;
	int stk[40],tp;
	template<typename T>void out(T x,char c=0) {
		if(x<0)putchar('-'),x=-x;
		do stk[++tp]=x%10,x/=10;
		while(x);
		while(tp)putchar(stk[tp--]^48);
		if(c)putchar(c);
	}
} using fastio::in;using fastio::out;
int f[1005][1005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int t;
	t=in;
	for(int i=1;i<=1000;i++) f[i][1]=(i-1);
	for(int i=1;i<=1000;i++) {
		for(int j=2;j<=1000;j++) {
			if(i%2==1) f[i][j]=f[i][j-1]+1;
			else f[i][j]=((j-i)/i);
		}
	}
	for(int i=1;i<=1000;i++) {
		for(int j=1;j<=1000;j++) {
			if(!f[i][j]) f[i][j]=f[j][i];
			if(!f[j][i]) f[j][i]=f[i][j];
		} 
	}
	for(int i=1;i<=1000;i++) f[i][i]=0;
	for(int i=1;i<=1000;i++) {
		for(int j=1;j<=1000;j++) {
			for(int w=1;w<=1000;w++) {
				if(f[i][j]) continue;
				if(i%w==0 && j%w==0) {
					f[i][j]=f[i/w][j/w];
				}
			} 
		}
	}
	while(t--) {
		int x,y;
		cin>>x>>y;
		int sum=0;
		for(int i=1;i<=x;i++) {
			for(int j=1;j<=y;j++) {
				sum+=f[i][j];
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}

