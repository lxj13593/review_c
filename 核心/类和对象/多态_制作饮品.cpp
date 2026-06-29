#include <iostream>
using namespace std;

class MakeDrink
{
public:
    virtual void boil_water() = 0;
    virtual void brew() = 0;
    virtual void pour_into_cup() = 0;
    virtual void add_ingredients() = 0;
    void work()
    {
        boil_water();
        brew();
        pour_into_cup();
        add_ingredients();
    }
    virtual ~MakeDrink() {}
};

class MakeCoffee : public MakeDrink
{
public:
    void boil_water() override
    {
        cout << "煮水" << endl;
    }
    void brew() override
    {
        cout << "冲泡咖啡" << endl;
    }
    void pour_into_cup() override
    {
        cout << "倒入杯中" << endl;
    }
    void add_ingredients() override
    { 
        cout << "加糖和牛奶" << endl;
    }
};

class MakeTea : public MakeDrink
{
public:
    void boil_water() override
    {
        cout << "煮水" << endl;
    }
    void brew() override
    {
        cout << "冲泡茶叶" << endl;
    }
    void pour_into_cup() override
    {
        cout << "倒入杯中" << endl;
    }
    void add_ingredients() override
    { 
        cout << "加柠檬" << endl;
    }
};

void do_work(MakeDrink &m)
{
    m.work();
}

void do_work1(MakeDrink *m)
{
    m->work();
    delete m;
}

void test_1()
{
    MakeCoffee mc;
    MakeTea mt;
    do_work(mc);
    do_work(mt);
    do_work1(new MakeCoffee);
    do_work1(new MakeTea);
}

int main()
{
    test_1();
    return 0;
}
