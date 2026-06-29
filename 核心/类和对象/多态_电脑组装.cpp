#include<iostream>
using namespace std;

class Cpu
{
public:
    virtual void work()=0;
    virtual ~Cpu() {}
};

class GraphicsCard
{
public:
    virtual void work()=0;
    virtual ~GraphicsCard() {}
};

class MemoryModule
{
public:
    virtual void work()=0;
    virtual ~MemoryModule() {}
};

class IntelMemoryModule:public MemoryModule
{
public:
    void work() override
    {
        cout<<"英特尔内存条工作"<<endl;
    }
};

class LenovoMemoryModule:public MemoryModule
{
public:
    void work() override
    {
        cout<<"联想内存条工作"<<endl;
    }
};

class IntelGraphicsCard:public GraphicsCard
{
public:
    void work() override
    {
        cout<<"英特尔显卡工作"<<endl;
    }
};

class LenovoGraphicsCard:public GraphicsCard
{
public:
    void work() override
    {
        cout<<"联想显卡工作"<<endl;
    }
};

class LenovoCpu:public Cpu
{
public:
    void work() override
    {
        cout<<"联想CPU工作"<<endl;
    }
};

class IntelCpu:public Cpu
{
public:
    void work() override
    {
        cout<<"英特尔CPU工作"<<endl;
    }
};

class Computer
{
public:
    Computer(Cpu *c,GraphicsCard *g,MemoryModule *m):cpu(c),g_card(g),m_m(m)
    {

    } 
    ~Computer()
    {
        if(cpu!=nullptr)
        {
            delete cpu;
            cpu=nullptr;
        }
        if(g_card!=nullptr)
        {
            delete g_card;
            g_card=nullptr;
        }
        if(m_m!=nullptr)
        {
            delete m_m;
            m_m=nullptr;
        }
    }
    void work()
    {
        cpu->work();
        g_card->work();
        m_m->work();
    }
private:
    Cpu *cpu;
    GraphicsCard *g_card;
    MemoryModule *m_m;

};

void test_1()
{
    Computer *p=new Computer(new IntelCpu(),new IntelGraphicsCard(),new IntelMemoryModule());
    p->work();
    delete p;

    p=new Computer(new LenovoCpu,new LenovoGraphicsCard,new LenovoMemoryModule);
    p->work();
    delete p;

    p=new Computer(new IntelCpu,new IntelGraphicsCard,new LenovoMemoryModule);
    p->work();
    delete p;
}

int main()
{
    test_1();
    return 0;
}
