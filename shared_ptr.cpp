#include <memory>
#include <iostream>

using namespace std;

class Test
{
public:
    Test(int a) : _a(a) {}
    ~Test()
    {
        cout << "Destructing Test instance" << endl;
    }

    int getA() const noexcept { return _a; }

private:
    int _a;
};

int main()
{
    auto shtr = make_shared<Test>(5);
    cout << shtr.use_count() << " " << shtr.unique() << endl;

    auto shtr2 = shtr;
    cout << "shtr use_cout: " << shtr.use_count() << " " << shtr.unique() << endl;
    cout << "shtr2 use_cout: " << shtr2.use_count() << endl;

    auto shtr3 = shtr;
    cout << "shtr use_cout: " << shtr.use_count() << endl;
    cout << "shtr2 use_cout: " << shtr2.use_count() << endl;
    cout << "shtr3 use_cout: " << shtr3.use_count() << endl;

    cout << "Resetting..." << endl;
    shtr.reset();

    shtr2.reset();
    shtr3.reset();
    cout << "shtr use_cout: " << shtr.use_count() << endl;
    cout << "shtr2 use_cout: " << shtr2.use_count() << endl;
    cout << "shtr3 use_cout: " << shtr3.use_count() << endl;


    cout << "shtr " << (shtr ? "not null" : "null") << " " << (shtr ? (*shtr).getA() : false) << endl;
    cout << "shtr2 " << (shtr2 ? "not null" : "null") << " " << (shtr2 ? (*shtr2).getA() : false) << endl;
    cout << "shtr3 " << (shtr3 ? "not null" : "null") << " " << (shtr3 ? (*shtr3).getA() : false) << endl;
}
