/*
Given an array of integers and a value, determine if there are any three integers in the array whose sum equals the given value.
*/
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool find3sum(vector<int> &input, int target)
{
    bool ret = false;
    std::sort(input.begin(), input.end());
    int len = input.size();

    for(int i = 0; i < len; i++)
    {
        int target2 = target - input[i];
        int front = i + 1;
        int back = len - 1;
        while(front < back)
        {
            if(input[front] + input[back] < target2)
                front++;
            else if(input[front] + input[back] > target2)
                back--;
            else
                return true;
        } 
    }

    return false;
}

int main()
{
    vector<int> arr = {-25, -10, -7, -3, 2, 4, 8, 10};

    cout << "-8: " << find3sum(arr, -8) << endl;
    cout << "-25: " << find3sum(arr, -25)<< endl;
    cout << "0: " << find3sum(arr, 0) << endl;
    cout << "-42: " << find3sum(arr, -42) << endl; 
    cout << "22: " << find3sum(arr, 22) << endl; 
    cout << "-7: " << find3sum(arr, -7) << endl;
    cout << "-3: " << find3sum(arr, -3) << endl; 
    cout << "2: " << find3sum(arr, 2) << endl; 
    cout << "4: " << find3sum(arr, 4) << endl; 
    cout << "8: " << find3sum(arr, 8) << endl; 
    cout << "7: " << find3sum(arr, 7) << endl; 
    cout << "1: " << find3sum(arr, 1) << endl;    
}