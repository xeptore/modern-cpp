#include <vector>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

void foo(bool param, int id)
{
    if (!param)
    {
        return;
    }

    cout << "start working thread (" << id << ")" << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout << "finish working thread (" << id << ")" << endl;
}

int main()
{
    vector<thread> threadsVector;
    // threadsVector.emplace_back([]() {
    //     // Lambda function that will be invoked
    // });

    auto t = thread(foo, true, 5);
    cout << t.get_id() << endl;
    terminate();

    threadsVector.emplace_back(foo, true, 1); // thread will run foo(true, 1)
    threadsVector.emplace_back(foo, true, 2); // thread will run foo(true, 2)
    for (auto &thread : threadsVector)
    {
        thread.join(); // Wait for threads to finish
    }
}