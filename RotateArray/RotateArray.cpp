// RotateArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    /*int temp = nums[k % n];
        int i = 0;
        for (i = 0; i < n; ++k) {
            nums[(i + k) % n] = nums[i];
        }
        --k;
    }*/

    //int temp = nums[0];
    for (int i = 0; i < n-1; ++i) {
        std::swap(nums[(k + i) % n], nums[i]);
    }
}

int main()
{

    std::vector<int> nums{ 1, 2, 3, 4 };
    int k = 2;
    rotate(nums, k);
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
