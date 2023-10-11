#include<bits/stdc++.h>
#define int __int128
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}
int L, x;
signed main() {
	freopen("geometry.in", "r", stdin);
	freopen("geometry.out", "w", stdout);
	L = read();
	x = read();
	if(x * 2 == L) {
		write(x * 3);
		return 0;
	}
	if(L % x == 0) {
		int n = L / x;
		write(x * 3 * (n - 1));
		return 0;
	}
	write(-1);
	return 0;
} 
