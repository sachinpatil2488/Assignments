// FindPeak.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int findPeakByBruteForce(int *arr, int n)
{
    if (n == 0) return -99;

    if (n == 1) return arr[0];

    if (n == 2) return arr[0] > arr[1] ? arr[0] : arr[1];

    int i = 1;
    while (i < n - 1) {
        if (arr[i] >= arr[i+1] && arr[i] >= arr[i-1]) {
            return arr[i];
        }
        ++i;
    }

    return arr[0] > arr[1] ? arr[0] : arr[n - 1 ] > arr[n - 2];
}

int findPeakByOptimal(int* arr, int n)
{
    int l = 0, r = n, mid = -1;

    while (l < r) {
        mid = (l + r) / 2;
        if (mid < n-1 && arr[mid] < arr[mid + 1]) {
            l = mid + 1;
        } else
        if (mid > 0 && arr[mid] < arr[mid - 1]) {
            r = mid - 1;
        } else {
            return arr[mid];
        }
    }

    return -99;
}

int findPeak(int* arr, int n)
{
    return 
        //findPeakByBruteForce(arr, n);
        findPeakByOptimal(arr, n);
}

int main()
{
    int arr[] = { 2 };
    std::cout << "\nPeal : " << findPeak(arr, 1);

    int arr1[] = {2, 3};
    std::cout << "\nPeal : " << findPeak(arr1, 2);

    int arr2[] = { 2, 3, 1 };
    std::cout << "\nPeal : " << findPeak(arr2, 3);

    int arr3[] = { 2, 3, 4, 5, 6};
    std::cout << "\nPeal : " << findPeak(arr3, 5);

    int arr4[] = { 6, 5, 4, 3, 2 };
    std::cout << "\nPeal : " << findPeak(arr4, 5);

    int arr5[] = { 2, 6, 4, 6, 8, 5 };
    std::cout << "\nPeal : " << findPeak(arr5, 5);
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
