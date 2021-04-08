/* Group Anagrams */
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<string>> groupAnagram(vector<string> &strs)
{
    vector<vector<string>> ret;
    map<string, vector<string>> mp;

    for(auto &str : strs)
    {
        string s = str;
        sort(s.begin(), s.end());
        mp[s].push_back(str);
    }

    for(auto &k : mp)
    {
        ret.push_back(k.second);
    }

    return ret;
}

int main()
{
    printf("Group Anagrams\n");

    vector<string> input = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ret = groupAnagram(input);

    for(int i = 0; i < ret.size(); i++)
    {
        printf("[ ");
        for(int j = 0; j < ret[i].size(); j++)
        {
            printf("%s ", ret[i][j].c_str());
        }
        printf("] ");
    }
    printf("\n");

    return 0;
}