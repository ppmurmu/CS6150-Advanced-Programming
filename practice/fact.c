#include <stdio.h>
int fact(int n)
{
    int fac;
    if (n > 1)
    {
        fac = n * fact(n - 1);
    }
}
int main()
{
    int t = fact(5);
    printf("%d", t);
    return 0;
}