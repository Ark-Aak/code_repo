#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
int n, m, ans, s;
int vis[10010], p[10010], c[10010];
void dfs(int x){
	if(x > n){
		for(int i = 1 ; i <= n ; i++) c[i] = p[i];
		for(int i = 1 ; i <= n ; i++){
			int x, y;
			for(int j = 1 ; j <= n ; j++) 
			    if(c[j] == i){
			    	x = j - 1;
			    	y = j + 1;
				}
			if(x == 0) x = n;
			if(y == n + 1) y = 1;
			if((c[x] < i && i < c[y] && c[y] > c[x]) || (c[y] < i && i < c[x] && c[x] > c[y])) {
				ans = (ans + 1) % m;
				return; 
			}
			swap(c[x], c[y]);
		}
		return ;
	}
	for(int i = 1 ; i <= n ; i++){
		if(!vis[i]){
			p[x] = i;
			vis[i] = 1;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}
int ou[20];
signed main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
    read(n); read(m);
    if(n % 2 == 1){
    	int ans = 1;
    	for(int i = 1 ; i <= n ; i++) ans = (ans * i) % m;
    	printf("%lld\n", ans);
    	return 0;
	}
    dfs(1);
    printf("%lld\n", ans);
    return 0; 
	return 0;
}


