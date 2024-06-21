#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 2.5e5 + 5, MAXM = MAXN << 5, INF = 1e9;
int n, k, a[MAXN], b[MAXN], root[MAXN];
vector <int> H;

namespace seg {
#define mid ((l+r)>>1)
    ll sum[MAXN*80];
    int cnt[MAXN*80],ls[MAXN*80],rs[MAXN*80],tot=0;
    void modify(int rt,int &x,int l,int r,int pos) {
        x=++tot;
        sum[x]=sum[rt]; cnt[x]=cnt[rt];
        ls[x]=ls[rt]; rs[x]=rs[rt];
        if(l==r) {
            sum[x]+=H[pos - 1];
            cnt[x]++;
            return ;
        }
        if(pos<=mid) modify(ls[rt],ls[x],l,mid,pos);
        else modify(rs[rt],rs[x],mid+1,r,pos);
        sum[x]=(sum[ls[x]]+sum[rs[x]]);
        cnt[x]=(cnt[ls[x]]+cnt[rs[x]]);
    }
    ll query(int A,int B,int l,int r,int K) {
        if(l==r) return min(cnt[A]-cnt[B],K)*H[l - 1];
        int res=cnt[rs[A]]-cnt[rs[B]];
        if(res<K) return sum[rs[A]]-sum[rs[B]]+query(ls[A],ls[B],l,mid,K-res);
        else return query(rs[A],rs[B],mid+1,r,K);
    }
    int querykth(int A,int B,int l,int r,int K) {
        if(l==r) return l;
        int res=cnt[rs[A]]-cnt[rs[B]];
        if(res<K) return querykth(ls[A],ls[B],l,mid,K-res);
        else return querykth(rs[A],rs[B],mid+1,r,K);
    }
#undef mid
}; // namespace seg

namespace minseg {

#define mid ((L + R) >> 1)
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)

int sum[MAXN << 2];

void pushdown(int x) {
	sum[ls(x)] = min(sum[ls(x)], sum[x]);
	sum[rs(x)] = min(sum[rs(x)], sum[x]);
	sum[x] = 0x3f3f3f3f3f3f3f3f;
}

void modify(int x, int L, int R, int l, int r, int p) {
	if (l <= L && R <= r) {
		sum[x] = min(sum[x], p);
		return;
	}
	if (sum[x] < 0x3f3f3f3f3f3f3f3f) pushdown(x);
	if (l <= mid) modify(ls(x), L, mid, l, r, p);
	if (r > mid) modify(rs(x), mid + 1, R, l, r, p);
}

int query(int x, int L, int R, int p) {
	if (L == R) return sum[x];
	if (sum[x] < 0x3f3f3f3f3f3f3f3f) pushdown(x);
	if (p <= mid) return query(ls(x), L, mid, p);
	else return query(rs(x), mid + 1, R, p);
}

} // namespace minseg

int mx[MAXN], ans = -1e18;
vector <int> ps[MAXN];

void solve(int L, int R, int qL, int qR) {
	/* cout << L << " " << R << endl; */
	/* cout << L << " " << R << " " << qL << " " << qR << endl; */
	if (L > R) return;
	int tp = 0;
	mx[mid] = -1e18;
	rep (i, max(mid + k - 1, qL), qR) {
		const int val = seg::query(root[i], root[mid - 1], 1, INF, k);
		const int wgt = val - (a[i] - a[mid - 1]);
		/* cout << wgt << " " << mx[mid] << endl; */
		if (wgt > mx[mid]) vector <int>().swap(ps[mid]), mx[mid] = wgt;
		if (wgt == mx[mid]) ps[mid].push_back(i), tp = i;
	}
	ans = max(ans, mx[mid]);
	solve(L, mid - 1, qL, tp);
	solve(mid + 1, R, tp, qR);
}

void init() {
	sort(H.begin(), H.end());
	H.erase(unique(H.begin(), H.end()), H.end());
}

int find(int x) {
	return lower_bound(H.begin(), H.end(), x) - H.begin() + 1;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
#endif
#endif
	n = read(); k = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) b[i] = read(), H.push_back(b[i]);
	init();
	rep (i, 1, n) b[i] = find(b[i]);
	memset(minseg::sum, 0x3f, sizeof minseg::sum);
	rep (i, 1, n) a[i] += a[i - 1];
	rep (i, 1, n) seg::modify(root[i - 1], root[i], 1, INF, b[i]);
	/* cerr << "sb" << endl; */
	solve(1, n - k + 1, 1, n);
	rep (i, 1, n) {
		if (mx[i] < ans) continue;
		for (auto j : ps[i]) {
			cout << i << " " << j << " " << seg::querykth(root[j], root[i - 1], 1, INF, k) << endl;
			minseg::modify(1, 1, n, i, j, seg::querykth(root[j], root[i - 1], 1, INF, k));
		}
	}
	print(ans), putchar(10);
	rep (i, 1, n) {
		putchar(48 ^ (b[i] >= minseg::query(1, 1, n, i)));
	}
	return 0;
}
