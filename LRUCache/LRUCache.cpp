// LRUCache.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
    int m_capacity = 0;
    std::list<std::pair<int, int>> m_lru;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_cache;

public:
    LRUCache(int capacity) : m_capacity(capacity) {}

    int get(int key)
    {
        int result = -1;

        auto itr = m_cache.find(key);
        if (itr != m_cache.end()) {
            m_lru.push_front(*(itr->second));
            m_lru.erase(itr->second);
            m_cache[key] = m_lru.begin();

            result = m_lru.begin()->second;
        }

        return result;
    }

    void put(int key, int value)
    {
        auto itr = m_cache.find(key);
        if (itr != m_cache.end()) {
            m_lru.erase(itr->second);
        }
        else {
            if (m_cache.size() >= m_capacity) {
                auto keyValue = m_lru.back();
                m_lru.erase(m_cache[keyValue.first]);
                m_cache.erase(keyValue.first);
            }
        }

        m_lru.push_front({ key, value });
        m_cache[key] = m_lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
    std::cout << "Hello World!\n";
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cache.get(1);
    cache.put(3,3);
    cache.get(2);
    cache.put(4,4);
    cache.get(1);
    cache.get(3);
    cache.get(4);
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
