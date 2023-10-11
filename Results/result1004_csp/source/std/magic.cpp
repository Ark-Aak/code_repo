#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e6 + 5;

int n;
int d, ans;
int f[N>>1];
int p[N][4];

struct bal {
	int pos;
	int sum;
};
bal t[N];

int re() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0'||ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while (ch <= '9'&&ch >= '0') {
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*f;
}

int find(int x) { 
	while(x != f[x])
	x = f[x] = f[f[x]];
	return x;
}

void un(int a, int b) {
	a = find(a);
	b = find(b);
	f[a] = b;
}

int cmp(bal a, bal b) {
	return a.sum < b.sum;
}

signed main() {
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout); 
	n = re();
	for(int i = 1; i <= n<<1; i++) 
		f[i] = i;
	for(int i = 1; i <= n; i++) {
		t[i].pos = i; t[i].sum = re();
		p[i][0] = re(); p[i][1] = re();
		p[i][2] = re(); p[i][3] = re();
		un(p[i][0], p[i][1]);
		un(p[i][2], p[i][3]);
	}
	sort(t + 1, t + n + 1, cmp);
	for(int i = 1; i <= n; i++) {
		d = t[i].pos;
		int x = find(p[d][0]);
		int y = find(p[d][2]);
		if(x != y) {
			f[y] = x;
			ans += t[i].sum;
		}
	}
	printf("%d\n", ans); 
	return 0;
}
