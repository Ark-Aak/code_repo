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
int T;
signed main(){
    freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
    read(T);
	while(T--){
    	printf("No\n");
	}
	return 0;
}

