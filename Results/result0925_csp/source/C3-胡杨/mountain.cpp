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
int n,a[1000010];
int l[1000010],r[1000010],x;
stack<int> q;
signed main() {
	freopen("mountain.in","r",stdin);
	freopen("mountain.out","w",stdout);
	read(n);
	for(int i = 1 ; i <= n ; i++)
		read(a[i]);
	for(int i = 1 ; i <= n ; i++) {
		while(q.size() && a[q.top()] <= a[i]) q.pop();
		if(q.size()) l[i] = q.top();
		else l[i] = 1;
		q.push(i);
	}
	while(!q.empty()) q.pop();
	for(int i = n ; i >= 1 ; i--) {
		while(q.size() && a[q.top()] <= a[i]) q.pop();
		if(q.size()) r[i] = q.top();
		else r[i] = n;
		q.push(i);
	}
	for(int i = 1 ; i <= n ; i++) cout << r[i] - l[i] - 1 << endl;
	return 0;
}
