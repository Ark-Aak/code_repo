# include <bits/stdc++.h>
# define N 12000005
# define mod 998244353
using namespace std;
long long a1,b1,a2,b2;
int n,q;
long long pos[N];
int m;
int len[N],cnt;
bool num1[N],num2[N];
long long pos2[N];
int len2[N],cnt2;
bool num3[N],num4[N]; 
long long sum[N],sum2[N];
long long read()
{
	char c=getchar();
	while(!isdigit(c))
		c=getchar();
	long long ans=0;
	while(isdigit(c))
		ans=ans*10+c-'0',c=getchar();
	return ans;
}
int main()
{
	freopen("snow.in","r",stdin);
	freopen("snow.out","w",stdout);
	cin>>a1>>b1>>a2>>b2>>n;
	for(int i=0;i<a1+b1;i++)
		pos[++m]=(a2+b2)*i+a2,pos[++m]=(a2+b2)*(i+1);
	for(int i=0;i<a2+b2;i++)
		pos[++m]=(a1+b1)*i+a1,pos[++m]=(a1+b1)*(i+1);
	sort(pos+1,pos+m+1);
	m=unique(pos+1,pos+m+1)-pos-1;
	num1[0]=1,num2[0]=1;
	long long now=0;
	int op1=1,op2=1;
	for(int i=1;i<=m;i++)
	{
		len[++cnt]=pos[i]-pos[i-1];
		num1[cnt]=op1;
		num2[cnt]=op2;
		if(pos[i]%(a1+b1)==a1 || pos[i]%(a1+b1)==0)
			op1^=1;
		if(pos[i]%(a2+b2)==a2 || pos[i]%(a2+b2)==0)
			op2^=1;
		now+=num1[cnt]*len[cnt]-num2[cnt]*len[cnt];
		if(now<0)
		{
			len[cnt]+=now;
			if(!len[cnt])
				cnt--;
			len[++cnt]=-now;
			num1[cnt]=0,num2[cnt]=0;
			now=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		len2[++cnt2]=pos[i]-pos[i-1];
		num3[cnt2]=op1;
		num4[cnt2]=op2;
		if(pos[i]%(a1+b1)==a1 || pos[i]%(a1+b1)==0)
			op1^=1;
		if(pos[i]%(a2+b2)==a2 || pos[i]%(a2+b2)==0)
			op2^=1;
		now+=num3[cnt2]*len2[cnt2]-num4[cnt2]*len2[cnt2];
		if(now<0)
		{
			len2[cnt2]+=now;
			if(!len2[cnt2])
				cnt2--;
			len2[++cnt2]=-now;
			num3[cnt2]=0,num4[cnt2]=0;
			now=0;
		}
	}
	for(int i=1;i<=cnt;i++)
		sum[i]=sum[i-1]+len[i]*num2[i],pos[i]=pos[i-1]+len[i];
	for(int i=1;i<=cnt2;i++)
		sum2[i]=sum2[i-1]+len2[i]*num4[i],pos2[i]=pos2[i-1]+len2[i];
	while(n--)
	{
		long long p=read();
		long long ans=0;
		if(p<=pos[cnt])
		{
			int s=upper_bound(pos+1,pos+cnt+1,p)-pos-1;
			ans+=sum[s];
			if(num2[s+1])
				ans+=(p-pos[s]);
		}
		else
		{
			ans+=sum[cnt];
			p-=pos[cnt];
			ans+=(sum2[cnt2]*(p/pos2[cnt2]));
			p%=pos2[cnt2];
			int s=upper_bound(pos2+1,pos2+cnt2+1,p)-pos2-1;
			ans+=sum2[s];
			if(num4[s+1])
				ans+=(p-pos2[s]);
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
