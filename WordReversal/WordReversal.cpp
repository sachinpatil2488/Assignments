/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>

using namespace std;

string reverseWords(string s) {
    std::string result;
    std::string word;

    int p = s.length() - 1;
    int len = 0;

    while (p >=0 ) {

        if (std::isspace(s[p])) {
            word = s.substr(p+1, len);
            if (word.size()) {
                result += result.empty() ? word : " " + word;
            }
            len = 0;
        }
        else {
            ++len;
        }

        --p;
    }

    if (len) {
        word = s.substr(p+1, len);
        if (word.size()) {
            result += result.empty() ? word : " " + word;
        }
    }
    return result;
}

int main()
{
    cout << reverseWords("  my name is   luckhan  ");
    return 0;
}
