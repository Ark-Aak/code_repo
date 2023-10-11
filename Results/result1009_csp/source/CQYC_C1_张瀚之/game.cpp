#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int T;
int a[MAXN + 5][MAXN + 5];
long long sum[MAXN + 5][MAXN + 5];

namespace Search {
    int n, m; //0~n, 0~m

    int gt(int fx, int fy, int nx, int ny) {
        if (nx < fx && ny < fy) return ny == 1 ? 1 : 2; //LU, Lst ? 1 : 2
        else if (nx < fx && ny > fy) return ny == m ? 0 : 3; //RU, Rst ? 0 : 3
        else if (nx > fx && ny < fy) return ny == 1 ? 3 : 0; //LD, Lst ? 3 : 0
        else return ny == m ? 2 : 1; //RD, Rst ? 2 : 1
    } //LU: 0 RU: 1 LD: 2 RD: 3

    bool check(int x, int y) {
        return (x == 1 || x == n) && (y == 1 || y == m);
    }

    void update(int& x, int& y, int dir) {
        int minn = min(dir & 1 ? m - y : y - 1, dir >= 2 ? n - x : x - 1);
        x += dir >= 2 ? minn : -minn;
        y += dir & 1 ? minn : -minn;
    }

    int get_ans(int N, int M) {
        n = N; m = M;
        int fx = n, fy = 1, nx = 0, ny = 0, ans = 0, dir = 1;
        while (!check(nx, ny)) {
            nx = fx; ny = fy;
            update(nx, ny, dir);
            dir = gt(fx, fy, nx, ny);
            fx = nx; fy = ny;
            ans++;
        }
        return ans;
    }
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    for (int i = 1; i <= MAXN; i++)
        for (int j = 1; j <= MAXN; j++) {
            int d = __gcd(i, j);
            if (d > 1) a[i][j] = a[i / d][j / d];
            else a[i][j] = Search::get_ans(i + 1, j + 1) - 1;
        }
    for (int i = 1; i <= MAXN; i++)
        for (int j = 1; j <= MAXN; j++)
            sum[i][j] = (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j]) % 1000000007;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("%lld\n", sum[n][m]);
    }
    return 0;
}
