#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int key;
    for( ; ; ){
        int n, f1 = 1, f2 = 1, f3 = 2, sum = 0;
        printf("¬ведите n, n > 10\n");
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            sum += f1;
            f1 = f2;
            f2 = f3;
            f3 = f1 + f2;
        }
        printf("—умма первых %d чисел ‘ибоначчи равна %d\n", n, sum);
        key = getch();
        if (key == 113)
            break;
        printf("\n");
    }
    return 0;
}
