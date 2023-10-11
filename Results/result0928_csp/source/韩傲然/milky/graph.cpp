#include<bits/stdc++.h>
#define int long long 
#define ls (k << 1)
#define rs (k << 1 | 1)
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 2e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
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
int n;
struct node {
    int x, y;
}a[N];
int b[N], tot, ans;
int sum[N << 2], cov[N << 2];
void pushup(int k) {sum[k] = sum[ls] + sum[rs];}
void pushdown(int k) {
    if(cov[k]) {
        cov[ls] = cov[rs] = 1;
        sum[ls] = sum[rs] = 0;
        cov[k] = 0;
    }
}
void modify(int k, int l, int r, int x, int y) {
    if(x <= l && r <= y) {
        cov[k] = 1;
        sum[k] = 0;
        return;
    }
    pushdown(k);
    int mid = (l + r) >> 1;
    if(x <= mid) modify(ls, l, mid, x, y);
    if(y > mid) modify(rs, mid + 1, r, x, y);
    pushup(k);
}
void add(int k, int l, int r, int x) {
    if(l == r) {
        sum[k]++;
        return;
    }
    pushdown(k);
    int mid = (l + r) >> 1;
    if(x <= mid) add(ls, l, mid, x);
    else add(rs, mid + 1, r, x);
    pushup(k);
}
int query(int k, int l, int r, int x, int y) {
    if(x <= l && r <= y) return sum[k];
    pushdown(k);
    int mid = (l + r) >> 1, res = 0;
    if(x <= mid) res += query(ls, l, mid, x, y);
    if(y > mid) res += query(rs, mid + 1, r, x, y);
    return res;
}
int getpos(int x) {
    int l = 1, r = tot, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(query(1, 1, tot, 1, mid) >= 1) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    return ans;
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    read(n);
    for(int i = 1; i <= n; i++) {
        read(a[i].x, a[i].y);
        b[++tot] = a[i].y;
    }
    sort(b + 1, b + tot + 1);
    tot = unique(b + 1, b + tot + 1) - b - 1;
    sort(a + 1, a + n + 1, [](node x, node y) {
        if(x.x != y.x) return x.x < y.x;
        return x.y < y.y;
    });
    for(int i = 1; i <= n; i++) {
        a[i].y = lower_bound(b + 1, b + tot + 1, a[i].y) - b;
        int x = query(1, 1, tot, 1, a[i].y);
        ans -= x;
        ans++;
        if(x) {
            int pos = getpos(a[i].y);
            modify(1, 1, tot, pos, a[i].y);
            add(1, 1, tot, pos);
        }
        else add(1, 1, tot, a[i].y);
    }
    cout << ans << "\n";
    return 0;
}
