#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n, kol = 0, sum = 0;
    float c, max;
    printf("Введите размер массива\n");
    scanf("%d", &n);
    float arr[n];
    printf("Введите элементы массива\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }                               //0.19   -62.04   -67.91   77.59   -80.34   67.02   57.19   -60.45   27.41   68.65
    printf("Элементы массива равны:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%7.2f ", arr[i]);
    }
    printf("\n");
    printf("Введите число C\n");
    scanf("%f", &c);
    for(int i = 0; i < n; i++)
        if(arr[i] < c)
            kol++;
    printf("Количество элементов массива, меньших C - %d\n", kol);
    for(int i = n - 1; i >= 0; i--)
    {
        if(arr[i] < 0)
            break;
        sum += arr[i];
    }
    printf("Сумма целых частей элементов массива, расположенных после последнего отрицательного элемента - %d\n", sum);
    for(int i = 0; i < n; i++)
        if(arr[i] > max || i == 0)
            max = arr[i];
    printf("Максимальный элемент массива равен %.2f\n", max);
    float lBoard = max - max*0.2;
    float rBoard = max + max*0.2;
    printf("Левая граница - %.2f", lBoard);
    printf("\nПравая граница - %.2f\n", rBoard);
    float *stack = (float *)malloc(n * sizeof(float));
    int iStack = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= lBoard && arr[i] <= rBoard)
        {
            stack[iStack] = arr[i];
            iStack++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(!(arr[i] >= lBoard && arr[i] <= rBoard))
        {
            stack[iStack] = arr[i];
            iStack++;
        }
    }
    for(int i = 0; i < n; i++)
        arr[i] = stack[i];
    printf("Массив после преобразования:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%7.2f ", arr[i]);
    }
    printf("\n");
    return 0;
}
