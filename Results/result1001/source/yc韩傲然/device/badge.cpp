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
int n, q;
struct node {
    int l, r, ans;
}a[N];
int m, b[N];
void subtask1() {
    while(q--) {
        read(m);
        int ans = 0;
        for(int i = 1; i <= m; i++) read(b[i]);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(b[j] >= a[i].l && b[j] <= a[i].r) a[i].ans ^= 1;
            }
            ans += a[i].ans;
        }
        cout << ans << "\n";
        for(int i = 1; i <= n; i++) a[i].ans = 0;
    }
}

signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("badge.in", "r", stdin);
    freopen("badge.out", "w", stdout);
    read(n, q);
    for(int i = 1; i <= n; i++) read(a[i].l, a[i].r);
    subtask1();
    return 0;
}