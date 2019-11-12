#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n, imax = 0, imin = 0, kol = 0;
    printf("Введите длинну массива\n");
    scanf("%d", &n);
    int a[n];
    printf("Введите n целых чисел\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
    {
        if(a[i] > a[imax])
            imax = i;
        if(a[i] < a[imin])
            imin = i;
    }
    int d;
    if(imax < imin) d = 1;
    else if(imax > imin) d = -1;
    else if(imax == imin) d = 0;
    for(int i = imax + d; i != imin; i += d)
    {
        if(a[i] > 0)
            kol++;
    }
    printf("Наименьшее значение массива: %d\n", a[imin]);
    printf("Наибольшее значение массива: %d\n", a[imax]);
    printf("Количество положительных чисел между наибольшим и наименьшим значением: %d\n", kol);
    return 0;
}
