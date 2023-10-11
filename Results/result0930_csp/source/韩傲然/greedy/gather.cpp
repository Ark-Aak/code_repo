#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 2e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
#define SEG (int)(N << 2)
#define EG (int)(N << 1)

void read(){};
template<class T1,class ...T2>
inline void read(T1& ret, T2&... rest){
    ret=0; char c = getchar(); bool f = false;
    while(c < '0' || c > '9') {f = c == '-'; c = getchar();}
    while(c >= '0' && c <= '9') {ret = ret * 10 + c - '0'; c = getchar();}
    if(f) ret = -ret;
    read(rest...);
}
int n, b[N];
int sum[N * 40], root[N], ls[N * 40], rs[N * 40];
int nxt[N], pre[N], cnt;
int inxt[N], ipre[N];
void pushup(int k) {
    sum[k] = sum[ls[k]] + sum[rs[k]];
}
void build(int &p, int l, int r) {
    p = ++cnt;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(ls[p], l, mid); build(rs[p], mid + 1, r);
}
void insert(int p, int &q, int l, int r, int x, int v) {
    q = ++cnt;
    sum[q] = sum[p], ls[q] = ls[p], rs[q] = rs[p];
    if(l == r) {sum[q] += v; return;}
    int mid = (l + r) >> 1;
    if(x <= mid) insert(ls[p], ls[q], l, mid, x, v);
    else insert(rs[p], rs[q], mid + 1, r, x, v);
    pushup(q);
}
int query(int p, int q, int l, int r, int x, int y) {
    if(x <= l && r <= y) return sum[q] - sum[p];
    int mid = (l + r) >> 1, res = 0;
    if(x <= mid) res += query(ls[p], ls[q], l, mid, x, y);
    if(y > mid) res += query(rs[p], rs[q], mid + 1, r, x, y);
    return res;
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("gather.in", "r", stdin);
    freopen("gather.out", "w", stdout);
    read(n);
    for(int i = 1; i <= n; i++) read(b[i]);
    fill(nxt + 1, nxt + n + 1, n + 1); fill(pre + 1, pre + n + 1, 0);
    for(int i = n; i >= 1; i--) inxt[i] = nxt[b[i]], nxt[b[i]] = i;
    for(int i = 1; i <= n; i++) ipre[i] = pre[b[i]], pre[b[i]] = i;
    build(root[0], 0, n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x = query(root[ipre[i]], root[i - 1], 0, n + 1, i + 1, n + 1);
        ans += x;
        insert(root[i - 1], root[i], 0, n + 1, inxt[i], 1);
    }
    cout << ans << "\n";
    return 0;
}
