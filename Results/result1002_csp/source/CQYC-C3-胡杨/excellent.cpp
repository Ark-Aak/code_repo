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
int Q;
string s;
signed main(){
    freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout);
    read(Q);
    while(Q--){
    	cin >> s;
    	int n = s.size();
    	//if(n & 1) printf("0\n");
    	//printf("%lld\n", n / 2 - 1);
    	int ans = 0;
    	for(int i = 4 ; i <= n ; i += 2){
    		ans += n / 2 - 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

