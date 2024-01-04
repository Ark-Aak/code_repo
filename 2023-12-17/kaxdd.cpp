#include <bits/stdc++.h>
namespace IO {
char buff[1 << 21], *p1 = buff, *p2 = buff;
char getch() {
    return p1 == p2 && (p2 = ((p1 = buff) + fread(buff, 1, 1 << 21, stdin)), p1 == p2) ? EOF : *p1++;
}
template <typename T>
void read(T &x) {
    char ch = getch();
    int fl = 1;
    x = 0;
    while (ch > '9' || ch < '0') {
        if (ch == '-')
            fl = -1;
        ch = getch();
    }
    while (ch <= '9' && ch >= '0') {
        x = x * 10 + ch - 48;
        ch = getch();
    }
    x *= fl;
}
template <typename T, typename... Args>
void read(T &x, Args &... args) {
    read(x);
    read(args...);
}
char obuf[1 << 21], *p3 = obuf;
void putch(char ch) {
    if (p3 - obuf < (1 << 21))
        *p3++ = ch;
    else
        fwrite(obuf, p3 - obuf, 1, stdout), p3 = obuf, *p3++ = ch;
}
char ch[100];
template <typename T>
void write(T x) {
    if (!x)
        return putch('0');
    if (x < 0)
        putch('-'), x *= -1;
    int top = 0;
    while (x) ch[++top] = x % 10 + 48, x /= 10;
    while (top) putch(ch[top]), top--;
}
template <typename T, typename... Args>
void write(T x, Args... args) {
    write(x);
    write(args...);
}
void flush() { fwrite(obuf, p3 - obuf, 1, stdout); }
}  // namespace IO
using namespace IO;
using namespace std;
const int MAXN = 1e6 + 5;
int n, m, k, a[MAXN], NOW = 0;
int h[MAXN], L[MAXN], R[MAXN], ans[MAXN], rk[MAXN], pre[MAXN], RW[MAXN];
vector<int> W[MAXN], p[MAXN];
struct Ques {
    int l, r;
} Q[MAXN];
bool cmp(int x, int y) {
    if (Q[x].l == Q[y].l)
        return Q[x].r < Q[y].r;
    return Q[x].l < Q[y].l;
}
struct Sgt_Tree_first {
/*
此线段树的作用有三
1.记录区间答案最大值
2.记录左端点前缀最大r值
3.记录右端点前缀最小l值
因为是不互相包含，所以l,r单调递增
*/
#define ls ((x << 1))
#define rs ((x << 1) | 1)
#define mid ((l + r) >> 1)

    int mx[MAXN << 2], ml[MAXN << 2], mr[MAXN << 2], laz[MAXN << 2];

    Sgt_Tree_first() {
        memset(mr, 0x3f, sizeof mr);
        memset(ml, 0xc0, sizeof ml);
        memset(mx, 0xc0, sizeof mx);
        memset(laz, 0, sizeof laz);
    }

    inline void pushdown(int x) {
        mx[ls] += laz[x];
        mx[rs] += laz[x];
        laz[ls] += laz[x];
        laz[rs] += laz[x];
        laz[x] = 0;
    }

    inline void pushup(int x) {
        mx[x] = max(mx[ls], mx[rs]);
        ml[x] = max(ml[ls], ml[rs]);
        mr[x] = min(mr[ls], mr[rs]);
    }
    //修改位置的信息
    void update(int x, int l, int r, int pos, int v) {
        if (l == r) {
            mx[x] = v;
            // printf("S:%d %d\n",NOW,v);
            if (k < 0)
                ml[x] = -1e9, mr[x] = 1e9;
            else {
                ml[x] = Q[a[l]].l + 1;
                mr[x] = Q[a[l]].r;
            }
            return;
        }
        if (laz[x])
            pushdown(x);
        if (pos <= mid)
            update(ls, l, mid, pos, v);
        else
            update(rs, mid + 1, r, pos, v);
        pushup(x);
    }

    //区间修改值
    void modify(int x, int l, int r, int LL, int RR, int v) {
        if (LL <= l && r <= RR) {
            // printf("S:%d %d\n",NOW,v);
            mx[x] += v;
            laz[x] += v;
            return;
        }
        if (laz[x])
            pushdown(x);
        if (LL <= mid)
            modify(ls, l, mid, LL, RR, v);
        if (mid < RR)
            modify(rs, mid + 1, r, LL, RR, v);
        pushup(x);
    }

    //二分枚举左右端点
    int queryl(int x, int l, int r, int v) {
        if (l == r)
            return l + (ml[x] <= v);
        if (laz[x])
            pushdown(x);
        pushup(x);
        if (ml[ls] <= v)
            return queryl(rs, mid + 1, r, v);
        else
            return queryl(ls, l, mid, v);
    }

    int queryr(int x, int l, int r, int v) {
        if (l == r)
            return l - (mr[x] >= v);
        if (laz[x])
            pushdown(x);
        pushup(x);
        if (mr[rs] >= v)
            return queryr(ls, l, mid, v);
        else
            return queryr(rs, mid + 1, r, v);
    }

    //查询区间最值
    int query(int x, int l, int r) {
        if (l == r)
            return l;
        int res = 0;
        if (laz[x])
            pushdown(x);
        if (mx[ls] >= k)
            res = query(ls, l, mid);
        else if (k <= mx[rs])
            res = query(rs, mid + 1, r);
        pushup(x);
        return res;
    }
} T;

struct Bit_tree {
    /*
    树状数组的作用是维护区间内的动态答案
    以便于我们新增加的区间能够快速计算答案
    */
    int sum[MAXN];
    Bit_tree() { memset(sum, 0, sizeof sum); }
    inline int lowbit(int x) { return x & (-x); }
    inline void add(int x, int k) {
        if (x == 0)
            return;
        for (int i = x; i <= n; i += lowbit(i)) {
            sum[i] += k;
        }
    }
    inline int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) {
            res += sum[i];
        }
        return res;
    }
} B;

struct Sgt_tree_second {
    /*
    这颗线段树维护前缀l端点小于他的
    且还“活着”的右端点最大值
    */
    int sum[MAXN << 2];

    Sgt_tree_second() { memset(sum, 0, sizeof sum); }

    inline void pushup(int x) {
        if (Q[sum[ls]].r >= Q[sum[rs]].r)
            sum[x] = sum[ls];
        else
            sum[x] = sum[rs];
    }

    void build(int x, int l, int r) {
        if (l == r) {
            if (W[l].size())
                sum[x] = W[l][W[l].size() - 1];
            return;
        }
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(x);
    }

    //寻找前缀最大r值
    int query(int x, int l, int r, int pos) {
        if (r <= pos)
            return sum[x];
        int res1 = 0, res2 = 0;
        //因为寻找的是前缀所以l一定合法
        res1 = query(ls, l, mid, pos);
        if (mid < pos)
            res2 = query(rs, mid + 1, r, pos);
        if (Q[res1].r >= Q[res2].r)
            return res1;
        return res2;
    }

    void del(int x, int l, int r, int pos) {
        if (l == r) {
            sum[x] = 0;
            W[l].pop_back();
            if (W[l].size())
                sum[x] = W[l][W[l].size() - 1];
            return;
        }
        if (pos <= mid)
            del(ls, l, mid, pos);
        else
            del(rs, mid + 1, r, pos);
        pushup(x);
    }
} S;
int insert(int id) {
    // printf("YUANSHEN:%d %d\n",NOW,id);
    if (Q[id].l <= 1)
        return 0;
    int x = S.query(1, 1, n, Q[id].l - 1);
    // printf("GEN:%d\n",x);
    // printf("%d\n",id);
    if (x == 0)
        return 0;
    if (Q[x].l <= Q[L[id]].l || Q[x].r <= Q[L[id]].r)
        return 0;
    // printf("YUSNSHENxcs:%d %d %d %d\n",NOW,id,x,L[id]);
    //判断不合法情况
    S.del(1, 1, n, Q[x].l);

    //删除这个点的预备役
    // printf("WWWS\n");
    int val = B.query(Q[x].r) - B.query(Q[x].l) + (h[Q[x].r] >= NOW);
    // printf("XXR:%d %d %d\n",NOW,x,val);
    //计算的是区间分割
    T.update(1, 1, n, rk[x], val);
    L[x] = L[id];
    R[L[id]] = x;
    L[id] = x;
    R[x] = id;
    //链表
    RW[Q[x].r] = x;
    return 1;
}
vector<pair<int, int> > hualian[MAXN];
void solve() {
    for (int i = 2; i <= n; i++) {
        /*
        这个地方写的非常好
        把贡献挂在了最右边
        */
        if (h[i - 1] > h[i]) {
            hualian[h[i - 1]].push_back({ i, 1 });
            hualian[h[i]].push_back({ i, -1 });
        }
    }
    for (NOW = n; NOW >= 1; NOW--) {
        for (auto i : hualian[NOW]) {
            int x = i.first, v = i.second;
            int fl = T.queryl(1, 1, n, x);
            int fr = T.queryr(1, 1, n, x);
            if (fr + 1 <= fl - 1)
                T.modify(1, 1, n, fr + 1, fl - 1, v);
            B.add(x, v);
        }
        for (auto i : p[NOW])
            if (RW[i])
                T.modify(1, 1, n, rk[RW[i]], rk[RW[i]], 1);
        // for(int i=1;i<=2*n;i++) printf("%d %d ",L[i],R[i]);
        // printf("\n");
        while (T.mx[1] >= k) {
            int x = T.query(1, 1, n);
            // printf("OP:%d %d %d\n",x,T.mx[1]);
            T.update(1, 1, n, x, -1e9);
            x = a[x];
            ans[x] = NOW;
            R[L[x]] = R[x];
            L[R[x]] = L[x];
            RW[Q[x].r] = 0;
            int id = R[x];

            // printf("OOOO:%d %d\n",NOW,L[id]);

            while (insert(id)) {
                id = L[id];
                // for(int i=1;i<=2*n;i++) printf("%d %d ",L[i],R[i]);
                // printf("\n");
                // printf("WSSB:%d\n",id);
            }
        }
    }
}
void init() {
    L[0] = 0;
    R[0] = n + 1;
    L[m + 1] = 0;
    R[m + 1] = n + 1;
    Q[m + 1].l = n + 1, Q[m + 1].r = n + 1;
    int id = m + 1;
    //从最后往前递归，找到前面第一个不合法的
    while (insert(id)) {
        id = L[id];
    }
}
signed main() {
    read(n, m, k);
    for (int i = 1; i <= n; i++) {
        read(h[i]);
        p[h[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        read(Q[i].l, Q[i].r);
        W[Q[i].l].push_back(i);
    }
    NOW = n + 1;
    for (int i = 1; i <= m; i++) a[i] = i;
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++) rk[a[i]] = i;
    for (int i = 1; i <= n; i++) {
        sort(W[i].begin(), W[i].end(), [&](int x, int y) { return Q[x].r < Q[y].r; });
    }
    S.build(1, 1, n);
    init();
    solve();
    for (int i = 1; i <= n; i++) {
        if (!ans[i])
            write(-1);
        else
            write(ans[i]);
        putch('\n');
    }
    flush();
    return 0;
}
