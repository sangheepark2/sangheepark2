/* Inplace rotate square matrix by 90 degrees */
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>> &img)
{
    reverse(img.begin(), img.end());

    for(int i = 0; i < img.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            swap(img[i][j], img[j][i]);
        }
    }
}

void rotate_anti(vector<vector<int>> &img)
{
    for(auto &v : img)
        reverse(v.begin(), v.end());

    for(int i = 0; i < img.size(); i++)
    {
        for(int j = 0; j < i; j++)
            swap(img[i][j], img[j][i]);
    }
}

void printImg(vector<vector<int>> &img)
{
    for(int i = 0; i < img.size(); i++)
    {
        for(int j = 0; j < img.size(); j++)
        {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Inplace rotate square matrix by 90 degree\n");
    vector<vector<int>> img = { { 1, 2, 3, 4},
                                { 5, 6, 7, 8},
                                { 9, 10, 11, 12},
                                {13, 14, 15, 16}};
    printImg(img);
    printf("\n");

    rotate(img);
    printImg(img);
    printf("\n");

    rotate_anti(img);
    printImg(img);

    return 0;
}