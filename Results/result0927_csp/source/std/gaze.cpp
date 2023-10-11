#include <bits/stdc++.h>

#define in read()
#define fi first
#define se second
#define pb push_back
#define rep(i, x, y) for(int i = (x); i <= (y); i++) 
#define per(i, x, y) for(int i = (x); i >= (y); i--)

using namespace std;

using ll = long long;
using db = double;
using pii = pair < int , int >;
using vec = vector < int >;
using veg = vector < pii >;

int read() {
	int x = 0; bool f = 0; char ch = getchar(); while(!isdigit(ch)) f |= ch == '-', ch = getchar(); 
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar(); return f ? -x : x;
}

const int N = 2e5 + 10;

int n, m, a[N], t[N], b[N], c[N], d[N];

namespace vpot {
	int arr[N << 2], cnt;
	inline void add(int x) { arr[++cnt] = x; }
	inline void init() { sort(arr + 1, arr + cnt + 1); cnt = unique(arr + 1, arr + cnt + 1) - arr - 1; }
	inline int query(int x) { return lower_bound(arr + 1, arr + cnt + 1,x) - arr; }
}

namespace T {
	int tr[N << 2];
	inline void upd(int x, int v) { for(; x <= vpot :: cnt; x += x & -x) tr[x] += v; }
	inline int query(int x) { int res = 0; for(; x; x -= x & -x) res += tr[x]; return res; }
}

inline void upd(int x, int op) {
	int l = a[x - 1], r = a[x];
	if(l > r) swap(l, r); l++;
	T :: upd(l, op); T :: upd(r + 1, -op);
	l = a[x], r = a[x + 1];
	if(l > r) swap(l, r); l++;
	T :: upd(l, op); T :: upd(r + 1, -op);
}

int main() {
	freopen("gaze.in", "r", stdin); freopen("gaze.out", "w", stdout);
	n = in, m = in; rep(i, 1, n) a[i] = in, vpot :: add(a[i]);
	rep(i, 1, m) {
		t[i] = in;
		if(t[i] == 1) b[i] = in, vpot :: add(b[i]);
		else c[i] = in, d[i] = in, vpot :: add(d[i]);
	}
	vpot :: add(0);
	vpot :: init();
	rep(i, 0, n + 1) a[i] = vpot :: query(a[i]);
	rep(i, 1, n + 1) {
		int l = a[i - 1], r = a[i];
		if(l > r) swap(l, r); l++;
		T :: upd(l, 1); T :: upd(r + 1, -1);
	}
	rep(i, 1, m) {
		if(t[i] == 1) b[i] = vpot :: query(b[i]);
		else d[i] = vpot :: query(d[i]);
		if(t[i] == 1) printf("%d\n", T :: query(b[i]) / 2);
		else {
			upd(c[i], -1); a[c[i]] = d[i]; upd(c[i], 1);
		}
	}
	return 0;
}

