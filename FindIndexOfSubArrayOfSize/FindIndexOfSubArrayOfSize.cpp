// FindIndexOfSubArrayOfSize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

void findSubArry(int* a, int n, int target)
{
    int* ax = new int[target];
    for (int i = 0; i < target; ++i) { ax[i] = -1; }

    for (int i = 0; i <n; ++i) {
        if (a[i]>= target) {
            continue; //skip
        }

        int x = ax[a[i]];
        if (x == -1) {
            ax[a[i]] = i;
        }
    }

    int index = target - 1;
    for (int i = 1; i < n; ++i) {
        if (i + index == target && ax[i] != -1 && ax[index] != -1) {
            std::cout << " i : " << ax[i] << " , j : " << ax[index];
            break;
        }
        --index;
    }
}

int main()
{
    int a[] = { 8, 3, 9, 7, 5, 4 }, n = 6, k = 10;
    findSubArry(a, n, k);
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
