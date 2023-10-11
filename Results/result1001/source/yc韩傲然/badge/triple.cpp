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
int a[4], b[4], c[4], d[4];
int T;
int subtaskA() {
    if(c[1] == 0 && c[2] == 0 && c[3] == 0) return 0;
    if(c[2] == c[3] || c[2] == 0 || c[3] == 0) return 1;
    if((d[2] != -1 && d[3] != -1 && d[2] == d[3]) || (d[2] == 1) || (d[3] == 1)) return 1;
    return 2;
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("triple.in", "r", stdin);
    freopen("triple.out", "w", stdout);
    read(T);
    while(T--) {
        read(a[1], a[2], a[3]);
        read(b[1], b[2], b[3]);
        for(int i = 1; i <= 3; i++) c[i] = b[i] - a[i];
        for(int i = 1; i <= 3; i++) {
            if(a[i] == 0) d[i] = -1;
            else d[i] = (b[i] % a[i] == 0) ? b[i] / a[i] : -1;
        }
        if(a[1] == b[1]) cout << subtaskA() << "\n";
    }
    return 0;
}