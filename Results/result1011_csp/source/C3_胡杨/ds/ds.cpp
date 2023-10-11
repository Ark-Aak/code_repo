#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	char ch = getchar();
	int f = 1;
	while (!isdigit(ch) && ch ^ '-') ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
	x *= f;
}
int x[10010];
vector<int> a[10010];
int n, Q;
signed main() {
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	read(n); read(Q);
	for(int i = 1 ; i <= n ; i++) read(x[i]);
	for(int i = 1 ; i <= n ; i++) {
		int y;
		read(y);
		a[x[i]].push_back(y);
	}
	while(Q--) {
		int U, R, D, L;
		read(U); read(R); read(D); read(L);
		int Min = L, ans = 0, Max;
		for(int i = U ; i >= D ; i--) {
			Max = 0;
			for(int j = 0 ; j < a[i].size() ; j++) {
				if(a[i][j] >= Min && a[i][j] <= R) {
					ans++;
					Max = max(Max, a[i][j]);
				}
			}
			Min = max(Min, Max);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
