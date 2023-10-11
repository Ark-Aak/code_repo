#include <bits/stdc++.h>
#define mx 1000005
using namespace std;
int n,m;
int u,r,d,l,ans;
int ton[mx];
int x[mx],y[mx],id[mx];
int qc,qcx[mx],tot = 0;
bool cmp(int a,int b){
	return x[a]==x[b]?y[a]<y[b]:x[a]<x[b];
}
vector<int> v[mx];
int main()
{
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; i++)
		scanf("%d",&x[i]),id[i] = i;
	for (int i = 1; i <= n; i++)
		scanf("%d",&y[i]);
	sort(id+1,id+n+1,cmp);
	for (int i = 1; i <= n; i++)
	{
		v[x[id[i]]].push_back(y[id[i]]);
		ton[x[id[i]]]++;
		if (ton[x[id[i]]] == 1) qcx[++tot] = x[id[i]];
	}
	for (int i = 1; i <= m; i++)
	{
		ans = 0;
		scanf("%d %d %d %d",&u,&r,&d,&l);
		int ll = 1,rr = tot,ret;
		while (ll <= rr)
		{
			int mid = (ll+rr) >> 1;
			if (qcx[mid] <= u) ret = mid,ll = mid+1;
			else rr = mid-1;
		}
		for (int j = v[qcx[ret]].size()-1; j >= 0; j--)
			if (v[qcx[ret]][j] <= r){
				qc = v[qcx[ret]][j];
				break;
			}
		if (qc < l){
			printf("0\n");
			continue;
		}
		ans += ton[qcx[ret]];
		for (int j = 1; j <= n; j++){
			if (x[id[j]] > qcx[ret]) break;
			if (x[id[j]] >= d && x[id[j]] < qcx[ret] && y[id[j]] >= qc && y[id[j]] <= r)
				ans++;
			else if (x[id[j]]==qcx[ret] && ((y[id[j]]<l)||(y[id[j]]>r)))
				ans--;			
		}
		printf("%d\n",ans);
	}
	return 0;
}

