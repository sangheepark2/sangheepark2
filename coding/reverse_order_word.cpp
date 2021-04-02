/* 
Reverse the order of words in a given sentence (an array of characters).
*/
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

string reverse_word(string str)
{
    string ret;
    vector<string> tmp;
    int len = str.size();

    int prev = 0;
    for(int i = 0; i < len; i++)
    {
        if(str[i] == ' ' || str[i] == '\0') 
        {
            string s = str.substr(prev, i - prev);
            tmp.push_back(s);
            prev = i + 1;
        }
        else if(i == len - 1)
        {
            string s = str.substr(prev, i - prev + 1);
            tmp.push_back(s);
        }
    }

    reverse(tmp.begin(), tmp.end());

    for(int i = 0; i < tmp.size(); i++)
    {
        if(i == 0)
            ret = tmp[i];
        else
            ret = ret + " " + tmp[i];
    }
    return ret;
}

int main()
{
    string str = "Hello World Man";
    printf( "Reverse the order of words\n");

    printf("%s\n", str.c_str());
    string ret = reverse_word(str);
    printf("%s\n", ret.c_str());

    return 0;
}