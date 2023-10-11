#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
const int mod = 1e9 + 7;
int n, m, k;
int he[1000010], su[1000010];
struct node{
	int x, y;
}l[1010], r[1010];
int L, R; 
int ans;
int ksm(int x, int y){
	int s = 1;
	while(y){
		if(y & 1) s = s * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return s;
}
int sum, s;
signed main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
    for(int i = 1 ; i <= 1e6 ; i++) he[i] = su[i] = 1;
    read(n); read(m); read(k);
    for(int i = 1 ; i <= k ; i++){
    	char s;
    	int x, y;
    	cin >> s;
    	read(x); read(y);
    	if(s == 'R') he[x] = (he[x] * y) % mod;
    	else su[x] = (su[x] * y) % mod;
	}
	for(int i = 1 ; i <= m ; i++) sum = (sum + su[i] * i % mod) % mod, s = (s + su[i]) % mod;
	for(int i = 1 ; i <= n ; i++){
		ans = (ans + sum * he[i] % mod) % mod;
		sum = (sum + s * m % mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}
/*
3 4 4
R 2 4
S 4 1
R 3 2
R 2 0
*/

