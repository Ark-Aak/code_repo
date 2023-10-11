#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 205, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
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
int f[N][N][N], T, n;
string str;
void solve40() {
    for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                if(str[i] == str[j] or str[i] == '?' or str[j] == '?') f[i][j][1] = 1;
            }
        }
        for(int len = 2; len <= n; len++) {
            for(int i = 1; i + len * 2 - 1 <= n; i++) {
                for(int j = i + len; j + len - 1 <= n; j++) {
                    int r = i + len - 1, R = j + len - 1;
                    if(f[i][j][len - 1] == 1 and (str[r] == str[R] or str[r] == '?' or str[R] == '?')) 
                        f[i][j][len] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= n; k++) {
                    if(i + 2 * j + 2 * k - 1 > n) break;
                    if(f[i][i + j][j] and f[i + 2 * j][i + 2 * j + k][k]) ans++;
                }
            }
        }
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) for(int k = 1; k <= n; k++)
            f[i][j][k] = 0;
        cout << ans << "\n";
}
void solve15() {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i + 2 * j - 1 > n) break;
            int rest = n - 2 * j - i + 1;
            ans += rest / 2;
        }
    }
    cout << ans << "\n";
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("excellent.in", "r", stdin);
    freopen("excellent.out", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> str; n = str.size(); str = " " + str;
        bool for15 = 1;
        for(int i = 1; i <= n; i++) if(str[i] != '?') for15 = 0;
        if(for15) solve15();
        else solve40();
    }
    return 0;
}
