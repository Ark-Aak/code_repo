#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N], b[N], n;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
signed main(){
	freopen("lca.in", "r", stdin);
	freopen("lca.out", "w", stdout); 
	n = read();
	for(int i = 1; i < n; i++) a[i] = read(), b[i] = read();
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if(j >= i && k >= i) cnt += min(j, k);
				else if(j <= i && k <= i) cnt += max(j, k);
				else cnt += i; 
			}
		}	
		cout << cnt << " ";		
	}	
	return 0;
}

