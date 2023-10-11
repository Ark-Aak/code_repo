#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define F(i,a,b) for(int i=a;i<=b;i++)

inline int read() {
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f*=-1;
		c = getchar();
	}
	while(c <= '9' && c>= '0') {
		x = (x << 3) + (x << 1) + (c^48);
		c = getchar();
	}
	return x * f;
}
 
const int N=5005, Mod=998244353;

int n, m, f[N][N], a[N], ans; 

inline int dfs(int u,int lst){
	if(u==n) return 1;
	if(f[u][lst]) return f[u][lst];
	int zexal=0;
	F(i, 1, m) {
		if(i == lst) continue;
		F(j, 1, a[i]) {
			if(u + j > n) break;
			zexal+=dfs(u + j, i) ;
			zexal%=Mod;
		}
	}
	zexal%=Mod;
	return f[u][lst]=zexal;	
}

signed main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	n = read(), m = read();
	F(i, 1, m) a[i] = read();
	//第 i 个地方 上一个选的什么 方案数 
	cout<<(dfs(0,0)+Mod)%Mod;
	return 0;
}
