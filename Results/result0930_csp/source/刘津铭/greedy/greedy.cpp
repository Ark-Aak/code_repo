#include<bits/stdc++.h>
#define int __int128
#define mod 147744151
using namespace std;
int n, k;
int f[2010][2010];
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
signed main() {
	freopen("greedy.in", "r", stdin);
	freopen("greedy.out", "w", stdout);
	n = read();
	k = read();
	if(k == 1) {
		write(n - 1);
		return 0;
	}
	if(k == 2) {
		int L = 1, R = n, mid, ans;
	    while(L <= R) {
		    mid = (L + R) / 2;
		    if(mid * (mid + 1) / 2 >= n) {
			    ans = mid;
			    R = mid - 1;
		    }
		    else {
			    L = mid + 1;
		    }
	    }
	    write(ans % mod);
	    return 0;
	}
	/*int L = 1, R = n, mid, ans;
	while(L <= R) {
		mid = (L + R) / 2;
		if(check(mid)) {
			ans = mid;
			R = mid - 1;
		}
		else {
			L = mid + 1;
		}
	}*/
	//cout << ans;
	return 0;
} 
