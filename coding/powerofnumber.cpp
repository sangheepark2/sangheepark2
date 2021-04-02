/* Power of a Number */
#include <stdio.h>
#include <math.h>

double mypower(double x, int n)
{
    double ret = 0.0f;
    int ne = 1;
    if(n < 0)
    {
        n = -n;
        ne = -1;
    }

    if(n == 2)
        ret = x * x;
    else if(n == 1)
        ret = x;
    else if(n == 0)
        ret = 1.0f;
    else
    {
        if(n % 2 == 0)
            ret = mypower(x, n / 2) * mypower(x, n / 2);
        else
            ret = x * mypower(x, n / 2) * mypower(x, n / 2);
    }

    if(ne == -1)
        ret = 1/ret;
    return ret;
}

int main()
{
    printf("Power of a Number\n");
    for(int i = -5; i < 6; i++)
        printf("%.9f\n", mypower(0.753, i) - pow(0.753, i));

    return 0;
}