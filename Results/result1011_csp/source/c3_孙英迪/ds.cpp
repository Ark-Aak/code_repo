#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <tuple>
#include <vector>
#include <bitset>
#define pii pair <int, int>
using namespace std;

#ifdef ONLINE_JUDGE

#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 23], *p1 = buf, *p2 = buf, ubuf[1 << 23], *u = ubuf;

#endif

int read() {
	int p = 0, flg = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') flg = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		p = p * 10 + c - '0';
		c = getchar();
	}
	return p * flg;
}
void write(int x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar(x % 10 + '0');
}
#define fi first
#define se second
const int N = 1e6 + 5;
array <pii, N> isl;

namespace Subtask1 {
array <int, N> px, py;
array <array <int, 1005>, 1005> mp, kp;

void main(int n, int q) {
	for (int i = 1; i <= n; i++) {
		px[isl[i].fi] = 1, py[isl[i].se] = 1;
		mp[isl[i].fi][isl[i].se] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			kp[i][j] = kp[i - 1][j] + kp[i][j - 1] - kp[i - 1][j - 1] + mp[i][j];
	for (int i = 1; i <= n; i++)
		px[i] += px[i - 1], py[i] += py[i - 1];
	while (q--) {
		int x_1 = read(), y_1 = read(), x_2 = read(), y_2 = read();
		int ans = 0;
		for (int i = x_2; i <= x_1; i++) {
			for (int j = y_2; j <= y_1; j++) {
				if (!mp[i][j]) continue;
				if (kp[x_1][y_1] - kp[x_1][j] - kp[i][y_1] + kp[i][j] == 0)
					ans++;
			}
		}
		write(ans), puts("");
	}
}

/*
n ^ 3做法
*/

}
array <tuple <int, int, int, int>, N> qrl;

namespace Subtask2 {

array <int, 4 * N> que;

bool cmp(pii a, pii b) {
	if (a.fi == b.fi) return a.se > b.se;
	return a.fi < b.fi;
}

void main(int n, int q) {
	/* puts("@"); */
	sort(isl.begin() + 1, isl.begin() + 1 + n, cmp);
	for (int i = 1; i <= q; i++) {
		int top = 0;
		int U = get <0>(qrl[i]), R = get <1>(qrl[i]),
			D = get <2>(qrl[i]), L = get <3>(qrl[i]);
		for (int j = 1; j <= n; j++) {
			if (D <= isl[j].fi && isl[j].fi <= U &&
				L <= isl[j].se && isl[j].se <= R) {
				while (top && isl[j].se > isl[que[top]].se) top--;
				top++;
				que[top] = j;
			}
		}
		write(top), puts("");
	}
}

/*
B 性质的 n ^ 2 做法
*/

}


namespace Subtask_B {

array <int, 4 * N> que;
array <int, N> ans;
array <tuple <int, int, int>, N> qrl;

bool cmp(pii a, pii b) {
	if (a.fi == b.fi) return a.se > b.se;
	return a.fi < b.fi;
}


void main(int n, int q) {
	/* puts("@"); */
	sort(isl.begin() + 1, isl.begin() + 1 + n, cmp);
	for (int i = 1; i <= q; i++) {
		get <0>(qrl[i]) = get <0>(::qrl[i]), get <1>(qrl[i]) = get <3>(::qrl[i]);
		get <2>(qrl[i]) = i;
	}
	sort(qrl.begin() + 1, qrl.begin() + 1 + q);
	int top = 0, idx = 0;
	for (int i = 1; i <= n; i++) {
		while (get <0>(qrl[idx + 1]) < isl[i].fi && idx < q) {
			idx++;
			ans[get <2>(qrl[idx])] = top - (lower_bound(que.begin() + 1, que.begin() + 1 + top, get <1>(qrl[idx])) - que.begin() - 1);
		}
		while (top && isl[i].se > isl[que[top]].se) top--;
		top++;
		que[top] = i;

	}
	for (int i = 1; i <= q; i++)
		write(ans[i]), puts("");
}

}

/*
namespace Subtask_C {

int lowbit(int x) {
	return x & -x;
}
array <int, N> edge;
void modify(int x, int y, int n) {
	while (x <= n) {
		edge[x] += y;
		x += lowbit(x);
	}
	return;
}
int query(int x) {
	int ans = 0;
	while (x) {
		ans += edge[x];
		x -= lowbit(x);
	}
	return ans;
}
vector <tuple <int, int, int, int> > qrl;
void main(int n, int q) {
	for (int i = 1; i <= q; i++) {
		qrl.push_back(make_tuple(get <0>(::qrl[i]), get <1>(::qrl[i]), i, 1));
		qrl.push_back(make_tuple(get <2>(::qrl[i]) - 1, get <3>(::qrl[i]), i, -1));
	}
}

}
*/

array <int, N> vx, vy;
int main() {
	freopen("ds.in", "r", stdin);
	freopen("ds.out", "w", stdout);
	int n = read(), q = read();
	for (int i = 1; i <= n; i++)
		isl[i].fi = read(), vx[isl[i].fi]++;
	for (int i = 1; i <= n; i++)
		isl[i].se = read(), vy[isl[i].se]++;
	/*
	bool flg = false;
	for (int i = 1; i <= n; i++) {
		if (vx[i] > 1 || vy[i] > 1)
			flg = 1;
	}
	*/


	if (n <= 500) {
		Subtask1::main(n, q);
		return 0;
	}
	bool _flg = 0;
	for (int i = 1; i <= q; i++) {
		get <0>(qrl[i]) = read(), get <1>(qrl[i]) = read();
		get <2>(qrl[i]) = read(), get <3>(qrl[i]) = read();
		if (get <1>(qrl[i]) != n || get <2>(qrl[i]) != 1) _flg = 1;
	}
	/* if (!flg) Subtask_C::main(n, q); */
	if (_flg) Subtask2::main(n, q);
	else Subtask_B::main(n, q);
	return 0;
}
