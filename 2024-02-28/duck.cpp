#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

using namespace std;

typedef long long ll;
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

const int MAXN = 1e3 + 5;

int n, m, ans[MAXN][MAXN], sum,
    O[5][5] = { { 1, 6, 13, 21, 5 },
                { 11, 19, 3, 8, 18 },
                { 14, 22, 0, 15, 23 },
                { 2, 7, 12, 20, 4 },
                { 10, 16, 24, 9, 17 } },
    J[5][5] = { { 1, 19, 7, 4, 20 },
                { 14, 11, 22, 17, 12 },
                { 8, 5, 0, 9, 6 },
                { 2, 18, 13, 3, 21 },
                { 15, 10, 23, 16, 0 } },
    JT[5][5] = { { 2, 15, 8, 5, 16 },
                 { 10, 25, 18, 13, 24 },
                 { 20, 6, 1, 21, 7 },
                 { 3, 14, 9, 4, 17 },
                 { 11, 22, 19, 12, 23 } },
    UD[5][5] = { { 2, 7, 14, 22, 6 },
                 { 12, 20, 4, 9, 19 },
                 { 15, 23, 1, 16, 24 },
                 { 3, 8, 13, 21, 5 },
                 { 11, 17, 25, 10, 18 } },
    DU[5][5] = { { 11, 17, 25, 10, 18 },
                 { 3, 8, 13, 21, 5 },
                 { 15, 23, 1, 16, 24 },
                 { 12, 20, 4, 9, 19 },
                 { 2, 7, 14, 22, 6 } },
    LR[5][5] = { { 6, 19, 24, 5, 18 },
                 { 22, 9, 16, 21, 10 },
                 { 14, 4, 1, 13, 25 },
                 { 7, 20, 23, 8, 17 },
                 { 2, 12, 15, 3, 11 } },
    RL[5][5] = { { 11, 3, 15, 12, 2 },
                 { 17, 8, 23, 20, 7 },
                 { 25, 13, 1, 4, 14 },
                 { 10, 21, 16, 9, 22 },
                 { 18, 5, 24, 19, 6 } },
    N5[5][5] = { { 1, 14, 7, 4, 15 },
                 { 9, 22, 17, 12, 23 },
                 { 19, 5, 25, 20, 6 },
                 { 2, 13, 8, 3, 16 },
                 { 10, 21, 18, 11, 24 } };

void fill_UD(int x, int y) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) ans[x + i][y + j] = sum + UD[i][j];
    sum += 25;
}
void fill_DU(int x, int y) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) ans[x + i][y + j] = sum + DU[i][j];
    sum += 25;
}
void fill_LR(int x, int y) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) ans[x + i][y + j] = sum + LR[i][j];
    sum += 25;
}
void fill_RL(int x, int y) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) ans[x + i][y + j] = sum + RL[i][j];
    sum += 25;
}
void fill_J(int x, int y) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) ans[x + i][y + j] = sum + J[i][j];
    sum += 23;
}
void fill_O(int x, int y) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) ans[x + i][y + j] = sum + O[i][j];
    sum += 24;
}
void fill_JT(int x, int y) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) ans[x + i][y + j] = sum + JT[i][j];
    sum += 25;
}

signed main() {
    freopen("duck.in", "r", stdin);
    freopen("duck.out", "w", stdout);
    cin >> n;
    m = n / 5;
    if (n == 5) {
		rep (i, 0, n - 1) {
			rep (j, 0, n - 1) printf("%lld ", N5[i][j]);
			printf("\n");
		}
        return 0;
    }
    int x = 1, y = 1;
    if (n % 2 == 0) {
        fill_O(x, y);
        ans[3][3] = n * n;
        while (1) {
            x += 5;
            if (x == n - 4) break;
            fill_UD(x, y);
        }
        fill_LR(x, y);
        y += 5;
        while (1) {
            rep (i, 1, m - 2) fill_LR(x, y), y += 5;
            fill_DU(x, y), x -= 5;
            rep (i, 1, m - 2) fill_RL(x, y), y -= 5;
            if (x == 1 && y == 6) {
                fill_RL(x, y), y -= 5;
                break;
            }
			else fill_DU(x, y), x -= 5;
        }
		rep (i, 1, n) {
            rep (j, 1, n) printf("%lld ", ans[i][j]);
            printf("\n");
        }
    }
	else {
        fill_J(x, y);
        ans[3][3] = n * n;
        ans[5][5] = n * n - 1;
        while (1) {
            x += 5;
            if (x == n - 4) break;
            fill_UD(x, y);
        }
        fill_LR(x, y);
        y += 5;
        while (1) {
            rep (i, 1, m - 2) fill_LR(x, y), y += 5;
            fill_DU(x, y), x -= 5;
            if (x == 6 && y == n - 4) break;
            rep (i, 1, m - 2) fill_RL(x, y), y -= 5;
            fill_DU(x, y), x -= 5;
        }
        while (1) {
            fill_DU(x, y), x -= 5;
            fill_RL(x, y), y -= 5;
            fill_UD(x, y), x += 5;
            if (x == 6 && y == 6) break;
            fill_RL(x, y), y -= 5;
        }
        fill_JT(x, y);
		rep (i, 1, n) {
            rep (j, 1, n) printf("%lld ", ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}
