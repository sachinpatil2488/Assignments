// TextJustification.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*class Solution {
public:

    string formLine(vector<string>& line, int maxWidth, bool noFormat)
    {
        int wordCount = line.size() - 1;
        int len = 0;
        for (auto word : line) {
            len += word.length();
        }

        int spaces = maxWidth - len;
        
        string str;
        int i = 0;
        for (; i < wordCount; ++i) {
            str += line[i];

            if (!noFormat) {
                int space = spaces / (wordCount);
                if (i == 0) {
                    space += spaces % (wordCount);
                }

                for (int j = 0; j < space; ++j) {
                    str += " ";
                }
            } else {
                str += " ";
            }
        }

        str += line[i];

        return str;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> lines;

        int n = words.size();
        int  i = 0;

        vector<string> line;
        line.push_back(words[i]);
        int lineLength = words[i].length();

        while (i < n) {
            int j = i + 1;
            if (j < n && lineLength + words[j].length() + 1 <= maxWidth) {
                lineLength += words[j].length() + 1;
                line.push_back(words[j]);
            }
            else {
                //form line from line
                string str = formLine(line, maxWidth, j == n);
                lines.push_back(str);
                line.clear();
                if (j < n) {
                    line.push_back(words[j]);
                    lineLength = words[j].length();
                }
            }

            i = j;
        }

        if (line.size()) {
            string str;
            for (int i = 0; i < line.size(); ++i) {
                i == 0 ? str += line[i] : str += " " + line[i];
            }

            lines.push_back(str);
        }

        return lines;
    }
};
*/

class Solution {
public:

    string formLine(vector<string>& line, int maxWidth, bool noformat)
    {
        int wordCount = line.size() - 1;
        int len = 0;

        for (auto word : line) {
            len += word.length();
        }

        int spaces = maxWidth - len;

        string str;
        int i = 0;
        for (; i < wordCount; ++i) {

            str += line[i];
            if (!noformat) {
                int space = spaces / wordCount;
                if (i == 0) {
                    space += spaces % wordCount;
                }

                for (int j = 0; j < space; ++j) {
                    str += " ";
                }
            }
            else {
                str += " ";
            }
        }

        str += line[i];

        return str;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {

        vector<string> lines;

        int n = words.size();
        int  i = 0;

        vector<string> line;
        line.push_back(words[i]);
        int lineLength = words[i].length();

        while (i < n) {

            int j = i + 1;

            if (j < n && lineLength + words[j].length() + 1 <= maxWidth) {
                lineLength += words[j].length() + 1;
                line.push_back(words[j]);
            }
            else {

                string str = formLine(line, maxWidth, j == n);
                lines.push_back(str);
                line.clear();

                if (j < n) {
                    line.push_back(words[j]);
                    lineLength = words[j].length();
                }
            }

            i = j;
        }

        if (line.size()) {
            string str;
            for (int i = 0; i < line.size(); ++i) {
                i == 0 ? str += line[i] : str += " " + line[i];
            }

            lines.push_back(str);
        }

        return lines;
    }
};

int main()
{
    std::vector<string> words{ "This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    /*Output :
    [
        "This    is    an",
        "example  of text",
        "justification.  "
    ]
    */

    Solution().fullJustify(words, maxWidth);
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
