#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int& first){
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {if(c == '-') f = -1;c = getchar();}
	while(isdigit(c)){x = (x << 3) + (x << 1) + (c ^ '0');c = getchar();}
	first = x * f;
}
int n;
stack<int> stk;
int ans[500010],a[500010], f[500010];
signed main(){
    freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
    read(n);
    for(int i = 1 ; i <= n ; i++) read(a[i]);
    a[0] = 1e18;
    stk.push(0);
    for(int i = 1 ; i <= n ; i++){
    	while(a[stk.top()] <= a[i]) stk.pop();
    	f[i] = stk.top();
    	stk.push(i);
	}
	for(int i = 1 ; i <= n ; i++) ans[i] = ans[f[i]] + 1;
	for(int i = 1 ; i <= n ; i++) printf("%lld ",ans[i]);
	return 0;
}
