#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,res;
char str[N];
void check(int a,int b)
{
	for(int i=a+2;i<=b-2;i+=2)
	{
		//a     i
		//i+1   b
		int flag=0;
		for(int j=a,k=(a+i)/2+1;j<=(a+i)/2,k<=i;j++,k++)
		{
			if(str[j]!=str[k])flag=0;
		}
		for(int j=i+1,k=(i+b+1)/2+1;j<=(i+b+1)/2,k<=b;j++,k++)
		{
			if(str[j]!=str[k])flag=0;
		}
		res+=flag;
	}	
}
void work()
{
	res=0;
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int len=4;len<=n;len+=2)
	{
		for(int i=1;i<=n;i++)
		{
			int j=i+len-1;
			check(i,j);
		}
	}
	printf("%d\n",res);
}
int main()
{
	freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout); 
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
