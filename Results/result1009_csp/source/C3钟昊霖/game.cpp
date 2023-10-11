#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=b;i++)
int n,r,c,T,u,v;

inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c <'0' || c > '9') {
	if (c == '-') f *= -f;
	c = getchar();
	}
	while (c <= '9' && c >= '0') {
	x = (x << 3) + (x << 1) + (c ^ 48);
	c = getchar();
	}
	return x * f;
}
const int N=1005+5;
int f[N][N];

int main(){
	T=read();
	while(T--){
		u=read(),v=read();
		int ans=0;
		for(int i=1;i<=u;i++) f[i][1]=i;
		for(int i=1;i<=u;i++){
			for(int j=2;j<=v;j++){
				if(i!=j)f[i][j]=f[i][j-1]+1;
				if(i==j-1) f[i][j]=f[i][j-2]+2; 
				if(i!=j)ans+=f[i][j];
			//	else ans+=1;
			}
		}
		F(i,1,u) {F(j,1,v) {if(f[i][j]==0) ans-=i;}}
		cout<<ans+1<<endl;
	}

	return 0;
}
