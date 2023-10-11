#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F(i,a,b) for(int i=a;i<=b;i++)

const int N = 2e5 + 5;

int f[5005][5005], n, ans,mp[5005];

map<int, int> ma;

vector<int> v;

struct node {
	int x, y, c;
} a[N];

inline int read();

signed main() {
	freopen("imp.in","r",stdin);
	freopen("imp.out","w",stdout);
	n=read();
	for (int i = 1; i <= n; i++) {
		a[i].x=read(),a[i].y=read(),a[i].c=read();
		if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
		if (!ma[a[i].x]) ma[a[i].x] = 1, v.push_back(a[i].x);
		if (!ma[a[i].y]) ma[a[i].y] = 1, v.push_back(a[i].y);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		ma[v[i]] = i + 1;
		mp[i + 1] = v[i];
	}

	for (int i = 1; i <= n; i++) {
		f[ma[a[i].x]][ma[a[i].y]] += a[i].c;
	}
	int len = v.size();
	for (int i = 1; i <= len; i++)
		for (int j = 1; j <= len; j++)
			f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
	for (int i = 1; i <= len; i++) {
		for (int j = i + 1; j <= len; j++) {
			if ((f[j][j] - f[i - 1][j] - f[j][i - 1] + f[i - 1][i - 1]) - mp[j] + mp[i] > ans) {
				ans = max(ans, ((f[j][j] - f[i - 1][j] - f[j][i - 1] + f[i - 1][i - 1]) - mp[j] + mp[i]));
			}

		}
	}
	cout << ans << endl;
	return 0;
}

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
