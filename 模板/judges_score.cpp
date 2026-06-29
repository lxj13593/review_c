#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include<algorithm>
#include <numeric>
#include <ctime>

using namespace std;

class Person
{
public:
    inline string get_name() const { return name; }
    inline double get_score() const { return score; }

    void set_name(const string &name)
    {
        this->name = name;
    }

    void set_score(double score)
    {
        this->score = score;
    }

    Person(string name, double score = 0) : name(name), score(score)
    {

    }
    void show()
    {
        cout<<name<<" "<<score<<endl;
    }
private:
    string name;
    double score;
};


void make_score(vector<Person> &p)
{
    srand(time(nullptr));
    for (int i = 0; i < p.size(); i++)
    {
        deque<double> dq;
        for(int j=0;j<10;j++)
        {
            dq.push_back(rand()%41+60);
        }
        sort(dq.begin(),dq.end());
        dq.pop_back();
        dq.pop_front();
        double total=accumulate(dq.begin(),dq.end(),0);
        double average_score=total/dq.size();
        p[i].set_score(average_score);
    }
}

void test_1()
{
    vector<Person> p;
    Person p1("A");
    Person p2("B");
    Person p3("C");
    Person p4("D");
    Person p5("E");
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    p.push_back(p5);
    make_score(p);
    for(int i=0;i<p.size();i++)
    {
        p[i].show();
    }
}

int main()
{
    test_1();
    return 0;
}
