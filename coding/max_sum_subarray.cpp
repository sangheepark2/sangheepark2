/* Largest Sum Subarray */
#include <vector>
#include <stdio.h>

using namespace std;
#if 1
int findMaxSumSubarray(vector<int> &data)
{
    int ret = 0;
    int len = data.size();
    if(len == 0)
        return 0;
    else if(len == 1)
        return data[0];

    int lmax = data[0];
    int gmax = data[0];
    
    for(int i = 0; i < len; i++)
    {
        lmax = max(data[i], lmax + data[i]);
        gmax = max(lmax, gmax);
    }

    return gmax;
}
#else
int findMaxSumSubarray(vector<int> &data)
{
    int ret = 0;
    int len = data.size();
    if(len == 0)
        return 0;
    else if(len == 1)
        return data[0];

    int lmax = data[0];
    int gmax = data[0];
    for(int i = 1; i < len; i++)
    {
        if(lmax < 0)
        {
            lmax = data[i];
        }
        else
        {
            lmax += data[i];
        }

        gmax = max(lmax, gmax);
    }

    return gmax;
}
#endif

int main()
{
    printf("Largest Sum Subarray\n");
    vector<int> data = {-4, 2, -5, 1, 2, 3, 6, -5, 1};

    printf("max sum: %d\n", findMaxSumSubarray(data));

    return 0;
}