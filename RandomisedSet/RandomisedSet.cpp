// RandomisedSet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>

class RandomizedSet {

    std::unordered_map<int, int> valuesMap;
    std::vector<int> values;

public:
    RandomizedSet() {}

    bool insert(int val) {

        bool result = false;

        if (valuesMap.find(val) == valuesMap.end()) {
            result = true;

            values.push_back(val);
            valuesMap[val] = values.size() - 1;
        }

        return result;
    }

    bool remove(int val) {
        bool result = false;
        if (valuesMap.find(val) != valuesMap.end()) {
            result = true;

            auto pos = valuesMap[val];

            std::swap(values[pos], values[valuesMap.size() - 1]);
            valuesMap[values[pos]] = pos;

            valuesMap.erase(val);
            values.pop_back();
        }

        return result;
    }

    int getRandom() {
        /*
        [1, 2, 3, 4, 5]
        [1, 3, 4, 5]
        [1, 3, 5]
        [1, 2, 3, 5]
        */
        int pos = rand() % values.size();
        return values[pos];
    }
};

int main()
{
    RandomizedSet set;
    std::cout << "[ "<< set.remove(0)  << ", ";
    std::cout << set.remove(0)  << ", ";
    std::cout << set.insert(0)  << ", ";
    std::cout << set.getRandom()<< ", ";
    std::cout << set.remove(0)  << ", ";
    std::cout << set.insert(0)  << "]";

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
