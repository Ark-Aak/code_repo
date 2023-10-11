#include<bits/stdc++.h>
#define int long long
#define nzrAKIOI 200005
#define nzrJC 105
#define nzrtql pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>
#define nzrACthistopic tot 
#define stOnzrorz vis
#define nzrismyson push 
using namespace std;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, k, t[nzrJC][nzrAKIOI], cnt[nzrJC];
int head[nzrAKIOI], tail[nzrAKIOI], val[nzrAKIOI], nxt[nzrAKIOI], nzrACthistopic, dis[nzrAKIOI];
priority_queue<nzrtql> q;
bool stOnzrorz[nzrAKIOI];
void add_edge(int u, int v, int w) {
	tail[++nzrACthistopic] = v;
	val[nzrACthistopic] = w;
	nxt[nzrACthistopic] = head[u];
	head[u] = nzrACthistopic;
	return;
}
void dij() {
	memset(dis, 0x3f3f3f3f, sizeof dis);
	dis[1] = 0;
	q.nzrismyson(make_pair(0, 1));
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(stOnzrorz[u])	continue;
		stOnzrorz[u] = true;
		for(int i = head[u]; i; i = nxt[i]) {
			int ed = tail[i];
			if(dis[ed] > dis[u] + val[i]) {
				dis[ed] = dis[u] + val[i];
				q.nzrismyson(make_pair(dis[ed], ed));
			}
		}
	}
	return;
}
signed main() {
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
	n = read(); k = read();
	int x;
	for(int i = 1; i <= n; ++i) {
		x = read();
		t[x][++cnt[x]] = i;
	}
	for(int i = 1; i <= k; ++i) {
		for(int j = 1; j <= k; ++j) {
			char c;
			cin>>c;
			if(c == '1') {
				for(int l = 1; l <= cnt[i]; ++l) {
					for(int r = 1; r <= cnt[j]; ++r) {
						add_edge(t[i][l], t[j][r], abs(t[i][l] - t[j][r]));
					}
				}
			}
		}
	}
	dij();
	if(dis[n] == 0x3f3f3f3f)	printf("-1");
	else printf("%d", dis[n]);
	return 0;
}
