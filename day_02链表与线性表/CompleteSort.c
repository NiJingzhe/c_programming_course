#include "compile_control.h"
#ifdef CMLP_SORT

#include<stdio.h>


int ans[400000];
int counter;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void perm(int num, int n, int a[]) {
    if (num == n) {
        int i;
        int sum = 0;
        for (i = 1; i <= n; ++i) {
            sum = sum * 10 + a[i];
        }
        ans[counter] = sum;
        counter++;
        sum = 0;
        return;
    }

    int j;
    for (j = num; j <= n; ++j) {
        swap(&a[j], &a[num]);
        perm(num + 1, n, a);
        swap(&a[j], &a[num]);
    }
}


void swap_lh(int a[], int low, int high) //交换两个数的值
{
    int t = a[low];
    a[low] = a[high];
    a[high] = t;
}


int partition(int a[], int low, int high)  //计算基准点，分割为左右两个数组
{
    int point = a[low];//基准点等于第一个元素

    while (low < high)
    {
        while (low < high && a[high] >= point)//控制high指针比较并左移
        {
            high--;
        }
        swap_lh(a, low, high);
        while (low < high && a[low] <= point)//控制low指针比较并右移
        {
            low++;
        }
        swap_lh(a, low, high);
    }
    return low;//返回基准点位置
}

void quicksort(int a[], int low, int high)  //low:起始位置 high:末尾位置
{
    if (low < high) {
        int point = partition(a, low, high);//计算基准点
        quicksort(a, low, point - 1);  //对基准点的左边进行排序
        quicksort(a, point + 1, high);//对基准点的右边进行排序
    }
}


int fact(int n) {

    if (n == 0 || n == 1)
        return 1;

    int i;
    int prod = 1;
    for (i = 1; i <= n; i++)
        prod *= i;

    return prod;
}

int main() {
    int n;
    int a[11];
    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; i++) {
        a[i] = i;
    }
    perm(1, n, a);
    quicksort(ans, 0, fact(n) - 1);

    for (i = 0; i < fact(n); i++)
        printf("%d\n", ans[i]);

    return 0;
}



#endif