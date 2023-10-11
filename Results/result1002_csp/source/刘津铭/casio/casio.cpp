//Ԥ�Ƶ÷֣�100 
#include<bits/stdc++.h>
#define int long long
#define N 30000000 + 1000
using namespace std;
//1857859
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
int T, P, n;
int f[N], pr[N], tot;
signed main() {
	freopen("casio.in", "r", stdin);
	freopen("casio.out", "w", stdout);
	//scanf("%lld %lld", &T, &P);
	T = read();
	P = read();
	for(int i = 2; i <= N; i++) {
		if(f[i] == 0) pr[++tot] = i;
		for(int j = 1; j <= tot && i * pr[j] <= N && pr[j] <= P; j++) {
			f[i * pr[j]] = 1;
			if(i % pr[j] == 0) break;
		}
	}
	while(T--) {
		n = read();
		int ans = n;
		while(1) {
			if(f[ans] == 0) {
				write(ans);
				printf("\n");
				break; 
			}
			ans++;
		}
	}
	return 0;
}
