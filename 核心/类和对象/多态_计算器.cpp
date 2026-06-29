#include <iostream>
using namespace std;

class Calculator
{
private:
    int x;
    int y;

public:
    Calculator()
    {
    }
    Calculator(int x, int y) : x(x), y(y)
    {
    }
    inline int get_x() const { return x; }
    inline int get_y() const { return y; }

    void set_x(const int &x)
    {
        this->x = x;
    }
    void set_y(const int &y)
    {
        this->y = y;
    }
    double add()
    {
        return x+y;
    }
    double substract()
    {
        return x-y;
    }
    double multiply()
    {
        return x*y;
    }
    double division()
    {
        if(y==0)
        {
            return -99999;
        }
        return (1.0*x)/(1.0*y);
    }
};

void test_1()
{
    Calculator c1;
    c1.set_x(5);
    c1.set_y(6);
    cout<<c1.add()<<endl;
    cout<<c1.division()<<endl;
    cout<<c1.multiply()<<endl;
    cout<<c1.substract()<<endl;
}

class AbstractCalculator
{
public:
    int x;
    int y;
public:
    virtual int get_result()
    {
        return 0;
    }
};

class AddCalculator:public AbstractCalculator
{
public:
    int get_result()
    {
        return x+y;
    }
};

class SubtractCalculator:public AbstractCalculator
{
public:
    int get_result() override
    {
        return x-y;
    }
};

class MultiplyCalculator:public AbstractCalculator
{
public:
    int get_result()
    {
        return x*y;
    }
};

void test_2()
{
    AbstractCalculator *a=new AddCalculator();
    a->x=10;
    a->y=20;
    cout<<a->get_result()<<endl;
    
    AbstractCalculator *b=new SubtractCalculator();
    b->x=10;
    b->y=20;
    cout<<b->get_result()<<endl;

    AbstractCalculator *c=new MultiplyCalculator();
    c->x=10;
    c->y=20;
    cout<<c->get_result()<<endl;
}

int main()
{
    // test_1();
    test_2();
    return 0;
}
