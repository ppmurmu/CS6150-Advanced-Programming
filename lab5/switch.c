#include <stdio.h>

int main()
{
    int n = 0;
    printf("Enter a val");

    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("one");
        break;
    case 2 ... 10:
        printf("2 to 10");
        break;
    default:
        printf("defautlt");
        break;
    }
    return 0;
}