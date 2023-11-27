// Jump-I.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

bool reached(vector<int>& nums, int n, int i)
{
    if (i == n)
        return true;

    if (i > n || nums[i] == 0)
        return false;

    int s = nums[i];
    for (int j = 1; j <= s; ++j)
        if (reached(nums, n, i + j))
            return true;

    return false;
}

bool canJump(vector<int>& nums) {

    int n = nums.size() - 1;
    return reached(nums, n, 0);
}

int main()
{
    std::vector<int> nums{ 3,2,1,0,4 };
    std::cout << canJump(nums);
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
