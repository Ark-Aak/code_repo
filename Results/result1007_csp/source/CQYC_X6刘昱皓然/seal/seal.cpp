#include<bits/stdc++.h>
using namespace std;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0'&& ch <= '9') {
		x = (x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
struct node {
	int tim, op;
	bool flag;
};
node a[4005];
int n, t, m, ans, Big[2005], Nobig[2005];
bool big[4005];
double delta = 0.98;
bool cmp(node x, node y) {
	return x.tim < y.tim;
}
int check(node x, node y) {
	if(big[x.op]) {
		if(x.op == y.op)	return 1;
		if(big[y.op])	return 1;
		if(y.flag)	return 1;
		return 0;
	}
	else {
		if(x.flag)	return 0;
		if(big[y.op])	return 1;
		if(y.flag)	return 1;
		return 0;
	}
}
void init() {
	for(int i = 1; i <= m; ++i)	big[i] = 1, Big[i] = i;
	for(int i = 1; i <= n - m; ++i)	Nobig[i] = i + m;
	ans = a[1].tim;
	for(int i = 1; i < n * 2; ++i) {
		ans += (a[i + 1].tim - a[i].tim) * check(a[i], a[i + 1]); 
	}
	ans += t - a[n * 2] . tim;
}
int get_cnt() {
	int sum = a[1].tim;
	for(int i = 1; i < n * 2; ++i) {
		sum += (a[i + 1].tim - a[i].tim) * check(a[i], a[i + 1]); 
	}
	sum += t - a[n * 2] . tim;
	return sum;
}
void SA() {
	double T = 5000;
	while(T >= 1e-3) {
		int x = rand() % m + 1;
		int y = rand() % (n - m) + 1;
		big[Big[x]] = 0;
		big[Nobig[y]] = 1;
		swap(Big[x], Nobig[y]);
		int cnt = get_cnt();
		if(cnt > ans)	ans = cnt;
		else if(exp(ans - cnt) >= (rand() - RAND_MAX) / T) {
			big[Big[x]] = 0;
			big[Nobig[y]] = 1;
			swap(Big[x], Nobig[y]);
		}
		T *= delta;
	}
	return;
}
int main() {
	freopen("seal.in","r",stdin);
	freopen("seal.out","w",stdout);
	srand(20120223);
	n = read(); t = read(); m = read();
	for(int i = 1; i <= n; ++i) {
		int x, y;
		x = read(); y = read();
		a[i * 2 - 1] = {x, i, true};
		a[i * 2] = {y, i, false};
	}
	sort(a + 1, a + 2 * n + 1, cmp);
	init();
	while((double)clock()/CLOCKS_PER_SEC < 0.9)	SA();
	cout<<ans;
	return 0;
} 
