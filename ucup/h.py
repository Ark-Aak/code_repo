import math

def solve():
    ips = input().split(' ')
    n = int(ips[0])
    m = int(ips[1])
    x = math.ceil((n + 1) / m)
    ans1 = x * m
    ans2 = -1
    if n <= m:
        ans2 = m
    else:
        prefix = ips[0][:len(ips[0]) - len(ips[1])]
        if len(prefix) == 0:
            prefix = "0"
        nxt = str(int(prefix) + 1)
        fn1 = int(prefix + ips[1])
        fn2 = int(nxt + ips[1])
        if fn1 >= n:
            ans2 = fn1
        else:
            ans2 = fn2
    if ans2 < ans1 and ans2 != -1:
        return ans2
    else:
        return ans1

T = int(input())

for i in range(T):
    print(solve())
