// PrintEvenOddInThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <condition_variable>
#include <mutex>

using namespace std;

std::condition_variable cv_even, cv_odd;
std::mutex mutex_;

bool start = false;
int max = 50;

void printNumber(int counter, const char* str)
{
    std::unique_lock<std::mutex> _lock(mutex_);

    if (counter == 0) {
        while (counter <= max) {
            cv_even.wait(_lock, [] { return start; });

            std::cout << " " << str << " : " << counter;
            counter += 2;

            start = false;
            cv_odd.notify_all();
        }
    }
    else {
        while (counter <= max) {
            cv_odd.wait(_lock, [] { return !start; });

            std::cout << " " << str << " : " << counter;
            counter += 2;

            start = true;
            cv_even.notify_all();
        }
    }
}

int main()
{

    std::thread even(printNumber, 0, "even");
    std::thread odd(printNumber, 1, "odd");

    {
        std::unique_lock<std::mutex> _lock(mutex_);
        start = true;
        cv_even.notify_all();
    }

    even.join();
    odd.join();

    std::cout << "\n\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
