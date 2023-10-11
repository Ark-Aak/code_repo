#include<bits/stdc++.h>
using namespace std;
void read(int& first){
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {if(c == '-') f = -1;c = getchar();}
	while(isdigit(c)){x = (x << 3) + (x << 1) + (c ^ '0');c = getchar();}
	first = x * f;
}
const int maxn = 40000000;
int T,P,S;
int zs[5000010],tot;
int bs[50],cnt;
bitset<maxn> vis;
int half1(int l, int r, int n){
	while(l <= r){
		int mid = (l + r) >> 1;
		if(zs[mid] < n) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}
int zys(int x){
	int i = 1;
	while(zs[i] <= P){
		if(!(x % zs[i])){
			if(zs[i] <= P) return 0;
			if(zs[i] > P) return 1;
		}
		i++;
	}
	return 1;
}
int Max;
int main(){
    freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
    for(int i = 2 ; i <= maxn ; i++){
    	if(vis[i]) continue;
    	zs[++tot] = i;
    	vis[i] = 1;
    	for(int j = i + i ; j <= maxn ; j += i) vis[j] = 1;
	}
	read(T);
	read(P);
	while(T--){
		int x;
		read(x);
		int ans1 = zs[half1(1, tot, x)];
		int ans2 = 1e9;
		if(ans1 > P){
			for(int i = x ; i <= ans1 ; i++)
			    if(zys(i)) ans2 = i, i = ans1 + 1;
		}
	    printf("%d\n",min(ans1, ans2));
	}
	return 0;
}

