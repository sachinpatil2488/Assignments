// StringAnagram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> result;

        std::vector<int> freq;
        for (int i = 0; i < 127; ++i)
            freq.push_back(-1);

        for (auto i : p) {
            if (freq[i] == -1) {
                freq[i] = 1;
            }
            else {
                ++freq[i];
            }
        }

        //    string s = "cbaebabacd", p = "abc";
        auto tempFreq = freq;

        for (int i = 0; i < s.length();) {

            if (freq[s[i]] != -1) {
                int start = i;
                int len = p.length();

                while (len) {
                    if (freq[s[i]] == -1) {
                        ++i;
                        break;
                    } else if(freq[s[i]]-- == 0) {
                        i = start + 1;
                        break;
                    } else {
                        --len;
                        if (len == 0) {
                            result.push_back(start);
                            i = start + 1;
                            break;
                        }
 
                        ++i;
                    }
                }
                freq = tempFreq;
            }
            else {
                ++i;
            }
        }

        return result;
    }
};

int main()
{
//Input:
    string s = "cbaebabacd", p = "abc";
//Output : [0, 6]
    auto result = Solution().findAnagrams(s, p);
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
