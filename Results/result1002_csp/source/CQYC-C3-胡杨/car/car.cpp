#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int& first){
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {if(c == '-') f = -1;c = getchar();}
	while(isdigit(c)){x = (x << 3) + (x << 1) + (c ^ '0');c = getchar();}
	first = x * f;
}
int m, t, n, Q;
struct node{
	int x, y;
}a[200010];
bool cmp(node q,node p){
	return q.x < p.x;
}
signed main(){
    freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
    read(m);read(t);read(n);read(Q);
    for(int i = 1 ; i <= n ; i++){
    	string s;
    	read(a[i].x);
    	cin >> s;
    	if(s[1] == 'M') a[i].y = 1;
    	else if(s[1] == 'N') a[i].y = 2;
    	else a[i].y = 3;
	}
	sort(a + 1, a + n + 1, cmp);
	a[n + 1].x = t;
	while(Q--){
		int s, d;
		read(s);
		int x = m, y = 0, z = 0;
		int sy = 0, sz = 0;
		for(int i = 1 ; i <= n ; i++){
			if(a[i].x <= s) continue;
			d = i;break;
		}
		if(a[d].x - s > m){
			printf("-1\n");
			continue;
		}
		int t = 0;
		for(int i = d + 1 ; i < n ; i++)
		    if(a[i].x - a[i - 1].x > m){
		    	//cout << a[i].x <<" "<<a[i - 1].x << endl;
		    	t = 1, i = n;
			}
		if(t == 1){
			printf("-1\n");
			continue;
		}
		x -= a[d].x - s;
		for(int i = d + 1 ; i <= n + 1 ; i++){
			if(a[i - 1].y == 1) x = m;
			else if(a[i - 1].y == 2) y = m - x;
			else z = m - x - y;
			if(a[i].x - a[i - 1].x <= x){
				x -= a[i].x - a[i - 1].x;
				continue;
			}
			else if(a[i].x - a[i - 1].x <= x + y){
				y -= a[i].x - a[i - 1].x - x;
				sy += a[i].x - a[i - 1].x - x;
				x = 0;
				continue;
			}
			else if(a[i].x - a[i - 1].x <= x + y + z){
				sy += y;
				sz += a[i].x - a[i - 1].x - x - y;
				x = y = 0;
				z -= a[i].x - a[i - 1].x - x - y;
			}
			else{
				t = 1;
				break;
			}
		}
		if(t == 1) printf("-1\n");
	    printf("%lld %lld\n", sz, sy);
	}
	return 0;
}
/*
6 18 4 4
2 SN
6 SS
4 SN
12 SS
3
4
10
2
*/
