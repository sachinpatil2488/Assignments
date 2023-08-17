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
void bruteForce(std::array<int, 10> arr)
{
    std::sort(arr.begin(), arr.end());

    int max = -1;

    for (int i = 1; i < arr.size(); ++i) {
        max = std::max(max, arr[i] - arr[i - 1]);
    }

    std::cout << "\n BruteForce : diff : " << max;
}


//Optimised: O(n)
void efficient(std::array<int, 10> arr)
{
    int max = -1;
    std::cout << "\n Efficient : diff : " << max;
}

int main()
{
    array<int,10> arr= { -9,0,1,18,6,2,-3,4,5,3 };
    //-9,-3,0,1,2,3,4,5,6,18
    bruteForce(arr);
    efficient(arr);
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
