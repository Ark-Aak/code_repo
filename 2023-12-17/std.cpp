#include <bits/stdc++.h>
#define For(i, a, b) for (int i = a, i##end = b; i <= i##end; i++)
#define Rof(i, a, b) for (int i = a, i##end = b; i >= i##end; i--)
#define rep(i, b) for (int i = 1, i##end = b; i <= i##end; i++)
using namespace std;
const int N = 4e6 + 9;
void chmx(int &x, int y) { (x < y) && (x = y); }
void chmn(int &x, int y) { (x > y) && (x = y); }
int read() {
    int f = 0, x = 0;
    char ch = getchar();
    while (!isdigit(ch)) {
        f |= (ch == '-');
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f ? -x : x;
}
int n, m, k, h[N], rk[N], a[N], NOW, ans[N];
struct node {
    int l, r;
    bool operator<(const node &X) const { return l == X.l ? r < X.r : l < X.l; }
} Q[N];
int R[N], L[N];
int Rwhere[N];
struct tree1 {
    int mx[N], tag[N], mnr[N], mxl[N];
    tree1() {
        memset(mnr, 0x3f, sizeof mnr);
        memset(mxl, 0xc0, sizeof mxl);
        memset(mx, 0xc0, sizeof mx);
        memset(tag, 0, sizeof tag);
    }
#define ls p << 1
#define rs p << 1 | 1
    void push_down(int p) {
        mx[ls] += tag[p];
        mx[rs] += tag[p];
        tag[ls] += tag[p];
        tag[rs] += tag[p];
        tag[p] = 0;
    }
    void change(int p, int l, int r, int x, int v) {
        if (l == r) {
            mx[p] = v;
            if (v < 0) {
                mxl[p] = -1e9, mnr[p] = 1e9;
            } else {
                mxl[p] = Q[a[l]].l + 1, mnr[p] = Q[a[l]].r;
            }
            return;
        }
        int mid = (l + r) >> 1;
        push_down(p);
        if (mid >= x)
            change(ls, l, mid, x, v);
        else
            change(rs, mid + 1, r, x, v);
        mx[p] = max(mx[ls], mx[rs]);
        mxl[p] = max(mxl[ls], mxl[rs]);
        mnr[p] = min(mnr[ls], mnr[rs]);
    }
    int findl(int p, int l, int r, int x) {
        if (l == r) {
            return l + (mxl[p] <= x);
        }
        int mid = (l + r) >> 1;
        if (mxl[ls] <= x)
            return findl(rs, mid + 1, r, x);
        return findl(ls, l, mid, x);
    }
    int findr(int p, int l, int r, int x) {
        if (l == r) {
            return l - (mnr[p] >= x);
        }
        int mid = (l + r) >> 1;
        if (mnr[rs] >= x)
            return findr(ls, l, mid, x);
        return findr(rs, mid + 1, r, x);
    }
    void add(int p, int l, int r, int nl, int nr, int v) {
        if (nl <= l && r <= nr) {
            tag[p] += v;
            mx[p] += v;
            return;
        }
        int mid = (l + r) >> 1;
        push_down(p);
        if (mid >= nl)
            add(ls, l, mid, nl, nr, v);
        if (mid < nr)
            add(rs, mid + 1, r, nl, nr, v);
        mx[p] = max(mx[ls], mx[rs]);
        mxl[p] = max(mxl[ls], mxl[rs]);
        mnr[p] = min(mnr[ls], mnr[rs]);
    }
    int get(int p, int l, int r) {
        if (l == r)
            return l;
        int mid = (l + r) >> 1, res = 0;
        push_down(p);
        if (mx[ls] >= k)
            res = get(ls, l, mid);
        else if (mx[rs] >= k)
            res = get(rs, mid + 1, r);
        mx[p] = max(mx[ls], mx[rs]);
        return res;
    }
} T1;
struct BIT {
#define lowbit(x) (x & -x)
    int sum[N];
    BIT() { memset(sum, 0, sizeof sum); }
    int get(int x, int res = 0) {
        while (x) res += sum[x], x -= lowbit(x);
        return res;
    }
    void add(int x, int v) {
        while (x <= n) sum[x] += v, x += lowbit(x);
    }
} T2;
vector<int> A[N];
struct tree2 {
    int mx[N];
    tree2() { memset(mx, 0, sizeof mx); }
#define ls p << 1
#define rs p << 1 | 1
    void build(int p, int l, int r) {
        if (l == r) {
            if (A[l].size())
                mx[p] = A[l][A[l].size() - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        mx[p] = (Q[mx[ls]].r >= Q[mx[rs]].r ? mx[ls] : mx[rs]);
    }
    int get(int p, int l, int r, int x) {
        if (r <= x) {
            return mx[p];
        }
        int mid = (l + r) >> 1, id1 = 0, id2 = 0;
        id1 = get(ls, l, mid, x);
        if (mid < x)
            id2 = get(rs, mid + 1, r, x);
        return Q[id1].r >= Q[id2].r ? id1 : id2;
    }
    void pop(int p, int l, int r, int x) {
        if (l == r) {
            A[l].pop_back();
            mx[p] = 0;
            if (A[l].size())
                mx[p] = A[l][A[l].size() - 1];
            return;
        }
        int mid = (l + r) >> 1;
        if (mid >= x)
            pop(ls, l, mid, x);
        else
            pop(rs, mid + 1, r, x);
        mx[p] = (Q[mx[ls]].r >= Q[mx[rs]].r ? mx[ls] : mx[rs]);
    }
} T3;
vector<int> pos[N];
bool insert(int id) {  //找到左端点比这个小的，最右的端点的编号
    if (Q[id].l <= 1)
        return false;
    int x = T3.get(1, 1, n, Q[id].l - 1);
	cout << "de:" << id << " " << x << " " << Q[id].l << endl;
    if (x == 0)
        return false;  //没了，找不到
    if (Q[x].l <= Q[L[id]].l || Q[x].r <= Q[L[id]].r)
        return false;
    T3.pop(1, 1, n, Q[x].l);  //找到了，弹掉
    int val = T2.get(Q[x].r) - T2.get(Q[x].l) + (h[Q[x].r] >= NOW ? 1 : 0);
    //重算贡献
	cout << "newAns:" << val << endl;
    T1.change(1, 1, n, rk[x], val);  //加入到第一棵树上
    L[x] = L[id];
    R[L[x]] = x;  //更新链表
    L[id] = x;
    R[x] = id;
    Rwhere[Q[x].r] = x;
    return true;
}
void init() {
    L[0] = 0;
    R[0] = n + 1;
    L[m + 1] = 0;
    R[m + 1] = n + 1;
    Q[m + 1].l = Q[m + 1].r = n + 1;
    int id = m + 1;
    while (insert(id)) id = L[id];
	cout << "finish init" << endl;
    return;
}
vector<tuple<int, int> > OP[N];
void solve() {
    For(i, 2, n) if (h[i - 1] > h[i]) {  //可能出现10的状态
        OP[h[i - 1]].push_back(make_tuple(i, 1));
        OP[h[i]].push_back(make_tuple(i, -1));
		cout << "id:" << i << endl;
    }
    for (NOW = n; NOW >= 1; NOW--) {
        for (auto tp : OP[NOW]) {
            int x, v;
            tie(x, v) = tp;
            int ll = T1.findl(1, 1, n, x);  // ll不合法一直到n
            int rr = T1.findr(1, 1, n, x);  // 1不合法到rr
			cout << "info:" << x << " " << v << endl;
			cout << "inv:" << ll << " " << rr << endl;
            if (rr + 1 <= ll - 1)
                T1.add(1, 1, n, rr + 1, ll - 1, v);
            T2.add(x, v);  //树状数组
        }
        for (int x : pos[NOW])
            if (Rwhere[x]) {
				cout << "wh:" << x << endl;
                T1.add(1, 1, n, rk[Rwhere[x]], rk[Rwhere[x]], 1);
			}
		cout << "mx:" << T1.mx[1] << endl;
        while (T1.mx[1] >= k) {                                    //如果有合法的
			cout << "mx:" << T1.mx[1] << endl;
            int x = T1.get(1, 1, n);                               //找到这个点
            T1.change(1, 1, n, x, -1e9);                           //给他改了
            x = a[x];                                              //找到这个编号
            ans[x] = NOW;                                          //更新答案
            R[L[x]] = R[x];                                        //链表删除
            L[R[x]] = L[x];
            Rwhere[Q[x].r] = 0;
            int id = R[x];  //继续加入
            while (insert(id)) {
                id = L[id];
            }
        }
    }
}
signed main() {
    n = read(), m = read(), k = read();
    NOW = n + 1;
    rep(i, n) h[i] = read(), pos[h[i]].push_back(i);
    rep(i, m) {
        Q[i].l = read();
        Q[i].r = read();
        A[Q[i].l].push_back(i);
    }
    rep(i, m) a[i] = i;
    sort(a + 1, a + 1 + m, [&](int x, int y) { return Q[x] < Q[y]; });
    rep(i, m) rk[a[i]] = i;
    rep(i, n) sort(A[i].begin(), A[i].end(), [&](int x, int y) { return Q[x].r < Q[y].r; });
    T3.build(1, 1, n);
    init();
    solve();
    rep(i, m) printf("%d\n", (ans[i] ? ans[i] : -1));
    return 0;
}
