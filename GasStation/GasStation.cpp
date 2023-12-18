// GasStation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int stations = gas.size();
        for (int i = 0; i < stations; ++i) {
            int j = i;
            int rem = 0;
            while (rem + gas[j] >= cost[j]) {
                rem = rem + gas[j] - cost[j];
                j = ++j % stations;
                if (i == j) {
                    return i;
                }
            }
        }

        return -1;
    }
};

int main()
{
    std::vector<int> gas = { 2, 3, 4 };
    std::vector<int>cost = { 3, 4, 3 };


    std::cout << "start station : " << Solution().canCompleteCircuit(gas, cost) << "\n";
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
