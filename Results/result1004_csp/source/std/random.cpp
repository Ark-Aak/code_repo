#include<bits/stdc++.h>
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
#define CL fclose(stdin),fclose(stdout)
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int out[4111],in[4111];
char s[4111];
const int M=998244353,H=M+1>>1;
int m=0;
int main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	int n=read();
	for(register int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(register int j=1;j<=n;++j)
			if(s[j]=='1')m++,out[i]++,in[j]++;
	}
	m=n*(n-1)/2-m;
	int ans=0;
	for(register int i=1;i<=n;++i)
	{
		int o=out[i],r=n-1-in[i]-out[i];
		ans=(ans+o+(long long)r*H)%M;
		ans=(ans+o*(o-1)+o*r)%M;
		ans=(ans+r*(r-1)*(long long)H%M*(long long)H)%M;
		ans=(ans+M-o)%M;
		ans=(ans+(long long)(M-r)*H)%M;
	}
	ans=(ans*(long long)H)%M;
	ans=((long long)n*(n-1)*(n-2)/6+M-ans)%M;
	for(register int i=1;i<=m;++i)ans=(ans<<1)%M;
	printf("%d\n",ans); 
	return 0;
}


