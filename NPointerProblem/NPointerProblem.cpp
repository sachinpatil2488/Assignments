// NPointerProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMin(int*a, int an, int*b, int bn, int*c, int cn)
{
    //min = max(a,b,c) - min(a,b,c)

    int i = 0, j = 0, k = 0, result = INT32_MAX;

    while (i < an && j < bn && k < cn) {

        int min_ = std::min(std::min(a[i], b[j]), c[k]);
        int max_ = std::max(std::max(a[i], b[j]), c[k]);

        result = min(result, max_ - min_);

        if (min_ == a[i]) {
            ++i;
        } else if (min_ == b[j]) {
            ++j;
        } else {
            ++k;
        }
    }

    return result;
}

int findMax(int* a, int an, int* b, int bn, int* c, int cn)
{
    int max_ = std::max(std::max(a[an - 1], b[bn - 1]), c[cn - 1]);
    int min_ = std::min(std::min(a[0], b[0]), c[0]);
    return max_ - min_;
}

int main()
{
    int a[]{ 2, 4, 5, 6, 8, 12 }, an = 6;
    int b[]{ 5, 8, 10, 18 }, bn = 4;
    int c[]{ 1, 3, 12 }, cn = 3;

    std::cout << "\nmin : " << findMin(a, an, b, bn, c, cn);
    std::cout << "\nmax : " << findMax(a, an, b, bn, c, cn);
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
