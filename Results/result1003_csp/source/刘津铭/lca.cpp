#include<bits/stdc++.h>
#define int long long
#define N 1000005
using namespace std;
int n, a[N], siz[N];
vector<int>p[N];
void dfs(int x, int fa) {
	//cout << "e";
	siz[x] = 1;
	for(int i = 0; i < p[x].size(); i++) {
		int y = p[x][i];
		if(y == fa) continue;
		dfs(y, x);
		siz[x] += siz[y];
	}
	
	int sum = 0;
	for(int i = 0; i < p[x].size(); i++) {
		int y = p[x][i];
		if(y == fa) continue;
		sum += siz[y] * (siz[x] - 1 - siz[y]);
	}
	sum *= x;
	a[1] += sum;
	a[x] -= sum;
	sum = (siz[x] - 1) * (n - siz[x]);
	for(int i = 0; i < p[x].size(); i++) {
		int y = p[x][i];
		if(y == fa) continue;
		sum += siz[y] * (n - siz[y] - 1);
	}
	for(int i = 0; i < p[x].size(); i++) {
		int y = p[x][i];
		if(y == fa) continue;
		a[y] += (sum - siz[y] * (n - siz[y] - 1) * 2) * x;
	}
	
	sum *= x;
	a[x] += sum;
	for(int i = 0; i < p[x].size(); i++) {
		int y = p[x][i];
		if(y == fa) continue;
		a[y] -= sum;  
	}
	
	sum = (n - siz[x]) * x * 2;
	a[x] += sum;

	for(int i = 0; i < p[x].size(); i++) {
		int y = p[x][i];
		if(y == fa) continue;
		a[1] += siz[y] * x * 2;
		a[y] -= siz[y] * x * 2;
	} 
}

void dfs2(int x, int fa) {
	a[x] += a[fa];
	for(int i = 0; i < p[x].size(); i++) {
		int y = p[x][i];
		if(y == fa) continue;
		dfs2(y, x);
	}
}
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
	freopen("lca.in", "r", stdin);
	freopen("lca.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n - 1; i++) {
		int u, v;
		u = read();
		v = read();
		p[u].push_back(v);
		p[v].push_back(u);
	} 
	a[1] += (1 + n) * n / 2; 
	//cout << "e"; 
	dfs(1, 0);
	dfs2(1, 0);
	for(int i = 1; i <= n; i++) {
		write(a[i]);
		printf(" ");
	}
	return 0;
} 
