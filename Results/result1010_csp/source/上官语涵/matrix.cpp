#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
string s[N];
struct node {
	int cnt0, cnt1;
}a[N];
signed main() {
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	int n, m, ans = 1e18;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for(int i = 0; i < (1 << n); i++) {
		memset(a, 0, sizeof(a));
		int sum = 0;
		for(int j = 0; j < m; j++) {
			for(int l = 0; l < n; l++) {
				if(i & (1 << l)) {
					if(s[j][l] == '1') a[j].cnt0++;
					else a[j].cnt1++;
				}
				else {
					if(s[j][l] == '1') a[j].cnt1++;
					else a[j].cnt0++;
				}
			}
			sum += min(a[j].cnt0, a[j].cnt1);
			if(sum > ans) break;
		}
		ans = min(ans, sum);	
	}
	cout << ans;
}
