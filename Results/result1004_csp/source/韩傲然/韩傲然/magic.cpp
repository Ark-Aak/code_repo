#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 4e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
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
    int c, p[5];
}a[N];
int f[N];
int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    read(n);
    for(int i = 1; i <= n * 2; i++) f[i] = i;
    for(int i = 1; i <= n; i++) {
        read(a[i].c); 
        for(int j = 1; j <= 4; j++) read(a[i].p[j]);
        f[find(a[i].p[1])] = find(a[i].p[2]);
        f[find(a[i].p[3])] = find(a[i].p[4]);
    }   
    sort(a + 1, a + n + 1, [](node A, node B) {return A.c < B.c;});
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 4; j++) {
            for(int k = j + 1; k <= 4; k++) {  
                int x = find(a[i].p[j]), y = find(a[i].p[k]);
                if(x != y) {
                    f[x] = y;
                    ans += a[i].c;
                    goto NXT;
                }
            }
        }
        NXT : {};
    }
    cout << ans << "\n";
    return 0;
}
