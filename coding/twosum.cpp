/* Two Sum */
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

vector<vector<int>> twosum(vector<int> &nums, int target)
{
    vector<vector<int>> ret;
    //unordered_map<int, int> mp; // number - index
    map<int, int> mp; // number - index
    int len = nums.size();

    for(int i = 0; i < len; i++)
    {
        if(mp.find(target - nums[i]) != mp.end())
        {
            vector<int> cur;
            if(i < mp[target - nums[i]])
            {
                cur.push_back(i);
                cur.push_back(mp[target - nums[i]]);
            }
            else
            {
                cur.push_back(mp[target - nums[i]]);
                cur.push_back(i);
            }
            ret.push_back(cur);
        }
        mp[nums[i]] = i;
    }

    return ret;
}

int main()
{
    printf("\nTwo Sum\n");
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<vector<int>> ret = twosum(nums, target);
    
    for(int i = 0; i < ret.size(); i++)
    {
        printf("\n[%d %d] ", ret[i][0], ret[i][1]);
    }
    printf("\n");

    vector<int> nums2 = {3, 2, 4};
    ret = twosum(nums2, 6);
    
    for(int i = 0; i < ret.size(); i++)
    {
        printf("\n[%d %d] ", ret[i][0], ret[i][1]);
    }
    printf("\n");
    return 0;
}