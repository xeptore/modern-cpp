#include <future>
#include <chrono>
#include <cmath>
#include <iostream>

using namespace std;

int foo(const int base, const int exp)
{
    const auto result = pow(base, exp);

    this_thread::sleep_for(chrono::seconds(5));

    cout << "sending result..." << endl;
    return result;
}

int main()
{
    auto handler = async(launch::async, foo, 4, 2);

    // handler.wait();

    cout << "hello after" << endl;

}
