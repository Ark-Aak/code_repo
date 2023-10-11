#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, a[N], b[N], k, ans[N];
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
signed main(){
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	n = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) b[i] = read();
	for(int x = 2; x <= k; x++){
		for(int i = 1; i <= n; i++)
			ans[a[i]] = b[i];
		for(int i = 1; i <= n; i++) a[i] = b[i];
		for(int i = 1; i <= n; i++) b[i] = ans[i];
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
}

