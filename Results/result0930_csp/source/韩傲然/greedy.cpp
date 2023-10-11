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
int n, k;
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("greedy.in", "r", stdin);
    freopen("greedy.out", "w", stdout);
    read(n, k);
    int lg = __lg(n);
    if(n != (1ll << lg)) lg++;
    if(k == 1) cout << (n - 1) % 147744151 << "\n";
    else if(k >= lg) cout << lg << "\n";
    return 0;
}
