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
int n,ans; 
struct node{
	int x,y;
}a[500010];
int t;

signed main(){
    freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout);
    read(n);
    for(int i = 1 ; i <= n ; i++){
    	read(a[i].x),read(a[i].y);
    	if(a[i].y < a[i].x) swap(a[i].x, a[i].y);
    	if(a[i].y - a[i].x != 1) t = 1;
	} 
	if(t == 0){
		ans = n * (n - 1) * (n - 2) / 6;
		printf("%lld\n",ans);
	    return 0;
	}
	printf("0");
	return 0;
}

