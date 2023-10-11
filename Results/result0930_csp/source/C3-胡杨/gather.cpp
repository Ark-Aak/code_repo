#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
const int maxn = 2 * 1e5 + 10;
int a[maxn];
int n;
int b[5010][5010];
int ans;
signed main(){
    freopen("gather.in","r",stdin);
    freopen("gather.out","w",stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
    	read(a[i]);
    	b[a[i]][i]++;
	} 
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= n ; j++)
			b[i][j] += b[i][j - 1];
    for(int i = 1 ; i <= n ; i++){
    	for(int j = i + 1 ; j <= n ; j++){
    		if(b[a[i]][j] - b[a[i]][i - 1] == 1 && b[a[j]][j] - b[a[j]][i - 1] == 1) ans++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
