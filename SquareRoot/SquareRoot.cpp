// SquareRoot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

using namespace std;

int bruteForce(int n)
{
    //O(n)

    if (n == 0 || n == 1) return n;

    int i = 1;
    while (i * i <= n) {
        ++i;
    }

    return i - 1;
}

int efficient(int n)
{
    if (n == 0 || n == 1) return n;

    int s = 1, e = n/2, r = 0;

    while (s <= e) {
        int mid = (s + e) / 2;
        int sqr = mid * mid;

        if (sqr < n) {
            s = mid + 1;
            r = mid; //floor value
        } else if (sqr > n) {
            e = mid - 1;
        } else {
            return mid;
        }
    }

    return r;
}

int squareRoot(int n) 
{
    return
        //bruteForce(n);
        efficient(n);
}

int main()
{
    for (int i = 0; i< 26; ++i) {
        std::cout << "\n" << i << " : " << squareRoot(i);
    }
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
