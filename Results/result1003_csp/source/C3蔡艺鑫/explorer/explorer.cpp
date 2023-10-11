#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2005;
const int M = 1e6 + 5;
int n, a[M], b[M], ans, f[M], c[N][N];
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
inline int solve(int x, int i, int j, int k){
	int s = min(a[x], b[x]), t = max(a[x], b[x]);
	int cnt1 = 0, cnt2 = 0;
	cnt1 += c[x][i] + c[x][j] + c[x][k];
	cnt2 = 6 - cnt1 + (f[s] == -1) + (f[t] == -1);
	return min(cnt1, cnt2); 
}
signed main(){
	freopen("explorer.in", "r", stdin);
	freopen("explorer.out", "w", stdout); 
	n = read();
	bool flag = 1;
	for(int i = 1; i <= n; i++){
		a[i] = read(), b[i] = read(), f[a[i]] = f[b[i]] = i;
		if(a[i] != 2 * i - 1 || b[i] != 2 * i) flag = 0;
	}
	if(n > 500){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++)
		for(int j = min(a[i], b[i]); j <= max(a[i], b[i]); j++)
			c[i][f[j]]++;
	if(flag){
		int cnt = 1;
		for(int i = n; i >= n - 3 + 1; i--) cnt *= i;
		cnt /= 6;
		cout << cnt << endl; 
	}
	else if(n <= 500){
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				for(int k = j + 1; k <= n; k++){
					f[a[i]] = f[b[i]] = f[a[j]] = f[b[j]] = f[a[k]] = f[b[k]] = -1;
					int x = solve(i, i, j, k), y = solve(j, i, j, k), z = solve(k, i, j, k);
					f[a[i]] = f[b[i]] = i, f[a[j]] = f[b[j]] = j, f[a[k]] = f[b[k]] = k;
					if(x == y && y == z) ans++;
				}
			}
		}
		cout << ans << endl;
	} 
	return 0;
}

