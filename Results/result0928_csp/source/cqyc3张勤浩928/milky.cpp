#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=1e6+7;
unsigned int n,q,a[Maxn],f[Maxn][5][5]; 
inline int gety(char c){
	if(c=='m') return 0;
	if(c=='i') return 1;
	if(c=='l') return 2;
	if(c=='k') return 3;
	if(c=='y') return 4;
	return -1;
}
inline unsigned int solve(int L,int R,int l,int r){
	if(L<=0||R>n) return 0;
	if(l==r){
		return f[R][l][r]-f[L-1][l][r];
	}
	unsigned int res=0;
	for(int i=0;i<r-l;i++){
		res+=solve(1,L-1,l,l+i)*solve(L,R,l+i+1,r);
	}
	return f[R][l][r]-f[L-1][l][r]-res;
}
char s[Maxn];
int main(){
	freopen("milky.in","r",stdin);
	freopen("milky.out","w",stdout);
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%u",&q);
	for(int i=1;i<=n;i++){
		for(int j=0;j<5;j++)
			for(int k=j;k<5;k++)
				f[i][j][k]=f[i-1][j][k];
		for(int j=0;j<gety(s[i]);j++)
			f[i][j][gety(s[i])]+=f[i-1][j][gety(s[i])-1];
		f[i][gety(s[i])][gety(s[i])]++;
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%u\n",solve(l,r,0,4));
	}	
	return 0;
}
/*
milkymilky
5
1 5
1 6
5 9
4 4
1 10
*/
