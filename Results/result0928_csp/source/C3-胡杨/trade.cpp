#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
const int maxn = 2010;
int n,m,C;
int a[maxn];
int ans = 0;
vector<int> tree[maxn];
int f[maxn][maxn];
signed main(){
    freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	read(n);read(m);read(C);
	for(int i = 1 ; i <= n ; i++) read(a[i]);
	for(int i = 1 ; i <= m ; i++){
		int x,y;
		read(x);read(y);
		tree[y].push_back(x);
	}
    for(int i = 1 ; i <= 1000 ; i++){
    	for(int j = 1 ; j <= n ; j++){
    		for(int k = 0 ; k < tree[j].size() ; k++){
    			int to = tree[j][k];
    			//if(a[to] + f[i][j] - 2 * i - 1 < 0) break;
    			//f[i + 1][to] = max(f[i + 1][to],f[i][j] + a[to]);
    			f[i][j] = max(f[i][j],f[i - 1][to] + a[j]);
			}
			f[i][j] -= 2 * i * C - 1;
		}
	}
	for(int i = 0 ; i <= 1000 ; i++)
	    ans = max(ans,f[i][1]);
	printf("%lld\n",ans);
	return 0;
}

