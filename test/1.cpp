#include<bits/stdc++.h>
#define lson (x << 1)
#define rson ((x << 1) | 1)
#define mid ((l + r) >> 1)
#define int long long
using namespace std;
const int Maxn = 100010, Maxm = 100000, base = 998244353;
struct Tree{
    int l, r, x;
}tree[Maxn * 80];
int rt[Maxn], a[Maxn];
int tot, n, Q;
int pw[Maxn];
void modify(int la, int &x, int l, int r, int k){
    // cout << la << " " << x << " " << l << " " << r << " " << k << '\n';
    x = ++tot;
    tree[x].l = tree[la].l, tree[x].r = tree[la].r, tree[x].x = tree[x].x;
    if(l == r){
        tree[x].x++;
        return ;
    }
    if(k <= mid) modify(tree[la].l, tree[x].l, l, mid, k);
    else modify(tree[la].r, tree[x].r, mid + 1, r, k);
    tree[x].x = tree[tree[x].l].x * pw[r - mid] + tree[tree[x].r].x;
}
int query(int la, int x, int l, int r, int L, int R){
    // cout << la << " " << x << " " << l << " " << r << " " << L << " " << R << '\n';
    if(L <= l && r <= R) return tree[x].x - tree[la].x;
    if(l > R || r < L) return 0;
    if(R <= mid) return query(tree[la].l, tree[x].l, l, mid, L, R);
    if(L > mid) return query(tree[la].r, tree[x].r, mid + 1, r, L, R);
    return query(tree[la].l, tree[x].l, l, mid, L, R) * pw[r - mid] + query(tree[la].r, tree[x].r, mid + 1, r, L, R);
}
signed main(){
    // ios::sync_with_stdio(false);
    pw[0] = 1;
    for(int i = 1 ; i <= Maxm ; i++) pw[i] = pw[i - 1] * base;
    cin >> n >> Q;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        modify(rt[i - 1], rt[i], 1, Maxm, a[i]);
    }
    // for(int i =1 ; i <= n ; i++) cout << tree[i].r << " ";
    cout << '\n';
    while(Q--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int pre = 1, suf = Maxm;
        int l = 1, r = Maxm;
        while(l <= r){
            // cout << l << " " << r << '\n';
            cout << rt[l - 1] << " " << rt[r1] << '\n';
            // cout << query(rt[l1 - 1], rt[r1], 1, Maxm, 1, mid) << " " << query(rt[l2 - 1], rt[r2], 1, Maxm, 1, mid) << '\n';
            if(query(rt[l1 - 1], rt[r1], 1, Maxm, 1, mid) == query(rt[l2 - 1], rt[r2], 1, Maxm, 1, mid)){
                l = mid + 1;
                pre = l;
            }else r = mid - 1;
        }
        l = 1, r = Maxm;
        while(l <= r){
            // cout << l << " " << r << '\n';
            // cout << query(rt[l1 - 1], rt[r1], 1, Maxm, mid, Maxm) << " " << query(rt[l2 - 1], rt[r2], 1, Maxm, mid, Maxm) << '\n';
            if(query(rt[l1 - 1], rt[r1], 1, Maxm, mid, Maxm) == query(rt[l2 - 1], rt[r2], 1, Maxm, mid, Maxm)){
                r = mid - 1;
                suf = r;
            }else l = mid + 1;
        }
        if(pre == Maxm){
            cout << "YES" << '\n';
            continue;
        }
        cout << pre << " " << suf << '\n';
        if(!query(rt[l1 - 1], rt[r1], 1, Maxm, pre + 1, suf - 1))
            cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
