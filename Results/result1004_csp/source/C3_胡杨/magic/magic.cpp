#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
int n;
int id[200010];
vector<int> a[200010];
struct node{
	int c, p1, p2, p3, p4;
}p[200010];
int vis[200010],col[200010],color;
bool cmp(node x, node y){
	return x.c < y.c;
}
map<pair<int,int>,int> mp;
int vis1[200010];
void dfs(int x, int co){
	//cout << x <<endl;
	vis[x] = 1;
	col[x] = co;
	for(int i = 0 ; i < a[x].size() ; i++){
		int to = a[x][i];
		if(!vis[to]) dfs(to, co);
	}
}
signed main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	read(n);
	//cin >> n;
	for(int i = 1 ; i <= n ; i++){
		int p1, p2, p3, p4, c1;
		read(c1);read(p1);read(p2);read(p3);read(p4);
		//cout <<c1<<" "<<p1 <<" "<<p2<<" "<<p3<<" "<<p4<<endl;
		//cin >>c1>> p1 >> p2 >> p3 >> p4;
		p[i].p1 = p1; p[i].p2 = p2; p[i].p3 = p3; p[i].p4 = p4;
		//cout << p[i].p1<<" "<<p[i].p2<<" "<<p[i].p3<<" "<<p[i].p4<<endl;
		a[p1].push_back(p2);
		a[p3].push_back(p4);
		a[p2].push_back(p1);
		a[p4].push_back(p3);
		//id[p1] = id[p2] = id[p3] = id[p4] = i;
		p[i].c = c1;
	}
	for(int i = 1 ; i <= n ; i++){
		if(!vis[p[i].p1]) dfs(p[i].p1,++color);//,cout << endl;
		if(!vis[p[i].p3]) dfs(p[i].p3,++color);//,cout << endl;
	}
	sort(p + 1, p + n + 1, cmp);
	int tot = 0, s = 0;
	for(int i = 1 ; i <= n ; i++){
		if(tot == color - 1) break;
		int x = col[p[i].p1], y = col[p[i].p3], l = col[p[i].p2], r = col[p[i].p4];
		//cout << x<<" "<<l<<" "<<y<<" "<<r<<endl;
		if(!mp[make_pair(x,y)] && !mp[make_pair(y,x)] && x != y){//&& !mp[make_pair(l,r)] && !mp[make_pair(r,l)]) {
			vis1[y] = vis[x] = 1;
			mp[make_pair(x,y)] = 1;
			mp[make_pair(y,x)] = 1;
//			mp[make_pair(l,r)] = 1;
//			mp[make_pair(r,l)] = 1;
		    //cout << x <<" "<<y<<endl; 
			s += p[i].c;
			tot++;
		}
		//cout << s << endl;
	}
	//for(int i = 1 ; i <= n ; i++) cout << vis[i]<<" ";
	printf("%lld\n",s);
	return 0;
}
/*
6
9 3 9 1 2
5 5 6 10 12
8 8 11 4 7
6 10 8 2 6
7 12 11 4 3
6 7 9 1 5
*/
