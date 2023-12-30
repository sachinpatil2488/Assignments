// StringSubSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubSequence(string s, string& word)
    {
        int sL = s.length();
        int wL = word.length();
        if (wL > sL) {
            return false;
        }

        int si = 0, wi = 0;
        while (wi < wL && si < sL ? (word[wi] == s[si++] ? ++wi : true) : false);

        return wi == wL;
    }

    bool isSubSequence(string s, string& word, vector<int> pos, vector<int> counts)
    {
        int sL = s.length();
        int wL = word.length();
        if (wL > sL) {
            return false;
        }

        int si = pos[word[0]];
        if (si == -1) { 
            return false;
        }

        int wi = 0;
        while (wi < wL && si < sL) {

            if (counts[word[wi]] <= 0) {
                break;
            }

            if (word[wi] == s[si++]) {               
                --counts[word[wi]];
                ++wi;
            }
        }

        return wi == wL;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        //Brute force
        int count = 0;
        /*for (auto& word : words) {
            if (isSubSequence(s, word)) {
                ++count;
            }
        }*/

        //efficient
        vector<int> position(127, -1);
        vector<int> counts(127, 0);

        for (int i = 0; i < s.length(); ++i) {
            auto& c = s[i];

            if (position[c] == -1) {
                position[c] = i;
            }

            ++counts[c];
        }

        for (auto& word : words) {
            if (isSubSequence(s, word, position, counts)) {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    string s = "abcd";
    vector<string> words = { "a", "acd" , "adc" };

    std::cout << Solution().numMatchingSubseq(s, words);
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
