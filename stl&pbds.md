# -1.写在前面

本文是学习 STL 时写的笔记，如有错误请指出。  
方法定义等来自 [Cpp Reference](https://cplusplus.com/reference)。  
右上角有角标的地方可以在文章底部找到详细信息。

# 0.目录

- **常用 STL 模板**
   - bitset
	- queue
  	- stack
   - map
   - unordered_map
   - set
   - multiset
   - vector
   - deque
   - list
   - multimap
   - priority_queue
- **__gnu_pbds 模板**
	- tree
   - priority_queue

# 1.常用 STL 模板

## `std::`bitset

- **模板定义**

```cpp
template <size_t N> class bitset;
```

- **使用方法**

该模板定义接受且仅接受一个参数 `N`，表示 `bitset` 的大小。  
`bitset` 类似于一个 `bool` 数组，但是 `bitset` 使用每一 `bit` 存储一个 `bool` 值，相较于原版 `bool` 数组，访问速度从 $O(n)$ 下降到约 $O(\frac{n}{w})$ $^{[1]}$。

访问和赋值 `bitset` 内元素的方法和数组相同，使用 `[]` 运算符访问，下标从 $0$ 开始。  

`bitset` 可以和**另一个 `bitset`** 进行逻辑操作以及位运算，运算符和正常操作相同。

- **常用成员方法**

| 方法名 |            作用             |
| :----: | :-------------------------: |
| count  | 计算 `bitset` 内 $1$ 的数量 |
|  size  |    返回 `bitset` 的大小     |
| reset  |        清空 `bitset`        |
|  set   |      给 `bitset` 赋值       |

方法定义 - `set`  

```cpp
bitset& set() noexcept;
bitset& set (size_t pos, bool val = true);
```

方法解释 - `set`  

不传入参数是，整个 `bitset` 都将被赋值为 $1$。  
传入参数是，接受且仅接受两个参数，表示将**下标**为 `pos` 元素的值改为 `val`。

- **使用实例**

```cpp
#include <bitset>
#include <iostream>

int main(){
	std::bitset<8> bs;
	bs[1] = true;
	std::cout << bs << std::endl; //00000010
	std::cout << bs.count() << std::endl; //1
	bs.reset();
	std::cout << bs << std::endl; //00000000
	std::cout << bs.size(); //8
}
```

# 2.__gnu_pbds 模板

## `__gnu_pbds::`tree  

- **模板定义**
  
```cpp
tree<Key, Mapped, Cmp_Fn = std::less<Key>, Tag = rb_tree_tag,
Node_Update = null_tree_node_update,
Allocator = std::allocator<char> >
```
`Key`：储存的元素类型。

`Mapped`：映射规则类型，一般填入 `null_type`。

`Cmp_Fn`：关键字比较函子，例如 `std::less<Key>`。

`Tag`：选择使用何种底层数据结构类型，默认是 `rb_tree_tag`。  
可以有三种取值：

- `rb_tree_tag`：红黑树

- `splay_tree_tag`：Splay

- `ov_tree_tag`：有序向量树

`Node_Update`：更新节点的策略，默认使用 `null_node_update`，若要使用 `order_of_key` 和 `find_by_order` 方法，需要使用 `tree_order_statistics_node_update`

`Allocator`：空间分配器类型。

- 成员函数

  - `insert(x)`：向树中插入一个元素 $x$，返回 `std::pair<point_iterator, bool>`。

  - `erase(x)`：从树中删除一个元素/迭代器 $x$，返回一个 `bool` 表明是否删除成功。

  - `order_of_key(x)`：返回 $x$ 以 `Cmp_Fn` 比较的排名。

  - `find_by_order(x)`：返回 `Cmp_Fn` 比较的排名所对应元素的迭代器。

  - `lower_bound(x)`：以 `Cmp_Fn` 比较做 `lower_bound`，返回迭代器。

  - `upper_bound(x)`：以 `Cmp_Fn` 比较做 `upper_bound`，返回迭代器。

  - `join(x)`：将 $x$ 树并入当前树，$x$ 树被删除，需要两树类型相同。

  - `split(x, b)`：以 `Cmp_Fn` 比较，小于等于 $x$ 的留在当前树，其余的放进 $b$ 树。

  - `empty()`：返回是否为空。
  - `size()`：返回大小。

---
- $[1]$ $w$ 表示计算机位数。