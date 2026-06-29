#include <iostream>
#include<cmath>

using namespace std;

const double pai=3.1415926;

class Circle
{
private:
    int ridus;

public:
    Circle(int r):ridus(r)
    {

    }
    Circle():ridus(0)
    {

    }
    void setRadius(int r)
    {
        this->ridus = r;
    }
    int getRadius() const
    {
        return this->ridus;
    }
    double calculate_perimeter() const
    {
        return 2*pai*ridus;
    }
};

void test_1()
{
    Circle c1(2);
    cout<<c1.calculate_perimeter();
}

class Student
{
private:
    string name;
    int number;
public:
    Student(string name,int number):name(name),number(number)
    {

    }
    void setName(string name)
    {
        this->name=name;
    }
    string getName() const
    {
        return this->name;
    }
    void setNumber(int number)
    {
        this->number=number;
    }
    int getNumber() const
    {
        return this->number;
    }
    void print() const
    {
        cout<<this->name<<" "<<this->number<<endl;
    }
};

void test_2()
{
    Student s1("li",156324);
    s1.setName("s");
    s1.print();
}

class Cube
{
private:
    int length;
    int width;
    int height;
public:
    Cube(int l,int w,int h):length(l),width(w),height(h)
    {

    }
    Cube()
    {

    }
    void setLength(int l)
    {
        this->length=l;
    }
    void setWidth(int w)
    {
        this->width=w;
    }
    void setHeight(int h)
    {
        this->height=h;
    }
    int getLength()
    {
        return this->length;
    }
    int getWidth()
    {
        return this->width;
    }
    int getHeight()
    {
        return this->height;
    }
    double get_surface_area()
    {
        return 2.0*(height*length+height*width+width*length);
    }
    double get_volume()
    {
        return height*length*width;
    }
    bool is_equal(Cube c2)
    {
        if(length==c2.length&&width==c2.width&&height==c2.height)
        {
            return true;
        }
        return false;
    }
};

bool is_equal(Cube c1,Cube c2)
{
    if(c1.getHeight()==c2.getHeight()&&c1.getLength()==c2.getLength()&&c1.getWidth()==c2.getWidth())
    {
        return true;
    }
    return false;
}

void test_3()
{
    Cube c1(2,3,6);
    Cube c2(2,3,5);
    cout<<c1.get_surface_area()<<endl;
    cout<<c1.get_volume()<<endl;
    cout<<c1.is_equal(c2)<<endl;
    cout<<is_equal(c1,c2)<<endl;
}

class Point
{
private:
    double x;
    double y;
public:
    Point()
    {

    }
    Point(double x, double y):x(x),y(y)
    {

    }
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    void setX(double x)
    {
        this->x = x;
    }
    void setY(double y)
    {
        this->y = y;
    }
};

class Circle1
{
private:
    Point point;
    int radius;
public:
    Circle1()
    {

    }
    Circle1(Point p,int r):point(p),radius(r)
    {

    }
    Point getPoint()
    {
        return point;
    }
    void setPoint(Point p)
    {
        this->point=p;
    }
    int getRadius()
    {
        return radius;
    }
    void setRadius(int r)
    {
        this->radius=r;
    }
};

double two_point_distance(Point p1,Point p2)
{
    double distance=sqrt(1.0*(p1.getX()-p2.getX())*(p1.getX()-p2.getX())+1.0*(p1.getY()-p2.getY())*(p1.getY()-p2.getY()));
    return distance;
}

void circle1_distance_point(Circle1 c,Point p)
{
    double distance=two_point_distance(c.getPoint(),p);
    if(distance>c.getRadius())
    {
        cout<<"点在圆外"<<endl;
    }
    else if(distance<c.getRadius())
    {
        cout<<"点在圆内"<<endl;
    }
    else
    {
        cout<<"点在圆上"<<endl;
    }
}

void test_4()
{
    Point p1(0,0);
    Point p2(sqrt(2),sqrt(2));
    Circle1  c1(p1,2);
    circle1_distance_point(c1,p2);
}

int main()
{
    // test_1();
    // test_2();
    // test_3();
    // test_4();
    return 0;
}