// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void merge(int* arr, int l, int mid, int r)
{
    int* temp = new int[r - l + 1];

    int index = 0, i=l, j=mid + 1;

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[index++] = arr[i++];
        } else {
            temp[index++] = arr[j++];
        }
    }

    for (int k = i; k<=mid; ++k) {
        temp[index++] = arr[k];
    }

    for (int k = j; k <= r; ++k) {
        temp[index++] = arr[k];
    }

    index = 0;
    for (int k = l; k <= r; ++k) {
        arr[k] = temp[index++];
    }

    delete[]temp;
}


void mergeSort(int* arr, int l, int r)
{
    if (l == r) return;

    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

int main()
{
    int arr[] = { 2, 1, 9, 2, 4, -3, 0 };
    
    int size = sizeof(arr)/sizeof(int);

    mergeSort(arr, 0, size-1);

    for (int i =0 ; i < size; ++i ){
        std::cout << arr[i] << " ";
    }

    std::cout << "\n\n";

    return 0;
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
