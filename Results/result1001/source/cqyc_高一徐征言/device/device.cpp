#include<bits/stdc++.h>
template<typename T> inline T read(T &num)
{
	register T x=0,f=0;
	register char ch=getchar();
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(48<=ch&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
using namespace std;
int T;
int main()
{
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
    read(T);
    while(T--)
    {
    	int k,n;
    	read(k),read(n);
    	int a=k%10,b=k/10%10,c=k/100%10;
    	if(a==b&&b==c)
    	{
    		printf("1\n");
    		continue;
		}
		if(a==b||a==c||b==c)
		{
			if(n==0) printf("1\n");
			else if(n==1) printf("7\n");
			else printf("8\n");
			continue;
		}
		if(n==0) printf("1\n");
		else if(n==1) printf("24\n");
		else printf("27\n");
	}
} 
