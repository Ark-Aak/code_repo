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
int solve(int p, int q, int r, int a, int b, int c) 
{
    int cnt=0;
    if(p!=a) cnt++;
    if(q!=b) cnt++;
    if(r!=c) cnt++;

    if (p!=a && q!=b) 
	{
        int diff1=a-p;
        int diff2=b-q;
        if (diff1==diff2||p+diff1==a&&q+diff1==b||p*diff1==a&&q*diff1==b) 
		{
            cnt--;
        }
    }
    if (q != b && r != c) 
	{
        int diff1 = b - q;
        int diff2 = c - r;
        if (diff1 == diff2 || q + diff1 == b && r + diff1 == c || q * diff1 == b && r * diff1 == c) 
		{
            cnt--;
        }
    }

    if (p != a && r != c) {
        int diff1 = a - p;
        int diff2 = c - r;
        if (diff1 == diff2 || p + diff1 == a && r + diff1==c||p*diff1==a&&r*diff1== c) 
		{
            cnt--;
        }
    }
    return cnt;
}
int main() 
{
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	int t;
	t=read();
    while (t--) 
	{
        int p, q, r, a, b, c;
        p=read(),q=read(),r=read();
        a=read(),b=read(),c=read();
        write(solve(p, q, r, a, b, c));
        putchar('\n');
    }
    return 0;
}

