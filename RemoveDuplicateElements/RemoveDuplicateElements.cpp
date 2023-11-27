// RemoveDuplicateElements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int  n = nums.size();
    if (n <= 2) {
        return n;
    }

    int i = 0, j = 1;
    while (j < n) {
        if (nums[i] != nums[j]) {
            if (j - i > 2) {
                for (int k = j, l = i + 2; k < n; ++l, ++k) {
                    nums[l] = nums[k];
                }
                n = n - (j - i - 2);
            }
            i = i + 2;
            j = i + 1;
        }
        else {
            ++j;
        }
    }

    return n;
}

int main()
{
    std::vector<int> nums {1,1,1,2, 2,3};
    std::cout << removeDuplicates(nums) << "\n";
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
