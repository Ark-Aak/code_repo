快11点了才开始写记录。惭愧。

比较自卑，写了一个小时的 T1，结果 T2 背包改了接近一个小时，愿意竟是因为高贵的枚举顺序捏/kk/kk/kk。

T1 不难发现答案具有单调性。使用双端队列进行二分答案。

注意到每个学生都有一个开始写讲义的时间范围，在这个范围之内越早写越好。由于 $C \ge B$，一个分身在一波最多只能应对一个人。

二分答案就行了。

T2 正难则反，求删去的边减少的贡献的最大值。不难发现是个背包，可以做到 $O(nV)$，有 $50$ 分捏/cf。