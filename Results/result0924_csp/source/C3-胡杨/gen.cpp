#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
const int mod = 1e9 + 7;
struct Tree{
	int to,nxt;
}tree[4000010];
int head[2000010],tot;
int n,m,sum;
map<pair<int,int>,int> mp;
int in[2000010],deg[2000010];
void add(int x,int y){
	tree[++tot].to = y;
	tree[tot].nxt = head[x];
	head[x] = tot;
}
int f(int x,int y){
	return (x ^ y) * (x | y) * (x & y) % mod;
}
signed main(){
    freopen("gen.in","r",stdin);
	freopen("gen.out","w",stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
    	int x,y;
    	cin >> x >> y;
    	in[x]++;
		in[y]++;
    	if(!mp[make_pair(x,y)] && !mp[make_pair(y,x)]){
    		add(x,y);
    		add(y,x);
    		mp[make_pair(x,y)] = 1;
    		mp[make_pair(y,x)] = 1;
    		
		}
	}
	int x;
	tot = 0;
	for(int i = 1 ; i <= n ; i++)
	    if(in[x] == 1){
	    	x = i;
	    	break;
		}
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			sum = (sum + f(in[i],in[j])) % mod;
		}
	}
	cout << sum << endl;
	return 0;
}

