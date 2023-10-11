#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
int n,k;
int main(){
    freopen("greedy.in","r",stdin);
    freopen("greedy.out","w",stdout);
    read(n);
    read(k);
    if(k == 1){
    	printf("%lld\n",n / 2 + n % 2);
        return 0;
	}
	if(k >= 100){
		int ans = log2(n) + 1;
		printf("%lld\n",ans);
		return 0;
	}
	return 0;
}

