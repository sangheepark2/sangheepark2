/* Search Rotated Array */
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int binary_search_rotated(vector<int> &v1, int target)
{
    int ret = 0;

    int pivot = -1;
    int len = v1.size();
    int left, right;

    left = 0, right = len - 1;
    int mid = 0;
    while(left < right)
    {
        mid = left + (right - left) / 2;
        if(v1[right] < v1[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    pivot = left;
    left = 0, right = len - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        int realmid = (mid + pivot) % len;
        if(v1[realmid] < target)
            left = mid + 1;
        else if(v1[realmid] > target)
            right = mid - 1;
        else
            return realmid;
    }

    return -1;
}

int main()
{
    printf("Search Rotated Array\n");
    vector<int> v1 = {6, 7, 1, 2, 3, 4, 5};

    cout<<"Key(3) found at: "<<binary_search_rotated(v1, 3)<<endl;
    cout<<"Key(6) found at: "<<binary_search_rotated(v1, 6)<<endl;

    vector<int> v2 = {4, 5, 6, 1, 2, 3};
    
    cout<<"Key(3) found at: "<<binary_search_rotated(v2, 3)<<endl;
    cout<<"Key(6) found at: "<<binary_search_rotated(v2, 6)<<endl;  
    return 0;
}