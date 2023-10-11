#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 500, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
#define SEG (int)(N << 2)
#define EG (int)(N << 1)

void read(){};
template<class T1,class ...T2>
inline void read(T1& ret,T2&... rest){
	ret=0;char c=getchar();bool f=false;
	while(c<'0'||c>'9'){f=c=='-';c=getchar();}
	while(c>='0'&&c<='9'){ret=ret*10+c-'0';c=getchar();}
	if(f)ret=-ret;
	read(rest...);
}
int n, K;
int a[N];
int f[N][N];
int mx[N][N];
int sum = 0;
signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	read(n, K);
	K++;
	for(int i = 1; i <= n; sum += a[i], i++) read(a[i]);
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			mx[i][j] = max(mx[i][j - 1], a[j]);
		}
	}
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	int ans = inf;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= K; j++) {
			for(int k = 0; k < i; k++) {
				f[i][j] = min(f[i][j], f[k][j - 1] + mx[k + 1][i] * (i - k));
			}
			if(i == n) ans = min(ans, f[i][j]);
		}
	}
	cout << ans - sum << "\n";
	return 0;
}
