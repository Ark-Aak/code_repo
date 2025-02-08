import math

n = int(input())
a = list(map(int, input().strip().split(' ')))
a.sort();

f = [[0] * (n + 1) for _ in range(n + 1)]
a.insert(0, 0)

f[1][1] = a[1]
for i in range(2, n + 1):
    for j in range(1, i + 1):
        f[i][j] = f[i - 1][j - 1] * a[i] + (i - 1) * f[i - 1][j]

b = []
for i in range(n + 1):
    b.append(f[n][i])

res = a[1]
for i in range(2, n + 1):
    res = math.gcd(res, b[i])
    
print(res)
