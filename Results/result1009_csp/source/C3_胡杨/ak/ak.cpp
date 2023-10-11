#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
int n, k, sum;
int a[1000010];
signed main(){
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
    read(n); read(k);
    for(int i = 1 ; i <= n ; i++){
    	read(a[i]);
    	sum += a[i];
	}
	sort(a + 1, a + 1 + n);
	int s = n / k / 2 + 1;
	sum -= a[s];
	printf("%lld\n", sum);
	return 0;
}


