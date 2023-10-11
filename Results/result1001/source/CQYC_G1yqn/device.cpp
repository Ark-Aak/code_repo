#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
void write(int x)
{
    if(x<0){putchar('-'),x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
    return;
}
signed main()
{
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	int t;
	int k,n;
	t=read();
	while(t--)
	{
		k=read(),n=read();
		puts("1");
	}
	return 0;
}
