// AllocateBookes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

using namespace std;

bool allocate(int* books, int sCount, int bCount, int maxPagesPerStudent)
{
    int sum = 0, allocatedStudents = 0;
    for (int i=0; i< bCount; ++i) {

        if (books[i] > maxPagesPerStudent) {
            return false;
        }

        if (books[i] + sum > maxPagesPerStudent) {
            sum = 0;
            allocatedStudents++;

            if (allocatedStudents > sCount) {
                return false; //exhausted
            }
        } else {
            sum += books[i];
        }
    }

    return true;
}

int allocateBooks(int* books, int bCount, int sCount)
{
    if (sCount > bCount) {
        return -1;
    }

    int maxPageCount = 0, result = 0;
    int totalPages = 0;

    for (int i=0; i<bCount; ++i) {
        maxPageCount = std::max(maxPageCount, books[i]);
        totalPages += books[i];
    }
    
    //Result lies between maxPageCount and totalPages

    while (maxPageCount <= totalPages) {
        int mid = (maxPageCount + totalPages) / 2;
        if (allocate(books, sCount, bCount, mid)) {
            result = mid;
            totalPages = mid - 1;
        } else {
            maxPageCount = mid + 1;
        }
    }

    return result;
}

int main()
{
    int books[] = { 20, 23 }, size = 2;
    int studentCount = 2;
    std::cout << "Min pages : " << allocateBooks(books, size, studentCount);

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
