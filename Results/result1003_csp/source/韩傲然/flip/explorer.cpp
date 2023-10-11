#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 1e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
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
int n, p10 = 1;
struct node {
    int x, y;
}a[N];
void solve10() {
    cout << n * (n - 1) * (n - 2) / 6 << "\n";
}
int getval(node *a) {
    int l = a[1].x, r = a[1].y, L = a[2].x, R = a[2].y, x = a[3].x, y = a[3].y;
    if(r < L and R < x) return 1;
    if(L < r and x < r and R > r and y > r and R < y) return 1;
    if(x > R and y < r) return 1;
    return 0;
}
void solve20() {
    for(int i = 1; i <= n; i++) {
        if(a[i].x > a[i].y) swap(a[i].x, a[i].y);
    }
    sort(a + 1, a + n + 1, [](const node A, const node B) {return A.x < B.x;});
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = j + 1; k <= n; k++) {
                node tmp[4] = {a[0], a[i], a[j], a[k]};
                ans += getval(tmp);
                //if(getval(tmp) == 1) cout << i << " " << j << " " << k << "\n";
            }
        }
    }
    cout << ans << "\n";
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("explorer.in", "r", stdin);
    freopen("explorer.out", "w", stdout);
    read(n);
    for(int i = 1; i <= n; p10 = p10 * (a[i].x == i * 2 - 1 and a[i].y == i * 2), i++) read(a[i].x, a[i].y);
    if(p10) solve10();
    else solve20();
    return 0;
}