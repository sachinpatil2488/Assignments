// MaxLengthSubStringPalindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <tuple>
#include <string>

using namespace std;

bool isPanlindrome(int i, int j, std::string& str)
{
    while (i < j) {
        if (str[i] != str[j]) {
            return false;
        }

        ++i;
        --j;
    }

    return true;
}

std::tuple<int, int> getMaxLengthPalindromeSlidingWindow(std::string str)
{
    //"abaaba"
    int maxLen = 0, start = - 1;;

    for (int i = 0; i < str.length() - 1; ++i) {
        for (int j = i+1; j < str.length(); ++j) {
            if (str[i] == str[j] && isPanlindrome(i, j, str)) {
                if (j-i > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }
    }

    return { start, maxLen };
}

std::tuple<int, int> getMaxLenPalindromeByEfficientWay(std::string str)
{
    if (str.length() < 1) {
        return std::make_tuple<int, int>(1,1);
    }

    int n = str.length() - 1;
    
    int maxLen = 0, start = 0, end = 0;

    auto findPalindrome = [&](int j, int i) {
        while (j >= 0 && i <= n && str[j] == str[i]) {
            int dist = i - j + 1;
            if (dist > maxLen) {
                start = j;
                end = i;
                maxLen = dist;
            }
            --j;
            ++i;
        }
    };

    for (int i = 1; i <=n; ++i) {
        //odd length
        findPalindrome(i - 1, i + 1);

        //even length
        findPalindrome(i-1, i);
    }

    return { start, end };
}

int main()
{
    //std::tuple<int, int> result = getMaxLengthPalindromeSlidingWindow("abaaba");
    std::tuple<int, int> result = getMaxLenPalindromeByEfficientWay("abaaba");
    std::cout << " start : " << std::get<0>(result) << ", pos : " << std::get<1>(result);
    std::cout << "Hello World!\n";
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
