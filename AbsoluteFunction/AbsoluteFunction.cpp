// Assignments.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

using namespace std;
/*
    Find (i,j) for max (| a[i] - a[j] | + | i - j |)

    | a[i] - a[j] | + | i - j |
    =>   a[i] - a[j]  + ( i - j ) => (a[i] + i) - (a[j] + j)
         a[j] - a[i]  + ( i - j ) => (a[j] - j) - (a[i] - i)
*/

void efficient(int* arr, int size)
{
    int maxi = -999, mxi = -1, mini = 999, mni = -1;
    for (int i = 0; i < size; ++i) {
        int temp = arr[i] + i;
        if (maxi < temp) {
            maxi = temp;
            mxi = i;
        }

        if (mini > temp) {
            mini = temp;
            mni = i;
        }
    }

    int c1 = maxi - mini;

    int maxj = -999, mxj = -1, minj = 999, mnj = -1;
    for (int j = 0; j < size; ++j) {
        int temp = arr[j] - j;
        if (maxj < temp) {
            maxj = temp;
            mxj = j;
        }

        if (minj > temp) {
            minj = temp;
            mnj = j;
        }
    }

    int c2 = maxj - minj;

    if (c1 > c2) {
        std::cout << "\n efficient : i= " << mxi << ", j= " << mni;
    }
    else {
        std::cout << "\n efficient : i= " << mxj << ", j= " << mnj;
    }

}

void bruteForce(int* arr, int size)
{
    int ii = 0, jj = 0, max = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int temp = std::max(arr[i] - arr[j], arr[j] - arr[i]) + i - j;
            if (temp > max) {
                max = temp;
                ii = i;
                jj = j;
            }
        }
    }

    std::cout << "\n bruteForce : i= " << ii << ", j= " << jj;
}

int main()
{
    int arr[] = { -3,8,9,1,0,-5,7,1,3 };

    bruteForce(arr, 9);

    efficient(arr, 9);
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
