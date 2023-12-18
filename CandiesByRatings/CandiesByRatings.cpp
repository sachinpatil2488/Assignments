// CandiesByRatings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool possible(vector<int>& ratings, vector<int> candies, int mid) {
        bool result = true;
        int n = ratings.size();

        //candies : already allocated n candies
        //remainging
        int remainingCandies = mid - n;
        if (remainingCandies <=0) {
            return false;
        }

        while (remainingCandies >= 0) {

            int temp = remainingCandies;

            for (int i = 1; i < n; ++i) {
                if (ratings[i] > ratings[i - 1] &&
                    candies[i] <= candies[i - 1]) {

                    int diff = candies[i - 1] - candies[i];
                    candies[i] += diff + 1;
                    remainingCandies -= (diff + 1);
                }

                if (ratings[i] < ratings[i - 1] &&
                    candies[i] >= candies[i - 1]) {

                    int diff = candies[i] - candies[i - 1];
                    candies[i - 1] += diff + 1;
                    remainingCandies -= (diff + 1);
                }

                //candies short
                if (remainingCandies < 0) {
                    break;
                }
            }

            //no more alloaction
            if (remainingCandies == temp) {
                break;
            }
        }

        return remainingCandies >= 0;
    }

    int candy(vector<int>& ratings) {

        int n = ratings.size();
        if (std::all_of(ratings.begin(), ratings.end(),
            [&](int& rate) { return ratings[0] == rate; })) {

            return n;
        }

        vector<int> candies(n, 1);
        //memset(candies, 1, n);

        int min = n, max = (n * (n + 1)) / 2;
        int result = min;
        while (min <= max) {
            int mid = (min + max) / 2;
            if (possible(ratings, candies, mid)) {
                result = mid;
                max = mid - 1;
            }
            else {
                min = mid + 1;
            }
        }

        return result;
    }

    int candyBruteForce(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies;
        candies.resize(n);

        for (int i = 0; i < n; ++i) {
            candies[i] = 1;
        }

        bool change = true;
        int result = n;

        while (change) {

            change = false;
            for (int i = 0; i < n - 1; ++i) {
                if (ratings[i] > ratings[i + 1] &&
                    candies[i] <= candies[i + 1]) {
                    candies[i]++;
                    change = true;
                    ++result;
                }
                else if (ratings[i] < ratings[i + 1] &&
                    candies[i] >= candies[i + 1]) {
                    candies[i + 1]++;
                    change = true;
                    ++result;
                }
            }
        }

        return result;
    }
};

int main()
{
    std::vector<int> ratings{ 1,2,87,87,87,2,1 };// { 1, 3, 2, 2, 1 };
    std::cout << "effi : " << Solution().candy(ratings);
    std::cout << "\nbrute : " << Solution().candyBruteForce(ratings);
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
