# C++ 常用新特性笔记

这份笔记整理的是现在复习 STL、写小项目时比较常用的新特性，主要包括：

- `auto`
- 范围 `for`
- `nullptr`
- `lambda` 表达式
- `override`
- `final`
- `default`
- `delete`
- `emplace` / `emplace_back`
- 智能指针：`unique_ptr`、`shared_ptr`、`weak_ptr`
- `using` 类型别名
- `decltype`

## 1. auto

### 作用

`auto` 用来让编译器自动推导变量类型。

常用于 STL 迭代器、范围遍历、接收复杂返回值。

### 基本写法

```cpp
auto a = 10;      // int
auto b = 3.14;    // double
auto c = "hello"; // const char*
```

### STL 迭代器

```cpp
vector<int> v = {1, 2, 3};

for (auto it = v.begin(); it != v.end(); it++)
{
    cout << *it << " ";
}
```

不用再写很长的类型：

```cpp
vector<int>::iterator it;
```

### 注意 const 和引用

```cpp
int a = 10;

auto b = a;   // b 是 int，复制一份
auto& c = a;  // c 是 int&，引用 a
```

如果不想复制容器中的元素，常写：

```cpp
for (const auto& x : v)
{
    cout << x << endl;
}
```

---

## 2. 范围 for

### 作用

范围 for 用来遍历数组或 STL 容器。

### 基本写法

```cpp
vector<int> v = {1, 2, 3};

for (int x : v)
{
    cout << x << " ";
}
```

### 使用 auto

```cpp
for (auto x : v)
{
    cout << x << " ";
}
```

### 只读取元素

如果只是读取，推荐：

```cpp
for (const auto& x : v)
{
    cout << x << " ";
}
```

这样不会复制元素，也不会修改元素。

### 修改元素

如果要修改容器里的元素，必须用引用：

```cpp
for (auto& x : v)
{
    x += 10;
}
```

如果不加引用：

```cpp
for (auto x : v)
{
    x += 10;
}
```

这里只是修改副本，原容器不会变。

---

## 3. nullptr

### 作用

`nullptr` 表示空指针，用来替代以前的 `NULL`。

### 基本写法

```cpp
int* p = nullptr;
```

### 判断空指针

```cpp
if (p == nullptr)
{
    cout << "空指针" << endl;
}
```

或者：

```cpp
if (p != nullptr)
{
    cout << *p << endl;
}
```

### 为什么用 nullptr

以前常写：

```cpp
int* p = NULL;
```

但是 `NULL` 本质上可能是整数 `0`，容易和普通整数混淆。

`nullptr` 是专门的空指针类型，更安全。

---

## 4. lambda 表达式

### 作用

`lambda` 是匿名函数，可以在需要函数的地方临时写一个函数。

常用于 STL 算法，例如：

```cpp
sort
find_if
for_each
count_if
```

### 基本语法

```cpp
[捕获列表](参数列表) {
    函数体
};
```

### 无参数 lambda

```cpp
auto f = []() {
    cout << "hello" << endl;
};

f();
```

### 有参数 lambda

```cpp
auto add = [](int a, int b) {
    return a + b;
};

cout << add(10, 20) << endl;
```

### 配合 sort

```cpp
vector<int> v = {3, 1, 5, 2};

sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;
});
```

这里表示降序排序。

### 配合 find_if

```cpp
vector<int> v = {1, 3, 5, 7, 9};

auto it = find_if(v.begin(), v.end(), [](int x) {
    return x > 5;
});
```

找到第一个大于 5 的元素。

### 捕获外部变量

```cpp
int limit = 5;

auto it = find_if(v.begin(), v.end(), [limit](int x) {
    return x > limit;
});
```

`[limit]` 表示把外部变量 `limit` 拿进 lambda 使用。

### 常见捕获方式

```cpp
[x]   // 按值捕获 x
[&x]  // 按引用捕获 x
[=]   // 按值捕获所有用到的外部变量
[&]   // 按引用捕获所有用到的外部变量
```

---

## 5. override

### 作用

`override` 用在子类重写父类虚函数时。

它可以让编译器检查这个函数是否真的重写了父类函数。

### 基本写法

```cpp
class Animal
{
public:
    virtual void speak()
    {
        cout << "动物说话" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak() override
    {
        cout << "猫叫" << endl;
    }
};
```

### 好处

如果你写错函数名：

```cpp
void speek() override
{
}
```

编译器会报错，因为父类没有 `speek()` 这个虚函数。

如果不写 `override`，这个错误可能不容易发现。

---

## 6. final

### 作用

`final` 可以禁止类被继承，或者禁止虚函数继续被重写。

### 禁止类被继承

```cpp
class Animal final
{
};
```

这样其他类不能再继承 `Animal`。

### 禁止虚函数继续重写

```cpp
class Animal
{
public:
    virtual void speak()
    {
    }
};

class Cat : public Animal
{
public:
    void speak() final
    {
    }
};
```

`Cat` 的子类不能再重写 `speak()`。

---

## 7. default

### 作用

`default` 表示让编译器生成默认函数。

### 默认构造

```cpp
class Person
{
public:
    Person() = default;
};
```

表示使用编译器生成的默认构造函数。

### 默认析构

```cpp
class Person
{
public:
    ~Person() = default;
};
```

### 默认拷贝构造

```cpp
class Person
{
public:
    Person(const Person&) = default;
};
```

---

## 8. delete

### 作用

`delete` 表示禁止某个函数被调用。

### 禁止拷贝

```cpp
class Person
{
public:
    Person() = default;
    Person(const Person&) = delete;
};
```

这样就不能写：

```cpp
Person p1;
Person p2 = p1; // 错
```

### 禁止赋值

```cpp
class Person
{
public:
    Person() = default;
    Person& operator=(const Person&) = delete;
};
```

这样就不能写：

```cpp
Person p1;
Person p2;
p2 = p1; // 错
```

### 常见写法

```cpp
class Person
{
public:
    Person() = default;
    Person(const Person&) = delete;
    Person& operator=(const Person&) = delete;
};
```

表示这个类可以创建对象，但不能拷贝和赋值。

---

## 9. emplace / emplace_back

### 作用

`emplace` 系列函数可以直接在容器内部构造对象。

### vector 的 emplace_back

```cpp
vector<Person> v;

v.emplace_back("A", 18);
```

要求 `Person` 有对应的构造函数：

```cpp
class Person
{
public:
    Person(string name, int age)
    {
    }
};
```

### push_back 对比

```cpp
v.push_back(Person("A", 18));
```

这是先创建临时对象，再放进容器。

```cpp
v.emplace_back("A", 18);
```

这是直接用参数在容器内部构造对象。

### vector 的 emplace

`emplace` 需要指定插入位置：

```cpp
v.emplace(v.begin(), "A", 18);
```

如果只是尾部插入，一般用：

```cpp
v.emplace_back("A", 18);
```

### map 的 emplace

```cpp
map<int, string> m;

m.emplace(1, "张三");
```

表示插入：

```cpp
1 -> "张三"
```

---

## 10. 智能指针

### 作用

智能指针用于管理堆区对象，减少手动 `delete`。

需要头文件：

```cpp
#include <memory>
```

### unique_ptr

`unique_ptr` 表示独占所有权。

```cpp
unique_ptr<Person> p = make_unique<Person>("A", 18);
```

对象会在 `p` 生命周期结束时自动释放。

不需要手动写：

```cpp
delete p;
```

`unique_ptr` 不能拷贝：

```cpp
unique_ptr<Person> p1 = make_unique<Person>("A", 18);

// unique_ptr<Person> p2 = p1; // 错
```

转移所有权：

```cpp
unique_ptr<Person> p1 = make_unique<Person>("A", 18);
unique_ptr<Person> p2 = move(p1);
```

此时对象所有权从 `p1` 转移到 `p2`。

### shared_ptr

`shared_ptr` 表示共享所有权。

```cpp
shared_ptr<Person> p1 = make_shared<Person>("A", 18);
shared_ptr<Person> p2 = p1;
```

`p1` 和 `p2` 指向同一个对象。

当最后一个 `shared_ptr` 被销毁时，对象才会释放。

引用计数：

```cpp
cout << p1.use_count() << endl;
```

### weak_ptr

`weak_ptr` 是弱引用，不增加引用计数。

它通常用来配合 `shared_ptr`，解决循环引用问题。

---

## 11. using 类型别名

### 作用

`using` 可以给类型起别名。

### 基本写法

```cpp
using String = string;
```

之后可以写：

```cpp
String name = "hello";
```

### STL 中使用

```cpp
using IntVector = vector<int>;

IntVector v = {1, 2, 3};
```

### 和 typedef 类似

以前写：

```cpp
typedef vector<int> IntVector;
```

现在更推荐：

```cpp
using IntVector = vector<int>;
```

---

## 12. decltype

### 作用

`decltype` 可以获取表达式的类型。

### 基本写法

```cpp
int a = 10;

decltype(a) b = 20; // b 是 int
```

### 和 auto 区别

`auto` 根据初始化值推导变量类型：

```cpp
auto x = a;
```

`decltype` 根据表达式本身获取类型：

```cpp
decltype(a) y;
```
