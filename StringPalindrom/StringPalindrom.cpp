// StringPalindrom.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        {
            int i = 0;
            int j = s.length() - 1;

            while (i < j) {

                if (!isalpha(s[i])) {
                    ++i;
                }
                else if (!isalpha(s[j])) {
                    --j;
                }
                else if (tolower(s[i]) == tolower(s[j])) {
                    ++i;
                    --j;
                }
                else {
                    return false;
                }
            }
        }
        string res;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z') res += (s[i] + ('a' - 'A'));
            else if (s[i] >= 'a' && s[i] <= 'z') res += s[i];
            else if (s[i] >= '0' && s[i] <= '9') res += s[i];
        }
        int i = 0;
        int j = res.length() - 1;
        while (i < j)
        {
            if (res[i] != res[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

int main()
{
    std::cout <<boolalpha << Solution().isPalindrome("0P");
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
