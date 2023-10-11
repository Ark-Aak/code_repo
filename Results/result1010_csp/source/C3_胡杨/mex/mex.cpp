#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
const int mod = 1e9 + 7;	
int n, k, ans;
int a[5010], b[5010], c[5010];
void dfs(int x){
	if(x > n){
		memset(c, 0, sizeof c);
		for(int i = 1 ; i <= n ; i++) c[a[i]] ++;
		for(int i = 0 ; i <= n + 1 ; i++) if(!c[i]) ans = (ans + i) % mod, i = n + 2;
		return ;
	}
	for(int i = 0 ; i <= b[x] ; i++){
		a[x] = i;
		dfs(x + 1);
	}
}
signed main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
    read(n);
    for(int i = 1 ; i <= n ; i++) read(b[i]);
    dfs(1);
    printf("%lld\n", ans);
	return 0;
}


