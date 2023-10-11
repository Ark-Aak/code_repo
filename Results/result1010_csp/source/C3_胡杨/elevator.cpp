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
int n, k, ans = 1e18, mm;
int a[500010], b[500010], c[500010];
int flo[2000010];
struct node {
	int flo, per, x;
} s[2000010];
int tot;
bool cmp(node q, node p) {
	if(q.x == p.x) return q.per > p.per;
	return q.x > p.x;
}
void dfs(int x) {
	if(x > n) {
		int s = 0, cnt = n;
		for(int i = 1 ; i <= n ; i++) {
			if(b[i]) {
				int Max = 0;
				for(int j = 1 ; j <= n ; j++) {
					if(c[j] == i) Max = max(Max, a[j] - 1);
				}
				s += Max * cnt * 2;
				cnt -= b[i];
			}
		}
		ans = min(ans, s);
		return ;
	}
	for(int i = 1 ; i <= n ; i++) {
		if(!b[i] && !b[i - 1] && i != 1) continue;
		if(b[i] < k) {
			b[i]++;
			c[x] = i;
			dfs(x + 1);
			b[i]--;
		}
	}
}
signed main() {
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	read(n);
	read(k);
	for(int i = 1 ; i <= n ; i++) {
		read(a[i]);
		flo[a[i]]++;
		mm = max(mm,a[i]);
	}
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}


