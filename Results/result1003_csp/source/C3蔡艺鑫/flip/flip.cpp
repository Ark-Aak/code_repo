#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod = 998244353;
int n, k; 
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
signed main(){
	n = read(), k = read();
	cout << (n + k) * n % Mod;
	return 0;
}

