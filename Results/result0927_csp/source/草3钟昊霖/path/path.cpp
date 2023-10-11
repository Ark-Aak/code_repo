#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F(i,a,b) for(int i=a;i<=b;i++)
//大师我悟了

const int N = 405;

inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' && c > '9') {
		if (c == '-') f *= -1;
		c = getchar();
	}
	while (c <= '9' && c >= '0') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

int a[N], f[N][N], n, m; //f_{i,j} 表示用 i 结尾 通过 k 次 的Min Cost

signed main() {
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	cin>>n>>m;
	F(i, 1, n) cin>>a[i];
	m+=1;
	memset(f, 0x7f, sizeof f);
	f[0][0] = 0;
	F(i, 1, n) {
		for (int k = 1; k <= m; k++)
		{
			for (int j = i, Max = 0, sum = 0; j >= 1; j--) {
				sum += a[j], Max = max(Max, a[j]);
				f[i][k] = min(f[j-1][k - 1] + Max * (i-j+1) - sum, f[i][k]);
				//cerr << j<<" "<<k <<" "<<f[i][k]<< endl;
			}
		}
	}
	int ans = LONG_LONG_MAX;
	F(i,1,m) ans=min(ans,f[n][i]);
	cout<<ans;
	return 0;
}
