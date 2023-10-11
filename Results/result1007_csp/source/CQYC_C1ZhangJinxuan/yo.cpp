#include <cstdio>
#include <cstring>
using namespace std;

int n;
char t[1000005], s[1000005];
int f[1000005][11];
bool dfs(int i, int rem) { // i pos, mod 11 res, can yoimiya win
        if (i == n + 1) {
                if (rem == 0) {
                        return 1;
                } else return 0;
        }
        if (f[i][rem] != -1) return f[i][rem];
        if (t[i] == 'o') {
                if (i & 1) return f[i][rem] = dfs(i + 1, (rem - (s[i] - '0') + 11) % 11) && dfs(i + 1, rem);
                else return f[i][rem] = dfs(i + 1, (rem + (s[i] - '0')) % 11) && dfs(i + 1, rem);
        } else {
                if (i & 1) return f[i][rem] = dfs(i + 1, (rem - (s[i] - '0') + 11) % 11) || dfs(i + 1, rem);
                else return f[i][rem] = dfs(i + 1, (rem + (s[i] - '0')) % 11) || dfs(i + 1, rem);
        }
}

int main() {
        freopen("yo.in", "r", stdin);
        freopen("yo.out", "w", stdout);
        memset(f, 255, sizeof(f));
        scanf("%d%s%s", &n, s + 1, t + 1);
        if (dfs(1, 0)) {
                printf("yoimiya\n");
        } else printf("oimiya\n");
        return 0;
}

