// WaterTappingProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

using namespace std;

/*
Tapping rain water

@
@  @ @
@ @@ @ @@@
0123456789
3012020111

Brute force solution : (n ^ 2)
*/
void bruteForce(int* arr, int N)
{
    int water = 0;
    for (int i = 1; i < N - 1; ++i)
    {
        int maxLeft = arr[i];
        for (int j = i; j >= 0; --j) {
            maxLeft = std::max(maxLeft, arr[j]);
        }

        int maxRight = arr[i];
        for (int j = i + 1; j < N; ++j) {
            maxRight = std::max(maxRight, arr[j]);
        }

        water += std::min(maxLeft, maxRight) - arr[i];
    }

    std::cout << "\n BruteForce : Tapped water size : " << water;
}


//Optimised: O(n)
void efficient(int* arr, const int N)
{
    //3012020111
    int* left = new int[N];
    left[0] = arr[0];
    for (int i = 1; i < N; ++i) {
        left[i] = std::max(left[i - 1], arr[i]);
    }
    //3333333333

    int* right = new int[N];
    right[N - 1] = arr[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        right[i] = std::max(right[i + 1], arr[i]);
    }
    //3222221111

    //3 0 1 2 0 2 0 1 1 1
    //3 3 3 3 3 3 3 3 3 3
    //3 2 2 2 2 2 1 1 1 1
    //0+2+1+0+2+0+1+0+0+0 

    int water = 0;
    for (int i = 1; i < N - 1; ++i) {
        water += std::min(left[i], right[i]) - arr[i];
    }

    std::cout << "\n Efficient : Tapped water size : " << water;
}

int main()
{
    int arr[] = { 3,0,1,2,0,2,0,1,1,1 };
    bruteForce(arr, 10);
    efficient(arr, 10);
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
