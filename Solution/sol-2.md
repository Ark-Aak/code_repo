## kel 可怜

### 题目大意

给定 $n$, 你需要给出一个长度为 $n$ 的『kel 序列』$a$。

我们把你个长度为 $n$ 的序列 $a$ 称为『kel 序列』,当且仅当它满足 $\forall1\leq l<r<l^{\prime}<r^{\prime}\leq n,a_{l...r}\neq a_{l^{\prime}...r^{\prime}}$。

Shinomiya 想要你给出一个『kel 序列』, 若无解, 请输出 Shinomiya。

值得注意的是,『kel 序列』仅由 $[L,R]$ 间的整数组成。
SPJ 会判断你的『kel 序列』并且给出相应分数。

- 如果你给出的『kel 序列』最优, 你会获得这个测试点的全部分数（即 $5$ 分）。

- 如果你给出的『kel 序列』合法但非最优, 你会获得这个测试点的部分分（即 $3$ 分）。

- 如果你给出的『kel 序列』非法, 你会在该测试点获得 $0$ 分。

『kel 序列』最优当且仅当其字典序在长度为$n$ 的『kel 序列』中最小。

### 解题思路

看到这个限制条件，手玩可以发现其实就是没有任何长度为 $2$ 的相同不相交子段。

如果没有限制的时候肯定可以用形如下面的方式构造：
$$
0,0,0,1,0,2,0,3 \cdots
$$
左端点的变化并不会改变我们构造序列的方式。我们只需要把 $0$ 相应的改为 $L$ 就可以了。

现在来考虑右端点对序列构造方式产生的变化，我们先假设左端点没有限制，即限制为 $[0, R]$。

我们还是希望像如上方式一样构造，也就是：
$$
0, 0, 0, 1, 0, 2, 0, 3, \cdots, R, R, R
$$
但是要注意最后可以出现 $(r, 0)$ 和 $(r, r)$，如果 $n > (r - l + 2) (r - l + 1) + 1$， 那么无解。

### 代码

```cpp
signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("kel.in", "r", stdin);
	freopen("kel.out", "w", stdout);
#endif
#endif
	int n, l, r;
	cin >> n >> l >> r;
	if (((r - l + 2) * (r - l + 1) + 1) < n) {
		cout << "Shinomiya";
		return 0;
	}
	if (n <= 3) {
		rep (i, 1, n) cout << l << endl;
		return 0;
	}
	int lft = l, rgt = l;
	rep (i, 1, n / 2) {
		if (lft > r) continue;
		res[++cnt] = lft, res[++cnt] = rgt;
		++rgt;
		if (rgt > r) rgt = ++lft;
	}
	if (cnt < n) res[++cnt] = lft;
	if (res[n - 1] == r) res[n] = l;
	rep (i, 1, n) cout << res[i] << endl;
	return 0; 
}
```

## gen 二进制

### 题目大意

定义 $f(x,y)=(x\oplus y)\times(x|y)\times(x\&y)$，其中 $\oplus,|,\&$ 分别代表按位异或、按位或、按位与。

给你一张 $n$ 个点，$m$ 条边无向图，其中无自环，可能有重边。记点 $i$ 的度数为 $deg_i$。

请你求出 $\sum_{i=1}^n\sum_{j=1}^nf(deg_i,deg_j)$，由于答案可能很大，输出时请将答案对 $10^9+7$ 取模。

### 解题思路

这能叫根号分治？？？？？？？？？

不难发现 $\sum^n_{i=1} deg_i = 2m$，很容易就能得出不同的 $deg_i$ 最多只有 $O(\sqrt m)$  级别。

>假设最坏情况，每个 $deg_i$ 互不相同。
>
>即 $\frac{x(x + 1)}{2} = 2m$。

我们只需要枚举所有不同的 $deg_i$ 进行计算即可。

最终答案需要除以 $2$。

### 代码

```cpp
int f(int x, int y) {
	return (x ^ y) % MOD * (x | y) % MOD * (x & y) % MOD;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("gen.in", "r", stdin);
	freopen("gen.out", "w", stdout);
#endif
#endif
	cin >> n >> m;
	rep (i, 1, m) {
		int u, v;
		cin >> u >> v;
		deg[u] += 1;
		deg[v] += 1;
	}
	rep (i, 1, n) {
		if (!cnt[deg[i]]) t.emplace_back(deg[i]);
		cnt[deg[i]]++; cnt[deg[i]] %= MOD;
	}
	sort(t.begin(), t.end());
	rep (i, 0, t.size() - 1) {
		rep (j, i + 1, t.size() - 1) {
			ans += f(t[i], t[j]) * cnt[t[i]] % MOD * cnt[t[j]];
			ans %= MOD;
		}
	}
	cout << ans << endl;
	return 0; 
}
```

## mountain 顶峰远眺

### 题目大意

Farmer John，也就是 FJ，带领了他的奶牛们登上了一座座山峰……

我们抽象地描述山的形状，有 $n$ 座山峰，从左到右的高度依次为 $h_i$，现在 FJ 想知道，对于 $i$，假设他在山 $i$ 上，能看到多少山峰？

- 对于 $i, j (i \ne j)$，我们称 $i$ 可以看见 $j$ 当且仅当对于它们中间所有山（包括 $i, j$）的高度要**小于等于** $i$ 的高度。

### 解题思路

签到题。单调栈就可以了。

输入量太大不要用 `std::cin` 和 `std::cout` 以及 `std::endl` 啊！！！

输入量太大不要用 `std::cin` 和 `std::cout` 以及 `std::endl` 啊！！！

输入量太大不要用 `std::cin` 和 `std::cout` 以及 `std::endl` 啊！！！

### 代码

```cpp
int main() {
	read(n);
	rep (i, 1, n)  read(h[i]);
	rep (i, 1, n) ans2[i] = n + 1;
	rep (i, 1, n) {
		while (s.size() && s.top().first <= h[i]) s.pop();
		if (s.size()) ans1[i] = s.top().second;
		s.push({h[i], i});
	}
	while (s.size()) s.pop();
	_rep (i, n, 1) {
		while (s.size() && s.top().first <= h[i]) s.pop();
		if (s.size()) ans2[i] = s.top().second;
		s.push({h[i], i});
	}
	rep (i, 1, n) print(ans2[i] - ans1[i] - 2), putchar(10);
	return 0; 
}
```

## game 游戏

### 题目大意

共有 $n$ 张两面的卡牌，按照 $1 \sim n$ 的顺序排列。卡牌一面黑一面白，初始情况下一些卡牌黑面向上（用 $0$ 表示），剩下的白面向上 (用 $1$ 表示)。

牌的状态是 $01010$，那么一个人可以将卡牌状态变为 $11110, 00010, 01110$ 等，但不能变成 $10110$ 或 $01010$。

如果一次操作之后, 所有卡牌都变成黑面朝上或都变成白面朝上, 那么进行这个操作的人获胜。

小 $C$ 和小 $D$ 都绝顶聪明，他们都使用最优策略，即尽量让自己获胜，如无法获胜则尽量不让对方获胜。
请你判断游戏的结果。

### 解题思路

先考虑一步获胜的情况。

当某一种颜色最左边和最右边的差不超过 $k$ 时，先手必胜。

那么容易想到，如果 Alice 第一步无法获胜，那么她以后都不可能再获胜了，因为任意一次操作过后必定会出现连续的长度 $\ge k$ 的颜色段。

实际上，如果存在某一种颜色的 $\max - \min \le k$，那么在先手无法一步获胜的情况下会使另外一种颜色变短，那么此时后手必胜。

依次来判断即可。

### 代码

```cpp
int main() {
	cin >> T;
	while (T --> 0) {
		cin >> n >> k >> s;
		s = ' ' + s;
		int l1 = 0, r1 = 0, l2 = 0, r2 = 0;
		rep (i, 1, n) {
			if (s[i] == '0') {
				if (l1 == 0) l1 = i;
				r1 = i;
			}
			else {
				if (l2 == 0) l2 = i;
				r2 = i;
			}
		}
		if (r1 - l1 + 1 <= k || r2 - l2 + 1 <= k) {
			cout << "win" << endl;
		}
		else if (r1 - l1 <= k && r2 - l2 <= k) {
			cout << "lose" << endl;
		}
		else cout << "tie" << endl;
	}
	return 0; 
}
```

## path 初始之路

### 题目大意
