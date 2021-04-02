/* add two integers represented with LinkedList */
/*
// assuming both integers are stored in a linked list
// e.g. 415 is stored as 5->1->4
// 32 is stored as 2->3
*/
#include <stdio.h>
#include <vector>
#include <list>

using namespace std;

list<int> addIntegers(list<int> &int1, list<int> &int2)
{
    list<int> ret;

    int c = 0;
    while(int1.size() > 0 || int2.size() > 0)
    {
        int a = 0;
        if(int1.size() > 0)
        {
            a = int1.front();
            int1.pop_front();
        }
        
        int b = 0;
        if(int2.size() > 0)
        {
            b = int2.front();
            int2.pop_front();
        }

        int val = (a + b + c) % 10;
        c = (a + b + c) > 10 ? 1 : 0;

        ret.push_back(val);
    }

    if(c == 1)
        ret.push_back(c);

    return ret;
}


int main()
{
   	vector<int> v1 = {1, 2, 3}; // 321
    vector<int> v2 = {1, 2}; // 21
    list<int> int1(v1.begin(), v1.end());
    list<int> int2(v2.begin(), v2.end());

    list<int> result = {2, 4,3};
    printf( "addTwoIntegers\n");
    list<int> ret = addIntegers(int1, int2);

    while(ret.size() > 0)
    {
        int val = ret.front();
        ret.pop_front();
        printf("%d ", val);
    }

    printf("return\n");
    return 0;
}
