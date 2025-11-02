#include <iostream>
#include <string>
using namespace std;

float diviser(int a, int b)
{
    if (b == 0)
    {
        throw("imposible de diviser par 0");
    }
    return a / b;
}

int main(int argc, char const *argv[])
{
    try
    {
        std::cout << "12 / 0 = " << std::endl;
        std::cout<<diviser(12,0) << std::endl;
    }
    catch(const char* msg)
    {
        std::cerr <<msg<< '\n';
    }
    return 0;
}
