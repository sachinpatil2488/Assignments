// ProductOfArrayElements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        /*
        std::vector<int> preProduct;
        preProduct.reserve(nums.size());

        auto product = 1;
        for (auto n : nums) {
            product = n * product;
            preProduct.push_back(product);
        }

        std::vector<int> postProduct;
        postProduct.reserve(nums.size());

        product = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            product = nums[i] * product;
            postProduct[i] = product;
        }

        vector<int> result;
        result.reserve(nums.size());

        for (auto k = 0; k < nums.size(); ++k) {
            int p1 = 1;
            if (k-1 >= 0) {
                p1 = preProduct[k-1];
            }

            int p2 = 1;
            if (k+1 < nums.size()) {
                p2 = postProduct[k+1];
            }

            result.emplace_back(p1 * p2);
        }
        */

        vector<int> result;
        result.resize(nums.size());

        result[0] = 1;

        for (int i = 1; i < nums.size(); ++i) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int right = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            result[i] *= right;
            right *= nums[i];
        }

        return result;
    }
};

int main()
{
    vector<int> nums = { 1,2,3,4 };
    Solution().productExceptSelf(nums);

    std::cout << "Hello World!\n";
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
