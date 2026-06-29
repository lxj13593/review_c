#include <iostream>
using namespace std;

class Person
{
private:
    int age;
    int score;
    int *height;

public:
    Person() : age(0), score(0), height(nullptr)
    {
    }
    Person(int age, int score, int height) : age(age), score(score)
    {
        this->height = new int(height);
    }
    ~Person()
    {
        if (height != nullptr)
        {
            delete height;
            height = nullptr;
        }
    }
    Person(const Person &p)
    {
        age = p.age;
        score = p.score;
        if (p.height != nullptr)
        {
            height = new int(*p.height);
        }
        else
        {
            height = nullptr;
        }
    }
    int getAge() const
    {
        return age;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    int getScore() const
    {
        return score;
    }
    void setScore(int score)
    {
        this->score = score;
    }
    int getHeight() const
    {
        if (height == nullptr)
        {
            return 0;
        }
        return *height;
    }
    void setHeight(int height)
    {
        if (this->height != nullptr)
        {
            delete this->height;
            this->height = nullptr;
        }
        this->height = new int(height);
    }
    // 加号运算符重载(类内)
    Person operator+(const Person &p1)
    {
        Person temp;
        temp.age = this->age + p1.age;
        return temp;
    }
    // 前置++运算符重载
    Person &operator++()
    {
        age++;
        return *this;
    }
    // 后置++运算符重载
    Person operator++(int)
    {
        Person temp = *this;
        age++;
        return temp;
    }
    // 赋值运算符重载
    Person &operator=(const Person &p)
    {
        if (this == &p)
        {
            return *this;
        }
        if (height != nullptr)
        {
            delete height;
            height = nullptr;
        }
        age = p.age;
        score = p.score;
        if (p.height != nullptr)
        {
            height = new int(*p.height);
        }
        else
        {
            height = nullptr;
        }
        return *this;
    }
};
// 比较运算符重载
bool operator==(const Person &p1, const Person &p2)
{
    if (p1.getAge() == p2.getAge() && p1.getScore() == p2.getScore() && p1.getHeight() == p2.getHeight())
    {
        return true;
    }
    return false;
}

// 左移运算符重载
ostream &operator<<(ostream &out, const Person &p)
{
    out << p.getAge() << " " << p.getScore() << " " << p.getHeight() << endl;
    return out;
}

// 加号运算符重载
Person operator+(const Person &p1, const Person &p2)
{
    Person temp;
    temp.setAge(p1.getAge() + p2.getAge());
    return temp;
}

void test_1()
{
    Person p1(10, 100, 20);
    Person p2(20, 101, 20);
    Person p3 = p1 + p2;
    cout << p1 << p2 << p3;
}

void test_2()
{
    Person p1(10, 100, 20);
    Person p2(20, 101, 20);
    cout << p1++;
    cout << p1;
    cout << ++p2;
    cout << p2;
}

void test_3()
{
    Person p1(10, 100, 20);
    Person p2(20, 101, 20);
    p1 = p2;
    cout << p1 << p2;
}

void test_4()
{
    Person p1(10, 100, 20);
    Person p2(10, 100, 20);
    cout<<(p1==p2);
}

int main()
{
    // test_1();
    // test_2();
    // test_3();
    test_4();
    return 0;
}