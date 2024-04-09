#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int i = 0;
    loop:
    if (i < n) {
        printf("%d", i++);
        goto loop;
    }

    return 0;
}