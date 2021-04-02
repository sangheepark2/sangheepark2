/* Find All Sum Combinations */
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

void rec(int target, vector<vector<int>> &ret, vector<int> &cur, int start)
{
    if(target == 0)
    {
        /*
        sort(cur.begin(), cur.end());
        if(find(ret.begin(), ret.end(), cur) != ret.end())
            return;
        */

        ret.push_back(cur);
        return;
    }
    /*
    else if(target < 0)
    {
        return;
    }
    */

    //for(int i = 1; i <= target; i++)
    for(int i = start; i <= target; i++)
    {
        cur.push_back(i);
        rec(target - i, ret, cur, start);
        cur.pop_back();
    }
}

vector<vector<int>> allSumComb(int n)
{
    vector<vector<int>> ret;
    vector<int> cur;

    for(int i = 1; i <= n; i++)
    {
        cur.push_back(i);
        rec(n - i, ret, cur, i);
        cur.pop_back();
    }

    return ret;
}

int main()
{
    int n = 4;
    vector<vector<int>> ret;

    ret = allSumComb(n);

    printf("ret.size(): %d\n", ret.size());

    for(int i = 0; i < ret.size(); i++)
    {
        for(int j = 0; j < ret[i].size(); j++)
        {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}
