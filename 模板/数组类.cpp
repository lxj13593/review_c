#include <iostream>
#include <string>
using namespace std;

template <class T>
class MyArray
{
public:
    MyArray(int capacity) : capacity(capacity), len(0)
    {
        t = new T[capacity];
    }
    MyArray() : capacity(0), len(0), t(nullptr)
    {
    }
    int get_len() const
    {
        return len;
    }
    int get_Capacity() const
    {
        return capacity;
    }
    MyArray(const MyArray &my_array)
    {
        len = my_array.len;
        capacity = my_array.capacity;
        if (my_array.t != nullptr)
        {
            t = new T[capacity];
            for (int i = 0; i < len; i++)
            {
                t[i] = my_array.t[i];
            }
        }
        else
        {
            t = nullptr;
        }
    }
    MyArray &operator=(const MyArray &my_array)
    {
        // 防止自己给自己赋值
        if (this == &my_array)
        {
            return *this;
        }

        // 清空自己区域
        if (t != nullptr)
        {
            delete[] t;
            t = nullptr;
        }

        len = my_array.len;
        capacity = my_array.capacity;

        // 赋值
        if (my_array.t != nullptr)
        {
            t = new T[capacity];
            for (int i = 0; i < len; i++)
            {
                t[i] = my_array.t[i];
            }
        }
        else
        {
            t = nullptr;
        }
        return *this;
    }
    void tail_insert(const T& val)
    {
        if (len >= capacity)
        {
            cout << "数组已满，无法插入" << endl;
            return;
        }
        t[len] = val;
        len++;
    }
    void tail_delete()
    {
        if (len <= 0)
        {
            cout << "数组为空，无法删除" << endl;
            return;
        }
        len--;
    }
    T& operator[](int i)
    {
        return t[i];
    }
    const T& operator[](int i) const
    {
        return t[i];
    }
    void show()
    {
        for (int i = 0; i < len; i++)
        {
            cout << t[i] << " ";
        }
        cout << endl;
    }
    ~MyArray()
    {
        if (t != nullptr)
        {
            delete[] t;
            t = nullptr;
        }
    }

private:
    int len;
    T *t;
    int capacity;
};

void test_1()
{
    MyArray<int> a(10);
    cout << a.get_Capacity() << " " << a.get_len() << endl;
    for (int i = 0; i < 8; i++)
    {
        a.tail_insert(i);
    }
    cout << a[2];
    a.tail_delete();
    a.tail_delete();
    cout << a.get_Capacity() << " " << a.get_len() << endl;
    a.show();
    cout << a.get_Capacity() << " " << a.get_len() << endl;

    MyArray<int> a1(a);
    MyArray<int> a2;
    a2 = a1;
    a1.show();
    a2.show();
}

class Person
{
public:
    Person() : name(""), age(0)
    {
    }
    Person(string name, int age) : name(name), age(age)
    {
    }
    inline string get_name() const { return name; }
    inline int get_age() const { return age; }

    void set_name(const string &name)
    {
        this->name = name;
    }
    void set_age(const int &age)
    {
        this->age = age;
    }

private:
    string name;
    int age;
};

ostream &operator<<(ostream &out, const Person &p)
{
    out << p.get_name() << " " << p.get_age();
    return out;
}

void test_2()
{
    MyArray<Person> p(10);
    cout << p.get_Capacity() << " " << p.get_len() << endl;
    Person p1("a", 20);
    Person p2("b", 30);
    Person p3("c", 40);
    Person p4("d", 50);
    Person p5("e", 60);
    p.tail_insert(p1);
    p.tail_insert(p2);
    p.tail_insert(p3);
    p.tail_insert(p4);
    p.tail_insert(p5);
    cout << p.get_Capacity() << " " << p.get_len() << endl;
    p.tail_delete();
    p.tail_delete();
    cout << p.get_Capacity() << " " << p.get_len() << endl;
    p.show();
    MyArray<Person> pp1(p);
    MyArray<Person> pp2;
    pp2 = pp1;
    pp1.show();
    pp2.show();
    cout << pp1[2];
}

int main()
{
    // test_1();
    test_2();
    return 0;
}