// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

int divide(std::vector<int>&a, int s, int e) 
{
    int pivot = a[e];

    int count = std::count_if(a.begin() + s, a.begin() + e, [&pivot](int x) { return x < pivot; });
    int pivotPos = s + count;

    std::swap(a[e], a[pivotPos]);

    int i = s, j = e;
    while ( i<pivotPos && j > pivotPos) {
        if (a[i] < pivot) {
            ++i;
        }

        if (a[j] > pivot) {
            --j;
            continue;
        }

        std::swap(a[i], a[j]);
        ++i; 
        --j;
    }

    return pivotPos;
}

void qsort(std::vector<int>& a, int s, int e) 
{
    if (s >= e) {
        return;
    }

    int pos = divide(a, s, e);

    qsort(a, s, pos - 1);
    qsort(a, pos + 1, e);
}

int main()
{
    std::vector<int> a{ 8, 3, 1, 7, 2, 4 };
    qsort(a, 0, a.size() - 1);
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
