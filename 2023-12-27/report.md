看了一下题感觉可能 $\text{T1, T3}$ 可做，$\text{T2}$ 显然不可做。

看了半个小时的 $\text{T1}$ 无果。

考虑到一次操作相当于获取序列后缀的最小值，并互换最小值和 $l$。

即一次操作删除序列后缀的最小值并插入 $l$。

感觉需要数据结构。没想出来什么可以维护的。打个暴力跳了。

获得了 $15pts$，复杂度 $O(n!)$。

然后看 $\text{T3}$。

根据特殊性质考虑和 $m$ 强相关的复杂度。

$O(nm)$，$O(nm\log m)$ 大概都是可以接受的。

考虑挂 $\log$，我们二分答案，如果可以做到 $O(n)$ `check` 就可以得到 $O(n\log m)$ 的复杂度。

感觉不是很行。$n$ 和 $m$ 差了两个数量级，复杂度最多支持到 $O(n\log^2 n)$。不挂 $m$ 我觉得不大可做。

码个暴力先，每次暴力 `BFS` 然后二分答案可以做到 $O(nm^2\log m)$，没准 $80pts$。

我日题读错了，复杂度变成 $O(n^2m\log n)$ 了，今日最大小丑。

我日没有单调性，复杂度变成 $O(n^3m)$ 了，小丑呜呜。

笑似了，第一档暴力分都拿不到，$6.25 \times 10^{10}$ 跑捏马一辈子😅。

相信大样例的强度不如相信 LC 是秦始皇。

$\text{T2}$ 为什么正解只会比暴力多 $5pts$ 啊。

调了八百年 $\text{T2}$ 暴力，最后发现原来是我不会写最长上升子序列了啊😅。

$\text{T3}$ 柠檬熟了😓，只要我少一个 $n$ 或者 $m$ 我都能拿到暴力分捏🤗，但是优化不了一点😓。

我是小丑。

烂了。上了 $20$ 分钟厕所😓，看看能不能 gank 掉一个 $n$ 或者 $m$。
