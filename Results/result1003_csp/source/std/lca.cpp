/* name: lca
 * author: 5ab
 * created at: 2023-08-19
 */
#include <iostream>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define ssz(x) (int((x).size()))

using ll = long long;
const int max_n = 5e5;

int hd[max_n], des[max_n * 2], nxt[max_n * 2], siz[max_n], e_cnt = 0, n;
ll sm[max_n], ans[max_n];

void add(int s, int t)
{
	des[e_cnt] = t;
	nxt[e_cnt] = hd[s];
	hd[s] = e_cnt++;
}

void dfs1(int id, int fa)
{
	siz[id] = 1;
	sm[id] = 0;
	for (int p = hd[id], dst; p != -1; p = nxt[p])
	{
		dst = des[p];
		if (dst != fa)
		{
			dfs1(dst, id);
			siz[id] += siz[dst];
			sm[id] -= 1ll * siz[dst] * siz[dst] * (id + 1);
			sm[id] += sm[dst];
		}
	}
	sm[id] += 1ll * siz[id] * siz[id] * (id + 1);
}

void dfs2(int id, int fa, ll tpas)
{
	ans[id] = sm[id] + tpas + 2ll * siz[id] * (n - siz[id]) * (id + 1);
	
	// cerr << id << " " << ans[id] << " " << tpas << endl;
	
	ll sms = tpas - 1ll * (n - siz[id]) * (n - siz[id]) * (id + 1);
	for (int p = hd[id], dst; p != -1; p = nxt[p])
	{
		dst = des[p];
		if (dst != fa)
		{
			sms -= 1ll * siz[dst] * siz[dst] * (id + 1);
			sms += sm[dst];
		}
	}
	for (int p = hd[id], dst; p != -1; p = nxt[p])
	{
		dst = des[p];
		if (dst != fa)
			dfs2(dst, id, sms - sm[dst] + 1ll * siz[dst] * siz[dst] * (id + 1) + 1ll * (n - siz[dst]) * (n - siz[dst]) * (id + 1));
	}
}

signed main()
{
	freopen("lca.in", "r", stdin);
	freopen("lca.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	fill(hd, hd + n, -1);
	
	for (int i = 1, x, y; i < n; i++)
	{
		cin >> x >> y, x--, y--;
		add(x, y), add(y, x);
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	dfs1(i, -1);
	// 	for (int j = 0; j < n; j++)
	// 		cerr << sm[j] << " \n"[j == n - 1];
	// }
	dfs1(0, -1);
	dfs2(0, -1, 0);
	
	for (int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i == n - 1];
	
	return 0;
}
// started coding at: 08-19 08:53:42