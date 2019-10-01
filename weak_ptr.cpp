#include <memory>
#include <iostream>

using namespace std;

class Person
{
public:
    Person(int const &age) : _age{age} {}
    Person() : Person(45) {}
    Person(Person const &) = delete;
    Person &operator=(Person const &other) = delete;
    ~Person()
    {
        cout << "Destructor is calling..." << endl;
    }

private:
    int _age;
};

int main()
{
    auto sp1 = make_shared<Person>();
    auto sp2(sp1);
    auto wptr = weak_ptr<Person>(sp1);

    cout << "sp1 use_count " << sp1.use_count() << endl;
    cout << "sp2 use_count " << sp2.use_count() << endl;
    cout << "weak_ptr expired " << wptr.expired() << endl;

    sp1.reset();

    cout << "sp1 use_count " << sp1.use_count() << endl;
    cout << "sp2 use_count " << sp2.use_count() << endl;
    cout << "weak_ptr expired " << wptr.expired() << endl;

    if (!wptr.expired())
    {
        sp1 = wptr.lock();
    }

    sp2.reset();

    cout << "sp1 use_count " << sp1.use_count() << endl;
    cout << "sp2 use_count " << sp2.use_count() << endl;
    cout << "weak_ptr expired " << wptr.expired() << endl;

    sp1.reset();

    cout << "sp1 use_count " << sp1.use_count() << endl;
    cout << "sp2 use_count " << sp2.use_count() << endl;
    cout << "weak_ptr expired " << wptr.expired() << endl;
}
