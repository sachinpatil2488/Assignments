// MaxSubArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

int maxSum(int* arr, int n)
{
    //{ 2, -1, 3, -3, 6, 2, -4 };
    //{ 2,  1, 4,  1, 7, 9,  5 }

    int sum = 0, max = 0;

    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum > max) {
            max = sum;
        } else if (sum < 0) {
            sum = 0;
        }
    }

    return max;
}

int main()
{
    int arr[] = { -8, -4, 3, 3, 6, 2, -4 };
   // int arr[] = { 2, -1, 3, -3, 6, 2, -4 };
   
    std::cout << "\nmaxSum : " << maxSum(arr, sizeof(arr) / sizeof(int)) << "\n";
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
