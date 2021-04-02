/* Merge Two Sorted Linked Lists */
#include <stdio.h>
#include <vector>

using namespace std;

#if 1
vector<int> merge2Sorted(vector<int> &v1, vector<int> &v2)
{
    int len1 = v1.size();
    int len2 = v2.size();
    vector<int> ret(len1 + len2);

    int i = 0, j = 0;
    int out = 0;

    while(i < len1 && j < len2)
    {
        if(v1[i] < v2[j])
            ret[out++] = v1[i++];
        else
            ret[out++] = v2[j++];
    }

    while(i < len1)
        ret[out++] = v1[i++];
    
    while(j < len2)
        ret[out++] = v2[j++];

    return ret;
}
#else
vector<int> merge2Sorted(vector<int> &v1, vector<int> &v2)
{
    int len1 = v1.size();
    int len2 = v2.size();

    vector<int> ret(len1 + len2);
    int pos = len1 + len2 - 1;
    
    while(len1 > 0 && len2 > 0)
    {
        if(v1[len1 - 1] > v2[len2 - 1])
            ret[pos--] = v1[--len1];
        else
            ret[pos--] = v2[--len2];
    }

    while(len1 > 0)
        ret[pos--] = v1[--len1];

    while(len2 > 0)
        ret[pos--] = v2[--len2];

    return ret;
}
#endif

int main()
{
    printf("Merge Two Sorted List\n");
    vector<int> v1 = {1, 3, 5, 6};
    vector<int> v2 = {2, 4, 6, 20, 34};

    vector<int> ret = merge2Sorted(v1, v2);

    int j = 0;
    for(int i = 0; i < ret.size(); i++)
    {
        printf("%d ", ret[i]);
    }
    printf("\n");

    return 0;
}