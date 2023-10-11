#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	char ch = getchar();
	int f = 1;
	while (!isdigit(ch) && ch ^ '-') ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
	x *= f;
}
int n,K;
int Max,ans = 1e18;
int a[410],s[410];
int f[410][410];
//void dfs(int x,int k,int v,int s){
//	//cout << x << " " << k<<" "<<v<<" "<<s<<endl;
//	if(x > n){
//		ans = min(ans,s);
//		return ;
//	}
//	if(k < K){
//		for(int i = x ; i <= n ; i++)
//		    if(a[i] >= a[x])
//			    dfs(x + 1,k + 1,a[i],s + a[i] - a[x]);
//	}
//	if(k >= K && v < a[x]) return;
//	if(a[x] <= v)
//	    dfs(x + 1,k,v,s + v - a[x]);
//}
signed main() {
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	read(n);
	read(K);
	for(int i = 1 ; i <= n ; i++) read(a[i]),Max = max(Max,a[i]);
	memset(f,0x3f,sizeof f);
	for(int i = 1 ; i <= n ; i++) s[i] = s[i - 1] + a[i];
	//for(int i = 1 ; i <= n ; i++) dfs(1,0,a[i],0);
	//printf("%lld\n",ans);
	f[0][0] = f[1][0] = 0;
	for(int i = 1 ; i <= n ; i++){
		int Max = 0;
		for(int j = i  ; j <= n ; j++){
			Max = max(a[j],Max);
			for(int k = 1 ; k <= K ; k++){
				//cout << Max << endl;
				f[j][k] = min(f[j][k],f[i - 1][k - 1] + Max * (j - i + 1) - s[j] + s[i - 1]);
			}
		}
	}
//	for(int i = 0 ; i <= n ; i++){
//		for(int k = 0 ;k<=K ; k++)
//	        cout << f[i][k] <<" ";
//	    cout << endl;
//	}
//	    
	int ans = 1e18;
	for(int i = 1 ; i <= K ; i++)
	    ans = min(ans,f[n][i]);
	cout << ans << endl;
	return 0;
}
/*
50 10
1 9 8 6 4 5 3 4 1 4
3 5 9 7 5 4 3 1 5 3
4 8 9 5 6 4 2 1 9 7
1 3 5 1 6 7 1 3 3 4
4 3 2 1 5 9 7 8 4 3
*/
