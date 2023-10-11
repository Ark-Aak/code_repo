#include<bits/stdc++.h>
#define int long long 
#define ull unsigned long long
using namespace std;
const int N = 1e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
#define SEG (int)(N << 2)
#define EG (int)(N << 1)
int a[N];
int n, x;
signed main() {
	freopen("fight.in", "r", stdin);
	freopen("fight.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x;
	for(int i = 1; i < n; i++) 
		cin >> a[i];
	for(int i = 1; i <= n; i++) cout << fixed << setprecision(9) << (double)1 / n << "\n";
	return 0;
}
