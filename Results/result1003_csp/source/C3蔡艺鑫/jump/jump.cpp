#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
const int INF = 1e9 + 5;
stack<int> Q;
int a[N], n; 
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
signed main(){
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout); 
	Q.push(INF);
	n = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
		while(a[i] >= Q.top()) Q.pop();
		Q.push(a[i]);
		cout << Q.size() - 1 << " ";
	}
	return 0;
}

