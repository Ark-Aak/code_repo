#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
const int mod = 998244353;
bitset<4010> a[4010];
map<pair<pair<int,int>,int>,int> mp;
int n;
signed main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
    read(n);
    for(int i = 1 ; i <= n ; i++){
    	for(int j = 1 ; j <= n ; j++){
    		char x;
    		cin >> x;
    		if(x == '1') a[i][j] = 1;
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			for(int k = 1 ; k <= n ; k++){
				if(a[i][j] && a[j][k] && a[k][i]){
					int x = min(i,min(j,k));
					int z = max(i,max(j,k));
					int y = i + j + k - x - z;
					if(!mp[make_pair(make_pair(x,y),z)]){
						ans++;
						mp[make_pair(make_pair(x,y),z)] = 1;
					}
				}
				if(ans >= mod) ans -= mod;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

