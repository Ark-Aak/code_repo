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

签。单调栈就可以了。

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

勇者小 $A$ 拔出了村子门口的石中剑,成为了钦定的勇者。开始踏上了过伐魔王的漫长道路，走出村子，就是一段初始之路,路上有 $N$ 只史莱姆，这 $N$ 只史莱姆排成了一行，每一支史莱姆有一个战斗力指数 $a_i$，小 $A$ 必须依次讨伐他们。刚刚拔出石中剑的小 $A$ 对于石中剑的使用并不款练，因此每一次小 $A$ 只能以一个额定功率$P$ 催动这把剑，此时，小 $A$ 可以击败任何战斗力小于等于 $P$ 的史莱姆。

如果小 $A$ 以额定功率 $P$ 击败了一只战斗力为 $S$ 的史莱姆，我们称小 $A$ 浪费了 $P - S$ 的能量。由于小 $A$ 对于石中剑的使用不太款练,小 $A$ 一天最多只能更改 $K$ 次剑的功率，请问，小 $A$ 如果要在一天之内通过初始之路他最少会浪费多少能量。（最开始的时候, 小 $A$ 可以免费设置一次石中剑功率并开始使用）

### 解题思路

一道 DP 签到题，但是没签上。

区间 DP，设定的功率一定是某一段区间的最大值。

$$
f_{i, j} = \min\{f_{k, j - 1} + \max\{a_{k + 1}, \cdots, a_i\} \times (i - k) - (sum_i - sum_k)\}
$$

### 代码

```cpp
signed main() {
	cin >> n >> k;
	rep (i, 1, n) cin >> a[i];
	k += 1;
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	rep (i, 1, n) {
		rep (j, 1, k) {
			int Max = 0, sum = 0;
			_rep (K, i, 1) {
				sum += a[K];
				Max = max(Max, a[K]);
				f[i][j] = min(f[K - 1][j - 1] + Max * (i - K + 1) - sum, f[i][j]);
			}
		}
	}
	int ans = LONG_LONG_MAX;
	rep (i, 1, k) ans = min(ans, f[n][i]);
	cout << ans;
	return 0;
}
```

## gaze 星锚

### 题目大意

虚数之树的一截树枝落入了量子之海中，这一截树枝中有 $n$ 个相互连通的世界泡，世界泡以链的方式连接（即 $1$ 号世界泡与 $2$ 号世界泡之间有双向通道，$2$ 号世界泡与 $3$ 号世界泡之间有双向通道依次类推，$n-1$ 号世界泡
 与 $n$ 号世界泡有双向通道连接）

作为有能力穿梭于量子之海的大善人组织，你们需要前往营救这些落入量子之海的世界泡，你们可以使用星锚技术将世界泡重新带回虚数之树上，每一次使用星锚，你可以将尚可通过双向通道与其联通的所有世界泡同时锚定回虚数之树。

量子之海有一个随时可能变化的侵蚀力 $X$，所有稳定性低于 $X$ 的世界泡都无法完整地在量子之海中表征，这也就意味着这个世界泡与其他世界泡之双向通道无法使用。当然世界泡内的人们也会采取行动，因此每一个世界泡的稳定性也是会变化的。

你只是组织里的一个观测员,你的任务是观测所有的变化，并在量子之海的侵蚀力发生变化时，告诉我们拯救所有当前还能完整表征的世界泡需要进行多少次锚定。

### 解题思路

看到数据范围是 $\le 2 \times 10^5$，考虑莫队。

> 莫队适合的最大数据范围大约是 $\le 5 \times 10^5$。

考虑在莫队指针的指向。我们令 $T$ 为时间轴，$L$ 为当前的侵蚀力。

我们把采取的行动看作是一次修改。考虑当侵蚀力移动时，新的 $L$ 为 $x$，那么明显的，被移除掉的点就是稳定性为 $x - 1$ 的所有点。

考虑移除一个点对答案带来的贡献。如果这个点两边都有点，移除它会使答案 $+1$，如果两边都没有点，则会使答案 $-1$。

我们把所有的点插入一个链表。每次就把新的值插入链表即可。

移动侵蚀力的时候把所有对应链表上的点执行删除操作即可。

### 代码

```cpp
const int MAXN = 2e5 + 5;

struct Query {
	int t, x, blk, id;
	bool operator < (const Query &t) const {
		if (blk != t.blk) return (this -> t) < t.t;
		if (blk & 1) return x > t.x;
		return x < t.x;
	}
};

vector <Query> query;

struct Modify {
	int x, val, bval;
} modify[MAXN];

vector <int> H;

int Hash(int x) {
	return lower_bound(H.begin(), H.end(), x) - H.begin() + 1;
}

struct List {
	int nxt[3 * MAXN], pre[3 * MAXN];

	void insert(int x, int y) {
		pre[nxt[x]] = y;
		nxt[y] = nxt[x];
		nxt[x] = y;
		pre[y] = x;
	}

	void erase(int x) {
		nxt[pre[x]] = nxt[x];
		pre[nxt[x]] = pre[x];
	}
} lst;

int n, m, cnt;

struct Bucket {
	bitset <MAXN> vis;
	int ans;

	void init() {
		rep (i, 1, n) vis[i] = 1;
		ans = 1;
	}

	void add(int x) {
		vis[x] = 1;
		if (vis[x - 1] && vis[x + 1]) ans--;
		if (!vis[x - 1] && !vis[x + 1]) ans++;
	}

	void del(int x) {
		vis[x] = 0;
		if (vis[x - 1] && vis[x + 1]) ans++;
		if (!vis[x - 1] && !vis[x + 1]) ans--;
	}
} counter;

int a[MAXN], blockSize, ans[MAXN];

signed main() {
	read(n), read(m);
	blockSize = ceil(n / sqrt(m) * 4);
	rep (i, 1, n) cin >> a[i], H.emplace_back(a[i]);
	rep (i, 1, m) {
		int op; read(op);
		if (op == 1) {
			int x; read(x);
			query.emplace_back((Query) {i, x, i / blockSize, ++cnt});
		}
		else {
			read(modify[i].x), read(modify[i].val);
			H.emplace_back(modify[i].val);
		}
	}

	sort(H.begin(), H.end());
	auto iter = unique(H.begin(), H.end());
	H.erase(iter, H.end());
	rep (i, 1, n) {
		a[i] = Hash(a[i]);
		lst.insert(a[i] + MAXN, i);
	}
	rep (i, 0, (int) (query.size() - 1)) query[i].x = Hash(query[i].x);
	rep (i, 1, m) if (modify[i].x) {
		modify[i].val = Hash(modify[i].val);
		modify[i].bval = a[modify[i].x];
		a[modify[i].x] = modify[i].val;
	}

	sort(query.begin(), query.end());
	int T = 1, X = 1;
	counter.init();
	for (auto [t, x, _bid, id] : query) {
		while (T < t) {
			if (modify[T].bval >= X) counter.del(modify[T].x);
			lst.erase(modify[T].x);
			lst.insert(modify[T].val + MAXN, modify[T].x);
			if (modify[T].val >= X) counter.add(modify[T].x);
			T++;
		}
		while (T > t) {
			T--;
			if (modify[T].val >= X) counter.del(modify[T].x);
			lst.erase(modify[T].x);
			lst.insert(modify[T].bval + MAXN, modify[T].x);
			if (modify[T].bval >= X) counter.add(modify[T].x);
		}
		while (X < x) {
			for (auto i = lst.nxt[X + MAXN]; i; i = lst.nxt[i]) counter.del(i);
			X++;
		}
		while (X > x) {
			X--;
			for (auto i = lst.nxt[X + MAXN]; i; i = lst.nxt[i]) counter.add(i);
		}
		ans[id] = counter.ans;
	}
	rep (i, 1, cnt) print(ans[i]), putchar(10);
	return 0;
}
```
