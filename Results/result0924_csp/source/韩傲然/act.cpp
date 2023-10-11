#include<bits/stdc++.h>
#define int long long 
#define ull unsigned long long
using namespace std;
const int N = 1e6 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
#define SEG (int)(N << 2)
#define EG (int)(N << 1)
int n, q;
int a[N], b[N];
signed main() {
	freopen("act.in", "r", stdin);
	freopen("act.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	if(q == 0) return 0;
	if(n == 0) {
		while(q--) {
			int x, y;
			cin >> x >> y;
			if(x == y) cout << "Bob\n";
			else cout << "Alice\n";
		}
	}
	return 0;
}
