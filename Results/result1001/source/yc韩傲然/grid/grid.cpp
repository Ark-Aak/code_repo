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
int T, n, m;
void subtask1() {
    if(n < m) swap(n, m); 
    if(m == 1) {
        cout << "0\n";
        return; 
    }
    int ans = n * m * ((n * m - 1) * (n * m - 2) - (n - 1) * (n - 2) - (m - 1) * (m - 2)) / 2;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int l = i - 1, r = n - i, L = j - 1, R = m - j;
            ans += l * r * (m - 1) * n + L * R * (n - 1) * m;
        }
    }
    cout << ans << "\n";
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("grid.in", "r", stdin);
    freopen("grid.out", "w", stdout);
    read(T);
    while(T--) {
        read(n, m);
        subtask1();
    }
    return 0;
}