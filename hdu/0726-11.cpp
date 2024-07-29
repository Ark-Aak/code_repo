#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll
#define double long double

const int MAXN = 500005;
int n, x[MAXN], y[MAXN], w1[MAXN], w2[MAXN];
int ans = 0, minArea = 9e18;

double Rand() { return (double)rand() / RAND_MAX; }
mt19937 rnd(time(0));

int calc(int tim) {
	if (tim > 2e9) return 1e18;
	if (tim < 0) return 1e18;
	int minx = 1e18, maxx = -1e18, miny = 1e18, maxy = -1e18;
	rep (i, 1, n) {
		int posx = x[i] + w1[i] * tim;
		int posy = y[i] + w2[i] * tim;
		minx = min(minx, posx);
		miny = min(miny, posy);
		maxx = max(maxx, posx);
		maxy = max(maxy, posy);
	}
	int area = (maxx - minx) * 2 + (maxy - miny) * 2;
	if (area < minArea) minArea = area, ans = tim;
	return area;
}

void simulateAnneal() {
	double t = 1000000000;
	int now = ans;
	while (t > 0.01) {
		int nxt = now + t * (Rand() * 2 - 1);
		double delta = calc(nxt) - calc(now);
		if (exp(-delta / t) > Rand()) now = nxt;
		t *= 0.97;
	}
}

vector <pii> v[5];

signed main() {
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	rep (i, 1, n) {
		char c;
		cin >> x[i] >> y[i] >> c;
		if (c == 'E') v[1].emplace_back(x[i], y[i]);
		if (c == 'W') v[2].emplace_back(x[i], y[i]);
		if (c == 'N') v[3].emplace_back(x[i], y[i]);
		if (c == 'S') v[4].emplace_back(x[i], y[i]);
		if (c == 'E') w1[i] = 1;
		if (c == 'W') w1[i] = -1;
		if (c == 'N') w2[i] = 1;
		if (c == 'S') w2[i] = -1;
	}
	sort(v[1].begin(), v[1].end(), [](pii a, pii b) { return a.ec < b.ec; });
	sort(v[2].begin(), v[2].end(), [](pii a, pii b) { return a.ec < b.ec; });
	sort(v[3].begin(), v[3].end(), [](pii a, pii b) { return a.fb < b.fb; });
	sort(v[4].begin(), v[4].end(), [](pii a, pii b) { return a.fb < b.fb; });
	n = 0;
	if (v[1].size()) {
		auto a = v[1].front(), b = v[1].back();
		n++;
		w1[n] = 1, w2[n] = 0;
		x[n] = a.ec, y[n] = a.fb;
		n++;
		w1[n] = 1, w2[n] = 0;
		x[n] = b.ec, y[n] = b.fb;
	}
	if (v[2].size()) {
		auto a = v[2].front(), b = v[2].back();
		n++;
		w1[n] = -1, w2[n] = 0;
		x[n] = a.ec, y[n] = a.fb;
		n++;
		w1[n] = -1, w2[n] = 0;
		x[n] = b.ec, y[n] = b.fb;
	}
	if (v[3].size()) {
		auto a = v[3].front(), b = v[3].back();
		n++;
		w1[n] = 0, w2[n] = 1;
		x[n] = a.ec, y[n] = a.fb;
		n++;
		x[n] = b.ec, y[n] = b.fb;
		w1[n] = 0, w2[n] = 1;
	}
	if (v[4].size()) {
		auto a = v[4].front(), b = v[4].back();
		n++;
		w1[n] = 0, w2[n] = -1;
		x[n] = a.ec, y[n] = a.fb;
		n++;
		x[n] = b.ec, y[n] = b.fb;
		w1[n] = 0, w2[n] = -1;
	}
	sort(v[3].begin(), v[3].end(), [](pii a, pii b) { return a.ec < b.ec; });
	sort(v[4].begin(), v[4].end(), [](pii a, pii b) { return a.ec < b.ec; });
	sort(v[1].begin(), v[1].end(), [](pii a, pii b) { return a.fb < b.fb; });
	sort(v[2].begin(), v[2].end(), [](pii a, pii b) { return a.fb < b.fb; });
	if (v[1].size()) {
		auto a = v[1].front(), b = v[1].back();
		n++;
		w1[n] = 1, w2[n] = 0;
		x[n] = a.ec, y[n] = a.fb;
		n++;
		w1[n] = 1, w2[n] = 0;
		x[n] = b.ec, y[n] = b.fb;
	}
	if (v[2].size()) {
		auto a = v[2].front(), b = v[2].back();
		n++;
		w1[n] = -1, w2[n] = 0;
		x[n] = a.ec, y[n] = a.fb;
		n++;
		w1[n] = -1, w2[n] = 0;
		x[n] = b.ec, y[n] = b.fb;
	}
	if (v[3].size()) {
		auto a = v[3].front(), b = v[3].back();
		n++;
		w1[n] = 0, w2[n] = 1;
		x[n] = a.ec, y[n] = a.fb;
		n++;
		x[n] = b.ec, y[n] = b.fb;
		w1[n] = 0, w2[n] = 1;
	}
	if (v[4].size()) {
		auto a = v[4].front(), b = v[4].back();
		n++;
		w1[n] = 0, w2[n] = -1;
		x[n] = a.ec, y[n] = a.fb;
		n++;
		x[n] = b.ec, y[n] = b.fb;
		w1[n] = 0, w2[n] = -1;
	}
	calc(0);
	rep (i, 1, 10000000) {
		int id = (rnd() % 1000000000) + 1;
		calc(id);
	}
	while (clock() * 1.0 / CLOCKS_PER_SEC < 0.9) simulateAnneal();
	cout << minArea << endl;
	return 0;
}
