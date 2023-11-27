// SubSequenceOfSize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*        
                                        12345
             1,2345                     2,345              3,45         4,5   5
         12,345  13,45  14,5  15      23,45  24,5  25       34,5  35    45
    123,45  124,5   
*/

int c = 0;
int X = 9;
std::vector<std::vector<int>> seqs;

void findCount(std::vector<int>& a, int b, int sum, int l,  int i, std::vector<int>& seq)
{
    if (l > b || sum > X)
        return;

    if (l == b && sum <= X) {
        c++;
        seqs.push_back(seq);
        return;
    }

    for (int j = i; j <a.size(); ++j) {
        seq[l] = a[j];
        findCount(a, b, sum + a[j], l + 1, j + 1, seq);
    }

}

int main()
{
    std::vector<int> a { 1,2,3,4,5 };
    int b = 3;
    std::vector<int> seq {0,0,0,0};


    for (int i = 0; i < a.size() - b; ++i) {
        seq[0] = a[i];
        findCount(a, b, a[i], 1, i + 1, seq);
    }
    std::cout << "\ncount : " << c;

    for (int i = 0; i< seqs.size(); ++i) {
        std::cout << "\n {";
        for (int j = 0; j < seqs[i].size(); ++j) {
            std::cout << seqs[i][j] << ",";
        }
        std::cout << "}\n";
    }
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
