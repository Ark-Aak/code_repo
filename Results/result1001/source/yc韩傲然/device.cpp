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
int T, n, k;
int cnt[10], sum[4], tot;
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("device.in", "r", stdin);
    freopen("device.out", "w", stdout);
    read(T);
    while(T--) {
        read(n, k); int tmp = n;
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
        while(tmp) cnt[tmp % 10]++, tmp /= 10;
        for(int i = 1; i <= 9; i++) if(cnt[i]) ++tot;
        if(k == 0) cout << "1\n";
        else if(tot == 1) cout << "1\n";
        else if(tot == 2) {
            if(k == 1) cout << "7\n";
            else cout << "8\n";
        }
        else if(tot == 3) {
            if(k == 1) cout << "24\n";
            else cout << "27\n";
        }
    }
    return 0;
}