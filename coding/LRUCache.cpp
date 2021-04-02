#include <stdio.h>
#include <unordered_map>
#include <iterator>
#include <list>

using namespace std;

class LRUCache {
private:
    unordered_map<int, list<int>::iterator> mp;
    list<int> lru;
    int capacity;

public:
    LRUCache(int size) :
        capacity(size)
    {}

    void put(int value)
    {
        if(mp.count(value) == 0 && mp.size() == capacity)
            evict();


        updateLRU(value);
    }

    int get(int value)
    {
        if(mp.count(value) == 0)
            return -1;

        updateLRU(value);
    }

    void updateLRU(int value)
    {
        if(mp.count(value))
            lru.erase(mp[value]);

        lru.push_front(value);
        mp[value] = lru.begin();
    }

    void evict()
    {
        printf("evict() : %d\n", lru.back());
        mp.erase(lru.back());
        lru.pop_back();
    }

    void print()
    {
        //for(list<int>::iterator it = lru.begin(); it != lru.end(); it++)
        for(auto it = lru.begin(); it != lru.end(); it++)
        {
            printf("%d, ", *it);
        }
        printf("\n");
    }
};

int main(void)
{
    LRUCache cache(4);
    cache.put(1);
    cache.print();

    cache.put(2);
    cache.print();

    cache.put(3);
    cache.print();

    cache.put(4);
    cache.print();

    cache.put(5);
    cache.print();

    cache.put(2);
    cache.print();

    return 0;
}