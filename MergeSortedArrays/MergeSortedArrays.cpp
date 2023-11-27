// MergeSortedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> & nums1, int m, vector<int> & nums2, int n) {

    for (int i = 0; i < n; ++i) {
        nums1.push_back(nums2[i]);
    }

    int i = 0, j = m;

    while (i < m) {
        if (nums1[i] > nums1[j]) {
            swap(nums1[i], nums1[j]);
        }
        ++i;
    }

    while (i < m + n) {
        if (nums1[i - 1] > nums1[i]) {
            swap(nums1[i - 1], nums1[i]);
        }
        ++i;
    }
}

int main()
{
    vector<int> n1 = {1, 3, 5, 7};
    vector<int> n2 = {2, 4, 6, 8};

    merge(n1, 4, n2, 4);
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
