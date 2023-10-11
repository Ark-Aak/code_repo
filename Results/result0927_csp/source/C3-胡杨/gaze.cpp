#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	char ch = getchar();
	int f = 1;
	while (!isdigit(ch) && ch ^ '-') ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
	x *= f;
}
int n,m;
int a[200010];
int t[200010];
struct node {
	int x,id,ans;
} b[200010],Q[200010];
bool cmp(node q,node p) {
	return q.x < p.x;
}
bool cmp1(node q,node p){
	return q.id < p.id;
}
signed main() {
    freopen("gaze.in","r",stdin);
	freopen("gaze.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	//read(n);read(m);
	for(int i = 1 ; i <= n ; i++) scanf("%lld",&a[i]);
	for(int i = 1 ; i <= n ; i++)
		b[i].x = a[i],b[i].id = i;
	sort(b + 1, b + n + 1, cmp);
	a[0] = -1;
	if(n <= 2000 && m <= 2000) {
		while(m--) {
			int t,x,y;
			read(t);
			if(t == 1) {
				read(x);
				int s = 0;
				for(int i = 1 ; i <= n ; i++)
					if(a[i] >= x && a[i - 1] < x)
						s ++;
				printf("%lld\n",s);
			} else {
				read(x);
				read(y);
				a[x] = y;
			}
		}
		return 0;
	}
    for(int i = 1 ; i <= m ; i++){
    	int aa;
    	scanf("%lld",&aa);
    	scanf("%lld",&Q[i].x);
    	//cout << aa << endl;
    	Q[i].id = i;
	}
	sort(Q + 1, Q + m + 1, cmp);
	int x = 1,s = 0;
	t[0] = t[n + 1] = 1;
	for(int i = 1 ; i <= m ; i++){
//		for(int j = 1; j<= n ; j++) cout << t[j]<<" ";
//		cout << endl;
		while(b[x].x < Q[i].x && x <= n){
			//cout << b[x].x <<" "<<Q[i].x <<" "<<b[x].id<<endl;
			if(!t[b[x].id + 1] && !t[b[x].id - 1] && !t[b[x].id])
				s++;
			if(t[b[x].id + 1] && t[b[x].id - 1])
			    s--;
			//cout << t[b[x].id]<<" ";
			t[b[x].id] = 1;
			//cout << t[b[x].id]<<endl;
			x++;
		}
		//cout << endl;
		Q[i].ans = s + 1;
	}
	sort(Q + 1, Q + m + 1, cmp1);
	//cout << m << endl;
	//cout << endl;
	for(int i = 1 ; i <= m ; i++)
	    printf("%lld\n",Q[i].ans);
	return 0;
}
/*
15 8
1 3 8 5 6
4 5 7 2 1
3 6 9 4 5
1 3
1 3
1 5
1 6
1 7
1 8
1 8
1 9

2 2 4 4 3 2 2 1
*/
