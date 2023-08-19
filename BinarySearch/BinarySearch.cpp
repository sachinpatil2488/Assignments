// WaterTappingProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

/*
Max diff in elements if array is sorted

Brute force solution :NlogN
*/
void bruteForce(std::array<int, 10> arr, int e)
{
    if (arr.empty()) {
        //empty list
        return;
    }

    int l = 0, r = arr.size();
    int mid = -1;

    //{1,2,3,4,5,6,7,8,9}

    bool found = false;
    while (l <= r) {
        mid = (l + r) / 2;
        if (arr.at(mid) < e) {
            l = mid + 1;
        }
        else if (arr.at(mid) > e) {
            r = mid - 1;
        }
        else {
            found = true;
            break;
        }
    }

    std::cout << "\n BruteForce : found : " << found;
    if (found) {
        std::cout << ", pos : " << mid;
    }
}


void recurstBS(std::array<int, 10> arr, int e, int l, int r)
{
    if (l > r) {
        return;
    }

    int mid = (l + r) / 2;
    if (arr.at(mid) < e) {
        recurstBS(arr, e, mid + 1, r);
    }
    else if (arr.at(mid) > e) {
        recurstBS(arr, e, l, mid - 1);
    }
    else {
        std::cout << "\n Optimal : found  at pos : " << mid;
    }
}

//Optimised: O(n)
void efficient(std::array<int, 10> arr, int e)
{
    recurstBS(arr, e, 0, arr.size());
}

int main()
{
    array<int, 10> arr = { -9,0,1,18,6,2,-3,4,5,3 };
    std::sort(arr.begin(), arr.end());

    bruteForce(arr, -3);
    efficient(arr, -3);
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
