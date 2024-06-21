#include <bits/stdc++.h>
#define int long long
#define MAXN 310
#define p 1000000007
using namespace std;
int n;
char s[MAXN];
int vis[MAXN], len[MAXN], cnt;
int sa[MAXN], sb[MAXN];
int f[MAXN][MAXN][MAXN], g[MAXN][MAXN][MAXN];
int sum[MAXN][MAXN][MAXN];
signed main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	reverse(s + 1, s + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (vis[i])
			continue;
		if (s[i] == '0')
			return printf("0"), 0;
		cnt++;
		len[cnt] = 1;
		for (int j = i + 1; j <= n; j++)
		{
			if (vis[j])
				continue;
			if ((s[j] == '0') ^ (len[cnt] & 1))
				continue;
			len[cnt]++;
			vis[j] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
		sa[i] = sa[i - 1] + len[i] / 2, sb[i] = sb[i - 1] + (len[i] + 1) / 2;
	f[n][0][0] = 1;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(sum[n / max(1ll, i - 1) + 1], 0, sizeof(sum[n / max(1ll, i - 1) + 1]));
		for (int j = n / max(1ll, i - 1); j; j--)
		{
			memcpy(g[j], f[j], sizeof(f[j])), memset(f[j], 0, sizeof(f[j]));
			memcpy(sum[j], g[j], sizeof(sum[j]));
			for (int a = 0; a <= n; a++)
				for (int b = 0; b <= n; b++)
					sum[j][a][b] = (sum[j][a][b] + sum[j + 1][a][b]) % p;
		}
		for (int j = 1; j <= n / i; j++)
			for (int a = j / 2; a <= sa[i]; a++)
				for (int b = (j + 1) / 2; b <= sb[i]; b++)
					f[j][a][b] = sum[j][a - j / 2][b - (j + 1) / 2];
		if (i < cnt)
			continue;
		for (int j = 1; j <= n / i; j++)
			ans = (ans + f[j][sa[i]][sb[i]]) % p;
	}
	printf("%lld", ans);
	return 0;
}
