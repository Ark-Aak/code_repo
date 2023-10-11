#include<bits/stdc++.h>
#define int unsigned int
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 1e6 + 10, inf = 0x3f3f3f3f;
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
string str;
int q, len;
int f[N][6];
void data1_3() {
    cin >> q;
    for(int t = 1; t <= q; t++) {
        int l, r; cin >> l >> r;
        for(int i = l - 1; i <= r; i++) {
            for(int j = 1; j <= 5; j++) f[i][j] = 0;
        }
        for(int i = l; i <= r; i++) {
            for(int j = 1; j <= 5; j++) f[i][j] = f[i - 1][j];
            if(str[i] == 'm') f[i][1]++;
            if(str[i] == 'i') f[i][2] += f[i - 1][1];
            if(str[i] == 'l') f[i][3] += f[i - 1][2];
            if(str[i] == 'k') f[i][4] += f[i - 1][3];
            if(str[i] == 'y') f[i][5] += f[i - 1][4];
        
        }
        cout << f[r][5] << "\n";
    }
}
void data7() {
    for(int i = 1; i <= len; i++) {
        //for(int j = 1; j <= 5; j++) g[i][j] = g[i - 1][j];
        for(int j = 1; j <= 5; j++) f[i][j] = f[i - 1][j];
        if(str[i] == 'm') f[i][1]++;
        if(str[i] == 'i') f[i][2] += f[i - 1][1];
        if(str[i] == 'l') f[i][3] += f[i - 1][2];
        if(str[i] == 'k') f[i][4] += f[i - 1][3];
        if(str[i] == 'y') f[i][5] += f[i - 1][4];
        
        //for(int j = 1; j <= 5; j++) cout << f[i][j] << " ";
        //cout << "\n----------------\n";
    }
    cin >> q;
    for(int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        cout << f[r][5] << "\n";
    }
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("milky.in", "r", stdin);
    freopen("milky.out", "w", stdout);
    cin >> str;
    len = str.size();
    str = " " + str;
    if(len <= 1000) data1_3();
    else data7();
    return 0;
}
