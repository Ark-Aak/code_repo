#include <bits/stdc++.h>
using namespace std;
const int N = 9e5 + 5;
int n, m, c[3][N], p;
char s[N], pi;

bool f1(char t)
{
    int x = (t - 'A' + 1) % 3, y = (t - 'A' + 2) % 3;
    for(int l = 1, r = 1; l <= m; l++)
    {
        if(r < l) r = l;
        while((c[x][r]-c[x][l-1] < c[x][m]-n || c[y][r]-c[y][l-1] < c[y][m]-n)
              && r <= m) r++;
        if(c[x][r]-c[x][l-1] == c[x][m]-n && c[y][r]-c[y][l-1] == c[y][m]-n)
            return printf("1\n%d %d %c", l, r, t), 1;
    }
    return 0;
}

void f2()
{
    puts("2");
    int x = (pi - 'A' + 1) % 3, y = (pi - 'A' + 2) % 3;
    char X = x + 'A', Y = y + 'A';
    printf("%d %d %c\n", p+1, p+n-c[x][p], X);
    printf("%d %d %c\n", p+n-c[x][p]+1, m, Y);
}

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    scanf("%d%s", &n, s + 1); m = 3 * n;

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < 3; j++) c[j][i] = c[j][i-1];
        c[s[i]-'A'][i] = c[s[i]-'A'][i-1] + 1;
        if(!p && c[s[i]-'A'][i] == n) p = i, pi = s[i];
    }

    if(c[0][m] == c[1][m] && c[0][m] == n) return puts("0"), 0;

    if(f1('A') || f1('B') || f1('C')) return cerr<<"ok",0;

    f2();

    return 0;
}

