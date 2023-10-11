#include <bits/stdc++.h>
using namespace std;
#define F(i, a, b) for (int i = a; i <= b; i++) 

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
const int N=2e5+5;
int n,k,a[N],sum[N];

int f[100][100][2];

inline int Dp(int l,int r,int p){
	if(l==r) return 0;
	if(f[l][r][p]) return f[l][r][p];
	if(p){
		return f[l][r][p]=min(Dp(l+k,r,!p)+sum[l+k]-sum[l],Dp(l,r-k,!p)+sum[r]-sum[r-k]);
	}else{
		return f[l][r][p]=max(Dp(l+k,r,!p)+sum[l+k]-sum[l],Dp(l,r-k,!p)+sum[r]-sum[r-k]);
	}
}

signed main() {
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
 	n=read(),k=read();
 	F(i, 1, n) a[i] = read();
 	if(n<=50){
 		F(i, 1, n) sum[i] = sum[i - 1] + a[i];
	 	Dp(1, n, 1);
		cout<<f[1][n][1];
		return 0;
	}
	return 0;
}
