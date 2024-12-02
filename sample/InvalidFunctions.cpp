
#include <vector>
#include <string>

int errorFunc1()
{
    // 空指针异常
    int* p = nullptr;
    *p = 0;
    return 0;
}

int errorFunc2()
{
    // 除零异常
    int a = 0;
    int b = 1 / a;
    return b;
}

int errorFunc3()
{
    // 重复释放异常
    int* p = new int;
    delete p;
    delete p;
    return 0;
}

int errorFunc4()
{
    // vector 越界
    std::vector<int> v;
    v[0] = 0;
    return 0;
}


int errorFunc5()
{
    // 非法访问迭代器
    std::vector<int> v = {1, 2, 3};
    auto it = v.end();
    return *it;
}

int errorFunc6()
{
    // 未知异常
    throw std::exception("unknown error");
    return 0;
}

int errorFunc7()
{
    // 非法访问 string
    std::string str = "hello";
    return str[10];
}
