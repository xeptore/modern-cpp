#include <iostream>
#include <tuple>

using namespace std;

int main()
{
    auto t = make_tuple<string, int, float>("Mamad", 78, 12.5);
    auto [igonre, grade, height] = t;

    cout << "name: " << "<name was ignored>" << endl
         << "grade: " << grade << endl
         << "height: " << height << endl;
}
