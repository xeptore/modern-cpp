#include <iostream>

using namespace std;

class T
{
    private:
    int _a;
    public:
    T(int a) : _a(a) { cout << "ctor is calling with " << a << endl; }
    ~T() { cout << "dtor" << _a << " is calling" << endl; }
};

void doALot(T& t)
{
    int a = 4;
    return;
}

int main()
{
    std::cout << "You can compile and run examples in other files. Good Luck!" << std::endl;

    T t1 {4};
    doALot(t1);
}
