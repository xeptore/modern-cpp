#include <memory>
#include <iostream>

using namespace std;

int main()
{
    auto uptr = make_unique<int>(10);
    const auto uptr2 = std::move(uptr);

    cout << "uptr " << (uptr ? "exists" : "not exists") << (uptr ? *uptr : 0) << endl;
    cout << "uptr2 " << (uptr2 ? "exists" : "not exists") << (uptr2 ? *uptr2 : 0) << endl;
}
