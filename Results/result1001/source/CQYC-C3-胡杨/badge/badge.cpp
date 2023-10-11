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
int n, Q, N;
int l[500010], r[500010];
int a[500010];
signed main(){
    freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
    read(N);
    read(Q);
    for(int i = 1 ; i <= N ; i++)
        read(l[i]),read(r[i]);
    while(Q--){
    	read(n);
        memset(a, 0, sizeof a);
        int x;
        for(int i = 1 ; i <= n ; i++) read(x), a[x] = 1;
        for(int i = 1 ; i <= N ; i++) a[i] += a[i - 1];
        int ans = 0;
        for(int i = 1 ; i <= N ; i++){
        	int s = a[r[i]] - a[l[i] - 1];
        	if(s & 1) ans++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

