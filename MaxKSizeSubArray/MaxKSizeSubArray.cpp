// MaxKSizeSubArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int bruteForce(int* a, int n, int B)
{
	int k = 1, ans = 0;

	while (k <= n) {
		
		int flag = 0;
		for (int i = 0; i <= n - k; ++i) {
			int sum = 0;
			for (int j = i; j < i + k; ++j) {
				sum += a[j];
			}

			if (sum > B) {
				flag = 1;
				break;
			}
		}

		if (k == 1 && flag == 1)
			break;

		if (flag == 0) {
			ans = k;
		}
		
		++k;
	}

	return ans;
}


bool isPossible(int*a, int n, int k, int B, int* sumArry)
{
	/*
	Solution 1: N2logN
	*/
	/*for (int i=0; i<=n-k; ++i) {
		int sum = 0;
		for(int j=i; j<i+k; ++j) {
			sum += a[j];
		}

		if (sum > B) {
			return false;
		}
	}*/

	/*
	Solution 2: NlogN
	*/
	for (int i = k - 1; i <n; ++i) {
		int sum = 0;
		if (i - k > -1) {
			sum = sumArry[i] - sumArry[i-k];
		} else {
			sum = sumArry[i];
		}

		if (sum > B) {
			return false;
		}
	}
	return true;
}

int efficient(int* a, int n, int B)
{
	int ans = 0;
	int start = 1, end = n;

	int* sumArry = new int[n]{ 0 };

	sumArry[0] = a[0];
	for (int i = 1; i<n; ++i) {

		if (a[i] > B) {
			return 0;
		}
		sumArry[i] = a[i] + sumArry[i - 1];
	}

    while (start <= end) {
		int k = (start + end) / 2;
		if (isPossible(a, n, k, B, sumArry)) {
			ans = k;
			start = k + 1;
		} else {
			end = k - 1;
		}
    }

	return ans;
}

int main()
{
	int a[] = { 1,2,3,4 }, n = 4, B = 9;

    //std::cout << "K : " <<bruteForce(a,n,B);
	std::cout << "K : " << efficient(a, n, B);
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
