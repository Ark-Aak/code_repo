#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline int read(){
	int s=0,w=1;char c=getchar();
	while(c<48||c>57) {if(c=='-') w=-1;c=getchar();}
	while(c>=48&&c<=57) s=(s<<1)+(s<<3)+c-48,c=getchar();
	return s*w;
}

inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}

int main() {
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	int n;
	cin>>n;
	time(0);
	cout<<rand()%n+1<<" "<<rand()%n+1<<" ";
	for(int i=3;i<=n;i++)cout<<n/2<<" ";
	return 0;
}


