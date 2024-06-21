
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 120005, LOG = 18;
int n, m, T;
char s[MAXN];
int a[MAXN];
int px[MAXN], qx[MAXN], pc, qc, pi[MAXN], qi[MAXN];
int h(int x) { return x == 0 ? 0 : __lg(x) + 1; }
int nxt[LOG][LOG][MAXN];
long long ps[LOG][LOG][MAXN], qs[LOG][LOG][MAXN];
int preb[MAXN];
struct SegmentTree {
    vector<pair<int, int>> t[MAXN << 2];
#define lc (i << 1)
#define rc (i << 1 | 1)
    void build(int i = 1, int l = 1, int r = m) {
        if (l == r) {
            int v = a[l];
            if (v == n) t[i] = { { v - 1, v + 1 - n - 1 }, { n, v - n - 1 } };
            else if (n - v - 1 < v - 1) t[i] = { { n - v - 1, v + 1 }, { v - 1, v + 1 - n - 1 }, { n, v - n - 1 } };
            else t[i] = { { v - 1, v + 1 }, { n - v, v }, { n, v - n - 1 } };
            return;
        }
        int mid = (l + r) >> 1;
        build(lc, l, mid), build(rc, mid + 1, r);
        int L = 0;
        for (auto [R, v] : t[lc]) {
            auto it1 = lower_bound(t[rc].begin(), t[rc].end(), make_pair(L + v, INT_MIN));
            auto it2 = lower_bound(t[rc].begin(), t[rc].end(), make_pair(R + v, INT_MIN));
            for (auto it = it1; ; it++) {
                int rr = it == it2 ? R + v : it->first;
                t[i].push_back({ rr - v, v + it->second });
                if (it == it2) break;
            }
            L = R + 1;
        }
    }
    void query(int a, int b, int &v, int i = 1, int l = 1, int r = m) {
        if (a <= l && r <= b) {
            auto p = lower_bound(t[i].begin(), t[i].end(), make_pair(v, INT_MIN));
            v += p->second;
            return;
        }
        int mid = (l + r) >> 1;
        if (a <= mid) query(a, b, v, lc, l, mid);
        if (b > mid) query(a, b, v, rc, mid + 1, r);
    }
} st;
int main() {
    scanf("%d%d%s", &n, &m, s + 1);
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n + 1; i++) if (s[i] != 'R') px[++pc] = i - 1, pi[i - 1] = pc;
    for (int i = n; i >= 0; i--) if (s[i] != 'B') qx[++qc] = n - i, pi[n - i] = qc;
    for (int i = 1; i <= n; i++) preb[i] = preb[i - 1] + (s[i] == 'B');
    for (int x = 0; x < LOG; x++) {
        for (int y = 0; y < LOG; y++) {
            int X = x == 0 ? 0 : (1 << (x - 1));
            int Y = y == 0 ? 0 : (1 << (y - 1));
            nxt[x][y][m + 1] = m + 1;
            for (int i = m; i >= 1; i--) nxt[x][y][i] = (X < a[i] && a[i] < n + 1 - Y) ? i : nxt[x][y][i + 1];
            for (int i = 1; i <= m; i++) {
                ps[x][y][i] = (a[i] <= X ? a[i] : 0) + ps[x][y][i - 1];
                qs[x][y][i] = (a[i] > n - Y ? n - a[i] : 0) + qs[x][y][i - 1];
            }
        }
    }
    st.build();
    scanf("%d", &T);
    while (T--) {
        int l, r; scanf("%d%d", &l, &r);
        int p = 1, q = 1;
        int i = l - 1;
        int t = -1;
        auto Get = [&](int x) {
            if (x <= px[p]) return 'R';
            if (x > n - qx[q]) return 'B';
            return s[x];
        };
        while (1) {
            int x = h(px[p]), y = h(qx[q]);
            int j = min(nxt[x][y][i + 1], r + 1);
            int dp = min(ps[x][y][j - 1] - ps[x][y][i], 1ll * n);
            int dq = min(qs[x][y][j - 1] - qs[x][y][i], 1ll * n);
            if (px[min(pc, p + dp)] + qx[min(qc, q + dq)] < n) {
                p += dp, q += dq, i = j;
                if (j == r + 1) break;
                int bc = preb[n - qx[q]] - preb[px[p]] + qx[q], x = a[j] + (Get(a[j]) == 'B');
                if (x <= bc) {
                    if (x >= bc - qx[q]) { t = n - qx[q] + (x - (bc - qx[q])), l = j + 1; break; }
                    else p += x;
                } else {
                    int ac = n - bc, x = n - a[j] + (Get(a[j]) == 'R');
                    if (x >= ac - px[p]) { t = px[p] - (x - (ac - px[p])), l = j + 1; break; }
                    else q += x;
                }
            } else {
                int L = i + 1, R = j - 1;
                while (L < R) {
                    int mid = (L + R) >> 1;
                    int dp = min(ps[x][y][mid] - ps[x][y][i], 1ll * n);
                    int dq = min(qs[x][y][mid] - qs[x][y][i], 1ll * n);
                    if (px[min(pc, p + dp)] + qx[min(qc, q + dq)] < n) L = mid + 1;
                    else R = mid;
                }
                int dp = min(ps[x][y][L - 1] - ps[x][y][i], 1ll * n);
                int dq = min(qs[x][y][L - 1] - qs[x][y][i], 1ll * n);
                p += dp, q += dq, l = L + 1;
                int bc = preb[n - qx[q]] - preb[px[p]] + qx[q], x = a[L] + (Get(a[L]) == 'B');
                if (x <= bc) {
                    t = n - qx[q] + (x - (bc - qx[q]));
                } else {
                    int ac = n - bc, x = n - a[L] + (Get(a[L]) == 'R');
                    t = px[p] - (x - (ac - px[p]));
                }
                break;
            }
        }
        if (t == -1) {
            int ans = px[p] + n - qx[q] - px[p] - (preb[n - qx[q]] - preb[px[p]]);
            printf("%d\n", ans);
        } else {
            if (l <= r) st.query(l, r, t);
            printf("%d\n", t);
        }
    }
    return 0;
}
