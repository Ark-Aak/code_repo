#include<bits/stdc++.h>
using namespace std;
#define For(i, j, k) for ( int i = (j) ; i <= (k) ; i++ )
struct point
{
	int x, y, id;
	bool operator<(const point &z)const { return x != z.x ? x < z.x : y != z.y ? y < z.y : id < z.id; }
}	a[2000009];
int n, q, num[2000009], l, lst, cx, cy, nwx, idy, ans[1000009], c[2000009]; bool ko[2000009];
void add(int x) { for ( ; x <= l ; x += x & -x ) c[x]++; }
int query(int x) { int y = 0; for ( ; x ; x ^= x & -x ) y += c[x]; return y; }
int main()
{
	freopen("act.in", "r", stdin), freopen("act.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> q;
	For(i, 1, n) cin >> a[i].x;
	For(i, 1, n) cin >> a[i].y, num[++l] = a[i].y;
	For(i, 1, q) cin >> a[i + n].x >> a[i + n].y, a[i + n].id = i, num[++l] = a[i + n].y;
	sort(a + 1, a + n + q + 1), sort(num + 1, num + l + 1), l = unique(num + 1, num + l + 1) - num - 1;
	For(i, 1, n + q)
	{
		idy = lower_bound(num + 1, num + l + 1, a[i].y) - num, cy = query(idy);
		if ( a[i].id )
		{
			if ( a[i].x == a[lst].x && a[i].y == a[lst].y ) { ans[a[i].id] = -1; continue; }
			if ( a[i].x == nwx || ko[idy] ) { ans[a[i].id] = 1; continue; }
			ans[a[i].id] = a[i].x - cx == a[i].y - cy ? -1 : 1;
		}
		else
		{
			lst = i;
			if ( a[i].x - cx < a[i].y - cy && !ko[idy] ) ko[idy] = true, add(idy);
			if ( a[i].x - cx > a[i].y - cy && a[i].x != nwx ) nwx = a[i].x, cx++;
		}
	}
	For(i, 1, q) assert(ans[i]), cout << ( ans[i] > 0 ? "Alice\n" : "Bob\n" );
	return 0;
}