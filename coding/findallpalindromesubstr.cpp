/* Find All Palindrome Substrings */
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

bool isPalindrome(string str)
{
    int len = str.size();
    for(int i = 0; i < len / 2; i++)
        if(str[i] != str[len - i - 1])
            return false;

    return true;
}

vector<string> findAllPalindromeSubStr(string str)
{
    vector<string> ret;

    int len = str.size();

    for(int i = 0; i < len; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if(isPalindrome(str.substr(i, j - i + 1)) == true)
                ret.push_back(str.substr(i, j - i + 1));
        }
    }

    return ret;
}

int main()
{
    printf( "find all Plindrome substrings!!\n");
    string str = "aabbbaa";
    vector<string> ret = findAllPalindromeSubStr(str);

    for(int i = 0; i < ret.size(); i++)
        printf("%s ", ret[i].c_str());
    printf("\n");
    return 0;
}
