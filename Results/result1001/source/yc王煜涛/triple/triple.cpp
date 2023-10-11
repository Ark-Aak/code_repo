/*
    Program: triple.cpp
    Author: 1l6suj7
    DateTime: 2023-10-01 08:33:47
    Description: 
*/

#include <bits/stdc++.h>
#define int long long
#define lp(i, j, n) for(int i = j; i <= n; ++i)
#define dlp(i, n, j) for(int i = n; i >= j; --i)
#define lft(n) ((n) << 1)
#define rt(n) ((n) >> 1)
#define mst(n, v) memset(n, v, sizeof(n))
#define mcy(n, v) memcpy(n, v, sizeof(v))
#define INF 1e18
#define MAX4 0x3f3f3f3f
#define MAX8 0x3f3f3f3f3f3f3f3f
#define lc(x) (x << 1)
#define rc(x) ((x << 1) ^ 1)

using namespace std;

int read() {
    int x = 0;
    char c;
    int f = 1;
    c = getchar();
    while((c < '0' || c > '9') && c != '-') c = getchar();
    if(c == '-') f = -f, c = getchar();
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}

bool judge(int a, int b, int c, int A, int B, int C) {
    if(a - b == 0) return false;
    int t = (A - B) / (a - b);
    if((A - B) % (a - b) == 0 && A - a * t == B - b * t && A - a * t == C - c) return true;
    return false;
}

bool judge2(int a, int b, int c, int A, int B, int C) {
    if(a - b == 0 || b - c == 0) return false;
    return (A - B) % (a - b) == 0 && (B - C) % (b - c) == 0 && (A - B) / (a - b) == (B - C) / (b - c);
}

bool judge3(int A, int a) { return a != 0 && A % a == 0; }

bool judge4(int a, int b, int c, int A, int B, int C) { return a == A && (B - b == C - c || judge3(B, b) && judge3(C, c) && B / b == C / c); }

bool judge5(int a, int b, int c, int A, int B, int C) {
    int x = b - B - a + A;
    return c + x == C || c + x - C == a + x - A;
}

bool judge6(int a, int b, int c, int A, int B, int C) {
    if(!judge3(A, a)) return false;
    int t = b * (A / a);
    return B - t == C - c || judge3(B, t) && judge3(C, c) && B / t == C / c;
}
/*
8 -4 -3
-8 1 -6
*/

bool judge7(int a, int b, int c, int A, int B, int C) {
    if(!judge3(A * b, B) || a == 0 || b == 0) return false;
    int x = A * b / B - a;
    return judge3(C, c) && judge3(A, a + x) &&  A / (a + x) == C / c || judge3(C, c + x) && judge3(A, a + x) && A / (a + x) == C / (c + x) || C == c || C == c + x;
}

bool judge8(int a, int b, int c, int A, int B, int C) {
    if(!judge3(A * a - A * b, A - B) || a == 0 || b == 0) return false;
    int x = (B * a - A * b) / (A - B);
    return judge3(C, c) && judge3(A, a + x) &&  A / (a + x) == C / c || judge3(C, c + x) && judge3(A, a + x) && A / (a + x) == C / (c + x) || C == c || C == c + x;
}
/*
A / (a + x) = B / b   a + x = A * b / B  x = A * b / B - a
10 3 -4
-8 6 -10  
A / (a + x) = B / (b + x)  A * b + A * x = B * a + B * x
(A - B) * x = B * a - A * b
x = (B * a - A * b) / (A - B)
*/

int opt[2], s[2];
void dfs(int a, int b, int c, int A, int B, int C, int dep) {
    if(dep == 3 && a == A && b == B && c == C) { cout << s[0] << ' ' << s[1]; exit(0);  }
    if(dep == 3) return;
    lp(i, -10, 10) {
        s[dep - 1] = i;
        dfs(a * i, b, c, A, B, C, dep + 1), dfs(a, b * i, c, A, B, C, dep + 1), dfs(a, b, c * i, A, B, C, dep + 1);
        dfs(a * i, b * i, c, A, B, C, dep + 1), dfs(a * i, b, c * i, A, B, C, dep + 1), dfs(a, b * i, c * i, A, B, C, dep + 1);
        dfs(a * i, b * i, c * i, A, B, C, dep + 1);
    }
    lp(i, -50, 50) {
        s[dep - 1] = i;
        dfs(a + i, b, c, A, B, C, dep + 1), dfs(a, b + i, c, A, B, C, dep + 1), dfs(a, b, c + i, A, B, C, dep + 1);
        dfs(a + i, b + i, c, A, B, C, dep + 1), dfs(a + i, b, c + i, A, B, C, dep + 1), dfs(a, b + i, c + i, A, B, C, dep + 1);
        dfs(a + i, b + i, c + i, A, B, C, dep + 1);
    }
}

bool ajudge(int a, int b, int c, int A, int B, int C) {
    return judge(a, b, c, A, B, C) || judge5(a, b, c, A, B, C) || judge6(a, b, c, A, B, C) || judge7(a, b, c, A, B, C) || judge8(a, b, c, A, B, C);
}

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("triple.in", "r", stdin);
    freopen("triple.out", "w", stdout);
    //dfs(-4, 10, 3, -10, -8, 6, 1);
    int T, a, b, c, A, B, C;
    T = read();
    while(T--) {
        a = read(), b = read(), c = read();
        A = read(), B = read(), C = read();
        // if(A - a == B - b && B - b == C - c || judge3(A, a) && judge3(B, b) && judge3(C, c) && A / a == B / b && B / b == C / c
        //     || judge4(a, b, c, A, B, C) || judge4(b, a, c, B, A, C) || judge4(c, a, b, C, A, B) || A == a && B == b || A == a && C == c || B == b && C == c) printf("%d\n", 1);
        // else if(A == a || B == b || C == c || A - a == B - b || B - b == C - c || A - a == C - c || judge3(A, a) && judge3(B, b) && A / a == B / b || judge3(A, a) && judge3(C, c) && A / a == C / c || judge3(C, c) && judge3(B, b) && C / c == B / b
        //     || judge(a, b, c, A, B, C) || judge(a, c, b, A, C, B) || judge(b, c, a, B, C, A) || judge2(a, b, c, A, B, C)
        //     || ajudge(a, b, c, A, B, C) || ajudge(a, c, b, A, C, B) || ajudge(b, a, c, B, A, C) || ajudge(b, c, a, B, C, A) || ajudge(c, a, b, C, A, B) || ajudge(c, b, a, C, B, A)) printf("%d\n", 2);
        // else printf("%d\n", 3);
        if(A - a == B - b && B - b == C - c || judge3(A, a) && judge3(B, b) && judge3(C, c) && A / a == B / b && B / b == C / c
            || judge4(a, b, c, A, B, C) || judge4(b, a, c, B, A, C) || judge4(c, a, b, C, A, B) || A == a && B == b || A == a && C == c || B == b && C == c) printf("%d\n", 1);
        else printf("%d\n", 2);
    }
    return 0;
}
/*
2 3 4
5 4 9
a * x - A = b * x - B
a * x - b * x = A - B
x = (A - B) / (a - b)

a + x - A = b - B  x = b - B - a + A
c + x == C || c + x - C == a + x - A

-2 8 5
3 3 -5

-4 8 -3
1 -8 -6

-4 10 3     -10 4 -3
-10 -8 6

A / (a + x) = B / b   a + x = A * b / B  x = A * b / B - a
*/