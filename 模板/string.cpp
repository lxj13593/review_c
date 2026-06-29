#include <iostream>
#include <string>

using namespace std;


// 演示 string 的几种初始化方式
void string_constructor()
{
    cout << "----------string构造函数----------" << endl;

    string s1 = "hello";
    string s2;
    s2 = 's';
    string s3(s2);
    string s4("c");

    cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
}


// 演示 string 的赋值操作
void string_assign()
{
    cout << "----------string赋值操作----------" << endl;

    string s1 = "hello";
    string s2;
    s2 = s1;
    string s3, s4;
    s3 = "c";

    cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
}


// 演示 string 的拼接操作
void string_append()
{
    cout << "----------string拼接操作----------" << endl;

    string s1 = "sss";
    string s = "sss_a";
    s1 += s;

    cout << s1 << endl;
}


// 演示 string 的查找和替换操作
void string_find_replace()
{
    cout << "----------string查找和替换----------" << endl;

    string s = "asafecfg";
    cout << s.find("cf") << endl;
    s.replace(0, 3, "222");

    cout << s << endl;
}


// 演示 string 的字符串比较操作
void string_compare()
{
    cout << "----------string字符串比较----------" << endl;

    string s1 = "abcd";
    string s2 = "abcde";

    cout << s1.compare(s2) << endl;
}


// 演示 string 按下标访问字符的两种方式
void string_access()
{
    cout << "----------string数据存取----------" << endl;

    string s1 = "abcde";

    cout << s1.at(0) << " " << s1[3] << endl;
}


// 演示 string 的插入和删除操作
void string_insert_erase()
{
    cout << "----------string插入和删除----------" << endl;

    string s1 = "abcde";
    s1.insert(2, "abd");
    cout << s1 << endl;

    s1.erase(2, 3);
    cout << s1 << endl;
}


// 演示 string 截取子串的操作
void string_substr()
{
    cout << "----------string截取子串----------" << endl;

    string s1 = "abcde";
    string s2 = s1.substr(2, 3);

    cout << s2 << endl;
}


// 程序入口，依次调用各个 string 示例函数
int main()
{
    string_constructor();
    string_assign();
    string_append();
    string_find_replace();
    string_compare();
    string_access();
    string_insert_erase();
    string_substr();
    return 0;
}
