// EvaluateReversePolishNotation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isOperator(string& str) {
        if (str.length() != 1) {
            return false;
        }

        switch (str[0]) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
        }

        return false;
    }

    int evaluate(string& str, std::stack<int>& stk)
    {
        auto op1 = stk.top();
        stk.pop();
        auto op2 = stk.top();
        stk.pop();

        switch (str[0]) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '/': return op2 / op1;
        case '*': return op1 * op2;
        }

        return 0;
    }

    int evalRPN(vector<string>& tokens) {

        std::stack<int> stk;

        for (auto& str : tokens) {

            if (isOperator(str)) {
                stk.push(evaluate(str, stk));
            }
            else {
                if (std::all_of(str.begin(), str.end(), [](char c) { return std::isdigit(c); })) {
                    stk.push(std::atoi(str.c_str()));
                }
                else {
                    //std::vector<string> exp {str}
                    //stk.push(evalRPN(exp));
                    //auto sd = std::all_of(str.begin() + 1, str.end(), [](char c) { return std::isdigit(c); });
                    //if (str[0] == '-') {
                        //stk.push(std::atoi(str.c_str() + 1) * -1);
                        stk.push(std::atoi(str.c_str()));
                    //}
                }
            }
        }

        return stk.top();
    }
};

int main()
{
    std::vector<string> exp{ "1", "2", "+", "-3", "/" };
    Solution s;

    std::cout << "Result : "<< s.evalRPN(exp) << "\n";
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
