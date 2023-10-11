#include<bits/stdc++.h>
#define int long long 
#define ull unsigned long long
using namespace std;
const int N = 2e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f, mod = 1e9 + 7;
#define SEG (int)(N << 2)
#define EG (int)(N << 1)
int n, m;
//map< pair<int, int>, bool > vis;
int d[N];
map< int, int > cnt;
//int maxdeg = -1;
vector<int> exist;
namespace task2 {
	void solve() {
		int ans = 0;
		for(int i = 1; i <= n; i++) 
			cnt[d[i]]++;
		for(auto i : cnt) 
			exist.emplace_back(i.first);
		for(int x = 0; x < exist.size(); x++) {
			for(int y = x + 1; y < exist.size(); y++) {
				int i = exist[x], j = exist[y];
				//cout << i << " " << cnt[i] << " " << j << " " << cnt[j] << " " << (i ^ j) * (i & j) * (i | j) << "\n";
				ans += (i ^ j) * (i & j) * (i | j) * cnt[i] % mod * cnt[j] % mod;
				ans %= mod;
			}
		}
		cout << ans << "\n";
	}
}
signed main() {
	freopen("gen.in", "r", stdin);
	freopen("gen.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		//if(x > y) swap(x, y);
		//if(vis.count({x, y})) continue;
		//vis[{x, y}] = 1;
		//if(i == 5) cout << "666\n";
		d[x]++, d[y]++;
		//maxdeg = max({maxdeg, d[x], d[y]});
	}
	//for(int i = 1; i <= n; i++) cout << d[i] << "\n";
	task2 :: solve();
	return 0;
}
