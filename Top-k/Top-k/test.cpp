#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

// 向下调整算法（小堆）
void AdjustDown(int* arr, int size, int parent)
{
    int child = 2 * parent + 1;
    while (child < size)
    {
        // 找较小的孩子
        if (child + 1 < size && arr[child + 1] < arr[child])
        {
            child++;
        }
        if (arr[child] < arr[parent])
        {
            std::swap(arr[child], arr[parent]);
            parent = child;
            child = 2 * parent + 1;
        }
        else
        {
            return;
        }
    }
}

// 造数据
void CreateDate()
{
    int n = 100000;
    srand((unsigned int)time(0));
    const char* file = "data.txt";
    FILE* fin = fopen(file, "w");
    if (fin == NULL)
    {
        perror("fopen error");
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        int x = (rand() + i) % 1000000;
        fprintf(fin, "%d\n", x);
    }
    fclose(fin);
    printf("数据生成完成，共 %d 条\n", n);
}

// TopK 问题：求前K个最大的数
void TopK()
{
    printf("请输入k:>");
    int k = 0;
    scanf("%d", &k);
    if (k <= 0)
    {
        printf("k必须大于0\n");
        return;
    }

    const char* file = "data.txt";
    FILE* fout = fopen(file, "r");
    if (fout == NULL)
    {
        perror("fopen error");
        return;
    }

    // 1. 分配 k 个空间的小堆
    int* minheap = (int*)malloc(sizeof(int) * k);
    if (minheap == NULL)
    {
        perror("malloc error");
        fclose(fout);
        return;
    }

    // 2. 先把前 k 个数据读入堆中
    for (int i = 0; i < k; i++)
    {
        if (fscanf(fout, "%d", &minheap[i]) == EOF)
        {
            printf("文件数据不足 %d 个\n", k);
            free(minheap);
            fclose(fout);
            return;
        }
    }

    // 3. 建小堆（前 k 个数据建堆）
    for (int i = (k - 2) / 2; i >= 0; i--)
    {
        AdjustDown(minheap, k, i);
    }

    // 4. 遍历剩余数据，比堆顶大则入堆
    int val = 0;
    while (fscanf(fout, "%d", &val) != EOF)
    {
        if (val > minheap[0])  // 比堆顶大
        {
            minheap[0] = val;           // 替换堆顶
            AdjustDown(minheap, k, 0);  // 向下调整
        }
    }

    // 5. 输出结果（前 k 个最大的数，从小到大输出）
    printf("前 %d 个最大的数是：\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", minheap[i]);
    }
    printf("\n");

    // 6. 释放资源
    free(minheap);
    fclose(fout);
}

int main()
{
    // 1. 先造数据（如果已经有 data.txt 可以注释掉）
    CreateDate();

    // 2. 求 TopK
    TopK();

    return 0;
}