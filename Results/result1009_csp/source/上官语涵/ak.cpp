#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
int a[N], b[N], sum[N], vis[N];
priority_queue<int, vector<int> >q1;
priority_queue<int, vector<int>, greater<int> >q2;
int n, k, ans = 0;
void solve() {
	int cnt = 0, num = n;
	while(num > 1) {
		++cnt;
		if(cnt % 2) {
			int Min = 1e9, Mini;
			for(int i = 1; i <= num; i++) {
				sum[i] = sum[i - 1] + a[i];
				if(sum[i] - sum[i - k] < Min) {
					Min = sum[i] - sum[i - k];
					Mini = i;
				}
			}
			ans += Min;
			int tmp = 0;
			for(int i = 1; i <= num; i++) {
				if(Mini - k + 1 <= i && i <= Mini) continue;
				b[++tmp] = a[i];
			}
			num -= k;
			for(int i = 1; i <= tmp; i++) a[i] = b[i];
		} else {
			int Max = 0, Maxi;
			for(int i = 1; i <= num; i++) {
				sum[i] = sum[i - 1] + a[i];
				if(sum[i] - sum[i - k] > Max) {
					Max = sum[i] - sum[i - k];
					Maxi = i;
				}
			}
			ans += Max;
			int tmp = 0;
			for(int i = 1; i <= num; i++) {
				if(Maxi - k + 1 <= i && i <= Maxi) continue;
				b[++tmp] = a[i];
			}
			num -= k;
			for(int i = 1; i <= tmp; i++) a[i] = b[i];
		}
	}
	cout << ans;
}
void solve2() {
	for(int i = 1; i <= n; i++) q1.push(a[i]), q2.push(a[i]);
	int cnt = (n - 1) / k;
	for(int i = 1; i <= cnt; i++) {
		if(i % 2) {
			while(vis[q2.top()]) q2.pop();
			vis[q2.top()] = 1;
			ans += q2.top();
			q2.pop();
		}
		else {
			while(vis[q1.top()]) q1.pop();
			vis[q1.top()] = 1;
			ans += q1.top();
			q1.pop();
		}
	}
	cout << ans;
}
signed main() {
	freopen("ak.in", "r", stdin);
	freopen("ak.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(k == 1) solve2();
	else if(n <= 1000) solve();
}
