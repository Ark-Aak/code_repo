#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
constexpr int N = 1e6 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f, inv = 1e9;
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
string a, s;
bool f[N][11], le[N][11], ri[N][11];
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("yo.in", "r", stdin);
        freopen("yo.out", "w", stdout);
    #endif
    cin >> n >> a >> s; a = " " + a, s = " " + s;
    //for(int i = 1; i <= 10; i++) y[i] = o[i] = 1;
    f[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        int x = a[i] - '0';
        for(int j = 0; j <= 10; j++) {
            if(f[i - 1][j]) {
                f[i][j * 10 % 11] = f[i][(j * 10 + x) % 11] = 1;
            }
        }
    }
    if(!f[n][0]) cout << "oimiya\n";
    else if(s[1] == 'y') cout << "yoimiya\n";
    else {
        for(int i = 1; i <= 10; i++) if(f[n][i]){cout << "oimiya\n"; return 0;} 
    }
    return 0;
}