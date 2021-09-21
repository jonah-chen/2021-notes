#include <iostream>
bool f(bool a, bool b, bool c, bool d)
{
    return !b && (a && !c || !a && d) || a && (b && !c || !b && d);
}
bool g(bool a, bool b, bool c, bool d)
{
    return !b && d || a && !c;
}
int main(int argc, char* argv[])
{
    for (int i = 0; i < 16; ++i)
    {
        bool a = (bool)(i & 1);
        bool b = (bool)((i>>1) & 1);
        bool c = (bool)((i>>2) & 1);
        bool d = (bool)((i>>3) & 1);
        std::cout << a << b<< c<<d<<" " << f(a,b,c,d) << g(a,b,c,d) << std::endl;
    }
}