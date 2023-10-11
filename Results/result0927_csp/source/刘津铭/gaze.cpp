#include<bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;
int n, Q;
int h[N], ans[N];
int opt[N], a[N], b[N];
int XX[N];
struct node{
	int x, v;
}p[N];
int sum[N];
int tot = 0;
bool cmp1(node X, node Y) {
	return X.x < Y.x;
} 
bool cmp2(node X, node Y) {
	return X.v < Y.v;
} 
int c[N * 4];
int u[N], g;
int tag[N * 4];
void maketag(int u, int L, int R, int x) {
	c[u] += x * (R - L + 1);
	tag[u] += x;
}
void pushdown(int u, int L, int R) {
	int mid = (L + R) / 2;
	maketag(u * 2, L, mid, tag[u]);
	maketag(u * 2 + 1, mid + 1, R, tag[u]);
	tag[u] = 0;
}
void pushup(int u) {
	c[u] = c[u * 2] + c[u * 2 + 1];
}
void update(int u, int L, int R, int l, int r, int x) {
	if(l <= L && R <= r) {
		maketag(u, L, R, x);
		return;
	}
	if(r < L || R < l) return;
	int mid = (L + R) / 2;
	pushdown(u, L, R);
	update(u * 2, L, mid, l, r, x);
	update(u * 2 + 1, mid + 1, R, l, r, x);
	pushup(u);
}
int query(int u, int L, int R, int l, int r) {
	if(l <= L && R <= r) return c[u];
    if(r < L || R < l) return 0;
    int mid = (L + R) / 2;
    pushdown(u, L, R);
    return query(u * 2, L, mid, l, r) + query(u * 2 + 1, mid + 1, R, l, r);
}
void add(int X, int Y, int num) {
	if(X > Y) return;
    int l = -1, mid, L = 1, R = tot;	//找第一个大于等于X的数 
    while(L <= R) {
    	mid = (L + R) / 2;
    	if(u[mid] >= X) {
    		l = mid;
    		R = mid - 1;
		}
		else L = mid + 1;
	} 
	int r = -1;
	L = 1, R = tot;	//找第最后一个小于等于Y的数 
    while(L <= R) {
    	mid = (L + R) / 2;
    	if(u[mid] <= Y) {
    		r = mid;
    		L = mid + 1;
		}
		else R = mid - 1;
	}
	if(l != -1 && r != -1) {
		//cout << X << " " << Y << "->" << l << " " << r << endl;
		update(1, 1, tot, l, r, num);
	}
}
int Min(int A, int B) {
	if(A < B) return A;
	return B;
}
map<int, int>gg;
signed main() {
	freopen("gaze.in", "r", stdin);
	freopen("gaze.out", "w", stdout);
	scanf("%lld %lld", &n, &Q);
	for(int i = 1; i <= n; i++) scanf("%lld", &h[i]);
	for(int i = 1; i <= Q; i++) {
		scanf("%lld", &opt[i]);
		if(opt[i] == 1) {
			int xx;
			cin >> xx;
			XX[i] = xx;
			p[++tot].x = xx;
			p[tot].v = i;
		}
		else cin >> a[i] >> b[i];
	}
	sort(p + 1, p + tot + 1, cmp1);
	
	for(int i = 1; i <= tot; i++) {
		//gg[]
		if(i == 1 || p[i].x != p[i - 1].x) {
			u[++g] = p[i].x;
			gg[p[i].x] = g;
			
			//ljm[p[i].v] = g;
		} 
	}
	//cout << "e" << g << endl;
	tot = g;
	//for(int i = 1; i <= tot; i++) cout << "g" << u[i] << endl;
	for(int i = 1; i <= n; i++) {
		add(h[i + 1] + 1, h[i], 1);
		//cout << "g" << h[i + 1] + 1 << " " << h[i] << endl;
	}
        /*for(int j = h[i]; j >= h[i + 1] + 1; j--) {

        	ans[j]++;
		} */
	//cout << "I will AC it" << query(1, 1, tot, 2, 2) << " "<< XX[1] << endl;
	//cout << "e" << query(1, 1, tot, 1, 1) << endl; 
	for(int i = 1; i <= Q; i++) {
		if(opt[i] == 1) {
			//cout << "e" << ljm[i] << endl;
		    cout << query(1, 1, tot, gg[XX[i]], gg[XX[i]]) << endl;
		}
		else {
			if(h[a[i]] == b[i]) continue;
			if(h[a[i]] > h[a[i] + 1]) {
				if(h[a[i]] > b[i]) add(max(b[i] + 1, h[a[i] + 1]), h[a[i]], -1);   //for(int i = h[a]; i >= b + 1; i--) ans[i]--;
				else add(h[a[i]] + 1, b[i], 1);  //for(int i = b; i >= h[a] + 1; i--) ans[i]++;
			}
			//else add(h[a[i] + 1] + 1, b[i], 1);
			if(a[i] > 1) {
				if(h[a[i] - 1] <= h[a[i]]) {
					//cout << "e" << query(1, 1, tot, 1, 1) << endl; 
					add(b[i] + 1, h[a[i] - 1], 1);
					//cout << "e" << query(1, 1, tot, 1, 1) << endl; 
					//for(int i = h[a - 1]; i >= b + 1; i--) ans[i]++;
				}
				if(h[a[i] - 1] > h[a[i]]) {
					if(h[a[i]] > b[i]) { //中间的数变多了 
					    add(b[i] + 1, h[a[i]], 1);
						//for(int i = h[a]; i >= b + 1; i--) ans[i]++;
					}
					else {
						add(h[a[i]] + 1, min(b[i], h[a[i] - 1]), -1);
						//for(int i = min(b, h[a - 1]); i >= h[a] + 1; i--) ans[i]--;
					}
				}
			}
			h[a[i]] = b[i];
		}
	}
	return 0;
}
/*
5 4
8
6
3
5
4
1 5
2 4 1
1 5
1 3
*/

/*
20 6
10 55 74 55 99 45 23 55 90 76 34 56 11 33 25 66 88 55 14 55
1 44
1 24
2 17 63
1 56
2 5 78
1 49
  
 */
