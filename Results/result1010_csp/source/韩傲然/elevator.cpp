#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 5e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
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
int a[N];
int f[N];
int q[N], l = 1, r = 0;
long double K(int ax, int ay, int bx, int by) {
    return ((long double)ay - (long double)by) / ((long double)ax - (long double)bx);
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("elevator.in", "r", stdin);
        freopen("elevator.out", "w", stdout);
    #endif
    read(n, k);
    for(int i = 1; i <= n; a[i]--, i++) read(a[i]);
    sort(a + 1, a + n + 1);
    q[++r] = 0;
    f[0] = 0;
    for(int i = 1; i <= n; i++) {
        while(l < r && (i - q[l] > k || K(q[l], f[q[l]], q[l + 1], f[q[l + 1]]) < (long double)2.0 * a[i])) l++;
        int j = q[l]; 
        f[i] = f[j] - 2 * a[i] * j + 2 * a[i] * n;
        //cout << f[i] << " " << j << " " << q[l + 1] << "\n";
        while(l < r && K(q[r], f[q[r]], q[r - 1], f[q[r - 1]]) > K(q[r], f[q[r]], i, f[i])) r--; 
        q[++r] = i;
    }
    cout << f[n] << "\n";
    return 0;
}