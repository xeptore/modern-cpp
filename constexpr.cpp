#include <iostream>
#include <memory>
#include <chrono>

using namespace std;
using namespace std::chrono;

constexpr long int fibExp(int n)
{
    return (n <= 1) ? n : fibExp(n - 1) + fibExp(n - 2);
}

long int fib(int n)
{
    return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
}

class FiboFactoryExp
{
public:
    constexpr FiboFactoryExp(const int p) : _fibo(fibExp(p)) {}

    constexpr auto getFiboResult() const { return _fibo; }

private:
    long int _fibo;
};

class FiboFactory
{
public:
    FiboFactory(const int p) : _fibo(fib(p)) {}

    auto getFiboResult() const { return _fibo; }

private:
    long int _fibo;
};

int main()
{
    auto t1 = high_resolution_clock::now();
    FiboFactoryExp instance(30);
    // FiboFactory instance(30);
    const auto result = instance.getFiboResult();
    auto t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(t2 - t1).count();

    cout << "duration (ms):    " << duration << endl
         << "result:           " << result << endl;
    return 0;
}
