// StringZigzag.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:

    string convertY(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }

        vector<string> pattern(numRows, "");

        int r = 0;
        bool flag = false;

        for (auto& c : s) {
            pattern[r] += c;

            if (r == numRows - 1 || r == 0) {
                flag = !flag;
            }

            flag ? ++r : --r;
        }

        string result;
        for (auto& p : pattern) {
            result += p;
        }

        return result;
    }

    string convert(string s, const int numRows) {

        const int rC = 3, cC = 3 * 3;
        char p[rC][cC] { 0 };

        for (int i = 0; i < rC; ++i) {
            for (int j = 0; j < cC; ++j) {
                p[i][j] = '-';
            }
        }


        int i = 0;
        int len = s.length();
        int c = 0;

        while (i < len) {
            for (int r = 0; r < rC && i < len; ++r) {
                p[r][c] = s[i++];
            }

            ++c;

            for (int r = rC-2; r > 0 && c < cC && i < len; --r, ++c, ++i) {
                p[r][c] = s[i];
            }
        }

        string result;
        for (i = 0; i < rC; ++i) {
            for (int j = 0; j < cC; ++j) {
                if (p[i][j] != '-') {
                    result += p[i][j];
                }
            }
        }

        return result;
    }

    string convertX(string s, const int numRows) {

        std::vector<string> p(numRows, "");

        int i = 0;
        int len = s.length();
        int c = 0;

        while (i < len) {
            for (int r = 0; r < numRows && i < len; ++r) {
                p[r] += s[i++];
            }

            for (int r = numRows - 2; r > 0 && i < len; --r) {
                p[r]+= s[i++];
            }
        }

        std::string result;
        for (auto str : p) {
            result += str;
        }
        return result;
    }

    string convert1(string s, int numRows)
    {

        if (numRows <= 1) { 
            return s;
        }

        vector<string> v(numRows, "");

        int j = 0, dir = -1;

        for (int i = 0; i < s.length(); i++) {

            if (j == numRows - 1 || j == 0) {
                dir *= (-1);
            }

            v[j] += s[i];

            if (dir == 1) {
                j++;
            }
            else {
                j--;
            }
        }

        string res;
        for (auto& it : v) res += it;

        return res;
    }
};

int main()
{
    std::cout << "\n" << Solution().convertY("PAYPALISHIRING", 3);
    std::cout << "\n" << Solution().convertX("PAYPALISHIRING", 3);
    std::cout <<"\n"<< Solution().convert1("PAYPALISHIRING", 3);
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
