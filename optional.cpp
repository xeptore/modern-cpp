#include <optional>
#include <iostream>

using namespace std;

optional<int> doSomething(int a)
{
    if (a > 10)
    {
        return a * 2;
    }

    return {};
}

int main()
{
    const auto res1 = doSomething(5);
    const auto res2 = doSomething(20);

    cout << "res 1: " << res1.value_or(0) << endl << "res 2: " << res2.value_or(0) << endl;
}
