// PlatformsRequired.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

int findPlatformsRequired(float* a, float* d, int n)
{
    if (n == 0) {
        return 0;
    }

    //float arr[] = { 9.00,  9.40,  9.50, 11.00, 15.00, 18.00 };
    //float dep[] = { 9.10, 12.00, 11.20, 11.30, 19.00, 20.00 };

    int result = 1;;

    for (int i = 0; i < n; ++i) {

        int platform = 1;
        for (int j = 0; j <=i; ++j) {

            if (i!=j) {
                //any train arriving before i and leaving after i
                if (a[j] <= a[i] && d[j] >= a[i]) {
                    ++platform;
                }
            }
        }

        result = std::max(result, platform);
    }

    return result;
}

int findPlatform(float* a, float* d, int l, int r)
{
    if (l == r) return 1;

    int m = (l + r) / 2;

    findPlatform(a, d, l, m);
    findPlatform(a, d, m + 1, r);

    int count = 1;
    for (int i = l; i < r; ++i) {
        if (m != i) {
            if (a[i] <= a[m] && d[i] >= a[m]) {
                ++count;
            }
        }
    }

    return count;
    //return std::max(count, std::max(lm, rm));
}

int main()
{
    float arr[] = { 9.00,  9.40,  9.50, 11.00, 15.00, 18.00 };
    float dep[] = { 9.10, 11.10, 11.20, 11.30, 19.00, 20.00 };

    //float arr[] = { 10.00, 10.15, 10.35, 10.35, 10.45 };
    //float dep[] = { 10.34, 10.46, 10.44, 10.40, 11.00 };

    std::cout << "\n Platforms : " << findPlatform(arr, dep, 0, 6);
    std::cout << "\n Platforms : " << findPlatformsRequired(arr, dep, 6);
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
