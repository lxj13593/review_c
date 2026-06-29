#include <iostream>

using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

struct Teacher
{
    string name;
    int age;
    Student s;
};

void init_struct()
{
    Student s1;
    s1.age = 10;
    s1.name = "李四";
    s1.score = 100;
    cout << s1.name << "　" << s1.age << " " << s1.score << endl;

    Student s2 = {"王五", 10, 90};
    cout << s2.name << "　" << s2.age << " " << s2.score << endl;
}

void struct_array()
{
    Student s[3] = {
        {"李四", 30, 90},
        {"王五", 20, 50},
        {"赵六", 21, 55}};
    for (int i = 0; i < 3; i++)
    {
        cout << s[i].name << " " << s[i].age << " " << s[i].score << endl;
    }
}

void struct_pointer()
{
    Student s1 = {"n", 20, 60};
    Student *p = &s1;
    (*p).name = 'a';
    cout << p->name << " " << p->age << " " << p->score << endl;
}

void nesting_struct()
{
    Teacher t1;
    // t1.name="老师1";
    // t1.age=18;
    // t1.s.name="学生1";
    // cout<<t1.s.name<<endl;
    Student s1;
    s1.name = "学生";
    t1.s = s1;
    cout << t1.s.name << endl;
}

void print_struct_1(Student s1)
{
    s1.age = 30;
    cout << s1.name << " " << s1.age << " " << s1.score << endl;
}

void print_struct_2(Student *s1)
{
    s1->age = 50;
    cout << s1->name << " " << s1->age << " " << s1->score << endl;
}

void struct_as_function_parameter()
{
    Student s1{"李", 20, 100};
    print_struct_1(s1);
    cout << s1.name << " " << s1.age << " " << s1.score << endl;
    print_struct_2(&s1);
    cout << s1.name << " " << s1.age << " " << s1.score << endl;
}

void print_struct_3(const Student *s1)
{
    // s1->age=15;
    cout << s1->name << " " << s1->age << " " << s1->score << endl;
}

void struct_const()
{
    Student s1{"李", 20, 100};
    print_struct_3(&s1);
}

struct Student1
{
    string name;
    int score;
};

struct Teacher1
{
    string name;
    Student1 stu[5];
};

void init_teacher1(Teacher1 *t)
{
    string s = "ABC";
    char a = 'a';
    srand((unsigned int)time(nullptr));
    for (int i = 0; i < 3; i++)
    {
        t[i].name = "老师";
        t[i].name += s[i];
        for (int j = 0; j < 5; j++)
        {
            t[i].stu[j].name = "学生";
            t[i].stu[j].name += a;
            a++;
            t[i].stu[j].score = rand() % 100;
        }
    }
}

void print(Teacher1 *t)
{
    for (int i = 0; i < 3; i++)
    {
        cout << t[i].name << " ";
        for (int j = 0; j < 5; j++)
        {
            cout << t[i].stu[j].name << " " << t[i].stu[j].score << ' ';
        }
        cout << endl;
    }
}

void case_1()
{
    Teacher1 t_array[3];
    init_teacher1(t_array);
    print(t_array);
}

struct Hero
{
    string name;
    int age;
    string sex;
};

void bubble_sort(Hero *h, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (h[j].age > h[j + 1].age)
            {
                Hero t = h[j];
                h[j] = h[j + 1];
                h[j + 1] = t;
            }
        }
    }
}

void print(Hero *h, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << h[i].name << " " << h[i].age << " " << h[i].sex << endl;
    }
    cout<<endl;
}

void case_2()
{
    Hero h[5] =
        {
            {"刘备", 23, "男"},
            {"关羽", 22, "男"},
            {"张飞", 20, "男"},
            {"赵云", 21, "男"},
            {"貂蝉", 19, "女"},
        };
    int len = sizeof(h) / sizeof(h[0]);
    print(h, len);
    bubble_sort(h, len);
    print(h, len);
}

int main()
{
    // init_struct();
    // struct_array();
    // struct_pointer();
    // nesting_struct();
    // struct_as_function_parameter();
    // struct_const();
    // case_1();
    // case_2();
    return 0;
}
