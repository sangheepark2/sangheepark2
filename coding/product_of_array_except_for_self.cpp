/* Product of Array Except Self */
#include <stdio.h>
#include <vector>

using namespace std;

void productArray(vector<int> &arr)
{
    int len = arr.size();
    vector<int> left(len, 1);
    vector<int> right(len, 1);
    vector<int> ret(len, 1);

    //left, right init
    for(int i = 1; i < len; i++)
    {
        left[i] = left[i - 1] * arr[i - 1];
        right[len - 1 - i] = right[len - 1 - i + 1] * arr[len - 1 - i + 1];
    }

    for(int i = 0; i < len; i++)
    {
        ret[i] = left[i] * right[i];
    }

    for(auto i : ret)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    printf("Product of Array Except Self\n");
    vector<int> arr = {10, 3, 5, 6, 2};
    productArray(arr);
    return 0;
}