# inserter 笔记

## 1. inserter 是什么

`inserter` 是 STL 提供的一个**插入迭代器适配器**。

它的作用是：

```text
把“赋值操作”变成“插入操作”
```

普通迭代器：

```cpp
*it = value;
```

表示修改当前位置的值。

而 `inserter` 生成的插入迭代器：

```cpp
*it = value;
```

表示向容器中插入 `value`。

---

## 2. 头文件

使用 `inserter` 需要：

```cpp
#include <iterator>
```

如果配合算法使用，一般还会有：

```cpp
#include <algorithm>
```

---

## 3. 基本语法

```cpp
inserter(container, pos)
```

例如：

```cpp
inserter(s, s.begin())
```

含义：

```text
向容器 s 中插入元素，s.begin() 是插入位置提示
```

对于 `set` 这种自动排序的容器来说，`s.begin()` 只是提示，最终元素还是会按照排序规则放置。

---

## 4. 为什么 set 不能直接用 begin() 当输出位置

比如：

```cpp
set<int> s;
```

不能这样：

```cpp
*s.begin() = 10; // 错
```

因为 `set` 中的元素是只读的，不能随便修改。

原因是：

```text
set 会自动排序，如果允许直接修改元素，可能破坏 set 的排序结构。
```

所以 STL 算法如果要把结果放进 `set`，不能写：

```cpp
merge(s1.begin(), s1.end(), s2.begin(), s2.end(), s3.begin());
```

应该写：

```cpp
merge(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
```

---

## 5. inserter 的效果

代码：

```cpp
set<int> s;

 auto it = inserter(s, s.begin());

*it = 5;
*it = 1;
*it = 3;
```

等价于：

```cpp
set<int> s;

s.insert(5);
s.insert(1);
s.insert(3);
```

最后结果：

```text
1 3 5
```

虽然插入顺序是 `5 1 3`，但是 `set` 会自动排序。

---

## 6. inserter 常用于 STL 算法

例如合并两个 `set`：

```cpp
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    set<int> s1 = {1, 3, 5};
    set<int> s2 = {2, 4, 6};
    set<int> s3;

    merge(s1.begin(), s1.end(),
          s2.begin(), s2.end(),
          inserter(s3, s3.begin()));

    for (int x : s3)
    {
        cout << x << " ";
    }

    return 0;
}
```

输出：

```text
1 2 3 4 5 6
```

---

## 7. inserter 和普通 insert 的区别

普通插入：

```cpp
s.insert(10);
```

直接向容器插入元素。

`inserter`：

```cpp
auto it = inserter(s, s.begin());
*it = 10;
```

通过“赋值”的形式完成插入。

所以平时自己手写插入时，一般用：

```cpp
s.insert(10);
```

而在 STL 算法中，需要一个“输出迭代器”时，就用：

```cpp
inserter(s, s.begin())
```

---

## 8. 和 back_inserter 的区别

`back_inserter` 适合有 `push_back()` 的容器，比如：

```text
vector
deque
list
```

例如：

```cpp
vector<int> v;

copy(s.begin(), s.end(), back_inserter(v));
```

它底层相当于：

```cpp
v.push_back(value);
```

但是 `set` 没有 `push_back()`，所以不能用 `back_inserter`。

`set` 要用：

```cpp
inserter(s, s.begin())
```

---

## 9. 常见插入迭代器总结

| 工具 | 底层操作 | 适合容器 |
|---|---|---|
| `back_inserter(c)` | `c.push_back(value)` | `vector`、`deque`、`list` |
| `front_inserter(c)` | `c.push_front(value)` | `list`、`deque` |
| `inserter(c, pos)` | `c.insert(pos, value)` | `set`、`map`、`list`、`vector` 等 |

---

## 10. 一句话总结

```text
inserter 是插入迭代器，把算法中的“赋值输出”变成“插入元素”。
```

尤其适合：

```cpp
set
map
multiset
multimap
```

这类不能直接用普通迭代器写入的容器。

常用写法：

```cpp
inserter(container, container.begin())
```

例如：

```cpp
merge(s1.begin(), s1.end(),
      s2.begin(), s2.end(),
      inserter(s3, s3.begin()));
```
