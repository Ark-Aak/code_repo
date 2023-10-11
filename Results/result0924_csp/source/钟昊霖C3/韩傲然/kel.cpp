#include<bits/stdc++.h>
#define int long long 
#define ull unsigned long long
using namespace std;
const int N = 1e6 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
#define SEG (int)(N << 2)
#define EG (int)(N << 1)
int n, L, R;
int a[N];
signed main() {
	freopen("kel.in", "r", stdin);
	freopen("kel.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> L >> R;
	int sum = 0;
//	if(len == 1 && n > 1) {
//		cout << "Shinomiya\n";
//		return 0;
//	}
//	else if(len == 1) {
//		cout << L << "\n";
//	}
	if(n <= 3) {
		for(int i = 1; i <= n; i++) cout << L << "\n";
		return 0;
	}
	for(int i = L; i <= R; i++) {
		for(int j = i; j <= R; j++) {
			//cout << i << "\n";
			a[++sum] = i;
			if(sum == n) break;
			//cout << j << "\n";
			a[++sum] = j;
			if(sum == n) break;
		}
	} 
	if(sum < n) cout << "Shinomiya\n";
	else {
		for(int i = 1; i <= n; i++) cout << a[i] << "\n";
	}
	return 0;
}
