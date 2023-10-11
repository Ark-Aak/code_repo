#include<bits/stdc++.h>
using namespace std;
const int N=3005;
inline void read(int &x){
   int f=1;x=0;char c=getchar();
   while((c<'0'||'9'<c)&&c^'-') c=getchar();
   if(c=='-') f=-1,c=getchar();
   while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
   x*=f;
}
int T,n;
char s[N];
bool all;
inline long long sub_all(){
	if(n&1) return 0;
	long long ans=0;
	for(int i=2;i<=n;i+=2)
		ans+=(i/2-1)*(n-i+1);
	return ans;
}
inline bool same(int l,int r){
	int mid=l+r>>1;
	for(int i=0;i<=mid-l;i++)
		if((s[l+i]^'?')&&(s[mid+1+i]^'?')&&(s[l+i]^s[mid+1+i]))
			return 0;
	return 1;
}
inline long long sub_20(){
	long long ans=0;
	for(int i=1;i<=n;i++)
	for(int j=i+3;j<=n;j+=2)
		for(int k=i+1;k<j;k+=2)
			if(same(i,k)&&same(k+1,j)) 
				++ans;
	return ans;
}
int main(){
	freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout);
	read(T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		all=0;
		for(int i=1;i<=n;i++)
			all&=(s[i]=='?');
		if(all) printf("%lld\n",sub_all());
		else printf("%lld\n",sub_20());
	}
	return 0;
}

