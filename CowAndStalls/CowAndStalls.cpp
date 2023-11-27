// CowAndStalls.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

using namespace std;

bool isPossible(int* a, int n, int k, int c) 
{
    //a={ 1 3 4 6 8 }, n=5
    //c=2
    //k=

    int gap = a[0] + k, count = 1;

    for (int i = 1; i<n; ++i) {

        if (gap <= a[i]) {
            count++; //knot cow

            if (count == c) {
                break;
            }

            gap = a[i] + k;
        }
    }

    return count == c;
}

int findMaxDistance(int*a, int n, int c)
{
    if (n < c) return 0;

    //Mininmum distance always between smallest distance between two stalls
    //and mxumun distance if number of cows=2

    int minD = 999, maxD = a[n-1] - a[0];
    for (int i = 1; i < n; ++i) {
        minD = min(a[i] - a[i - 1], minD);
    }

    int result = 0;

    while (minD <= maxD) {
        int k = (minD + maxD) / 2;
        if (isPossible(a, n, k, c)) {
            minD = k + 1;
            result = max(k, result);
        } else {
            maxD = k - 1;
        }
    }
}

int main()
{
    //int a[] { 1, 2, 3, 4, 5 }, n = 5, k = 2;
    //int a[]{ 1, 2, 4, 8, 9 }, n = 5, k = 3;
    int a[] = { 6, 7,  9, 11, 13, 15 }, n = 6, k = 4;
    std::cout << "Min distance : " << findMaxDistance(a, n, k);
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
