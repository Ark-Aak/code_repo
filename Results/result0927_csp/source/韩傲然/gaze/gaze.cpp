#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
#define ls (k << 1)
#define rs (k << 1 | 1)
using namespace std;
const int N = 8e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
#define SEG (int)(N << 2)
#define EG (int)(N << 1)

void read(){};
template<class T1,class ...T2>
inline void read(T1& ret,T2&... rest){
	ret=0;char c=getchar();bool f=false;
	while(c<'0'||c>'9'){f=c=='-';c=getchar();}
	while(c>='0'&&c<='9'){ret=ret*10+c-'0';c=getchar();}
	if(f)ret=-ret;
	read(rest...);
}
int cov[N << 5], cnt[N << 5], lc[N << 5], rc[N << 5];
int n, m;
void pushup(int k) {
	if(cov[k]) {
		cnt[k] = 1;
		lc[k] = rc[k] = 1;
	}
	else {
		cnt[k] = cnt[ls] + cnt[rs] - (rc[ls] && lc[rs]);
		lc[k] = lc[ls]; rc[k] = rc[rs];
	}
}
void build(int k, int l, int r) {
	cnt[k] = cov[k] = 1;
	if(l == r) {
		lc[k] = rc[k] = 1;
		return;
	}
	int mid = (l + r) / 2;
	build(ls, l, mid); build(rs, mid + 1, r);
	pushup(k);
}
void modify(int k, int l, int r, int x, int y, int v) {
	if(k > N || k < 1) cerr << k << " " << l << " " << r << " " << x << " " << y << "\n";
	cov[k] = 0; 
	if(x <= l && r <= y) {
		cov[k] = 0; 
		pushup(k);
		return;
	}
	int mid = (l + r) / 2;
	if(x <= mid) modify(ls, l, mid, x, y, v);
	if(y > mid) modify(rs, mid + 1, r, x, y, v);
	pushup(k);
}
struct OPT{
	int opt, x, y, ti;
}op[N];
struct Line {
	int l, r, h;
}line[N * 2];
int tot;
int a[N], ans[N];
void subtask2() {
	memset(ans, 0x3f, sizeof(ans));
	sort(line, line + tot + 1, [](Line x, Line y) {
		if(x.h != y.h) return x.h < y.h;
		return x.l < y.l;
	});
	sort(op, op + m + 1, [](OPT x, OPT y) {
		return x.x < y.x;
	});
	build(1, 1, n);
	for(int i = 1, p = 1; i <= m; i++) {
		for(; line[p].h < op[i].x && p <= tot; p++) {
			modify(1, 1, n, line[p].l, line[p].r, -1);
		}
		ans[op[i].ti] = cnt[1]; // !!!!!!!!!!!!!!!
	}
	for(int i = 1; i <= m; i++) if(ans[i] != INF) cout << ans[i] << "\n";
}
void subtask1() {
	a[n + 1] = -inf;
	for(int i = 1; i <= m; i++) {
		if(op[i].opt == 1) {
			int ans = 0;
			for(int j = 1; j <= n + 1; j++) {
				if(a[j] < op[i].x) {
					if(a[j - 1] >= op[i].x) ans++;
				}
				
			}
			cout << ans << "\n";
		}
		else {
			a[op[i].x] = op[i].y;
		}
	}
}
signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	freopen("gaze.in", "r", stdin);
	freopen("gaze.out", "w", stdout);
	read(n, m);
	for(int i = 1; i <= n; i++) {
		read(a[i]);
	}
	int v = a[1], cnt = 1;
	for(int i = 1; i <= n; i++) {
		if(a[i + 1] != v) {
			line[++tot] = {i - cnt + 1, i, v};
			cnt = 1, v = a[i + 1];
		}
		else cnt++;
	}

	for(int i = 1; i <= m; i++) { 
		int opt, x, y = 0; read(opt);
		if(opt == 1) 
			read(x);
		else read(x, y);
		op[i] = {opt, x, y, i};
	}
	if(n <= 2000 && m <= 2000) subtask1();
	else subtask2();
	return 0;
}
