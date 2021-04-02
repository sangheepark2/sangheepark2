/*
Merge Overlapping Intervals
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

static bool sortCol(vector<int> &v1, vector<int> &v2)
{
    return v1[0] < v2[0];
}

vector<vector<int>> merge(vector<vector<int>> &input)
{
    vector<vector<int>> ret;
    sort(input.begin(), input.end(), sortCol);
    int len = input.size();

    for(int i = 0; i < len; i++)
    {
        int start = input[i][0];
        int end = input[i][1];

        for(int j = i + 1; j < len; j++)
        {
            if(input[j][0] <= end)
            {
                end = max(end, input[j][1]);
                i = j;
            }
            else
                break;
        }
        
        vector<int> tmp{start, end};
        ret.push_back(tmp);
    }

    return ret;
}

int main()
{
    vector<vector<int>> input = {{1, 5}, {3, 7}, {4, 6}, {6, 8}, {10, 12}, {11, 15}};

    vector<vector<int>> ret = merge(input);

    for(int i = 0; i < ret.size(); i++)
    {
        printf( "[%d, %d], ", ret[i][0], ret[i][1]);
    }
    printf("\n[2]ret.size(): %d\n", ret.size());
    return 0;
}
