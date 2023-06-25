#include <stdio.h>
#include <stdbool.h>

bool isSorted(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (array[i] < array[i - 1])
        {
            return false;
        }
    }
    return true;
}

void generatePermutations(int array[], int size, int level, int results[][size], int *count)
{
    if (level == size)
    {
        for (int i = 0; i < size; i++)
        {
            results[*count][i] = array[i];
        }
        (*count)++;
        return;
    }

    for (int i = level; i < size; i++)
    {
        int temp = array[level];
        array[level] = array[i];
        array[i] = temp;

        generatePermutations(array, size, level + 1, results, count);

        temp = array[level];
        array[level] = array[i];
        array[i] = temp;
    }
}

void allbeingSort(int array[], int size)
{
    int permutations = 1;
    for (int i = 2; i <= size; i++)
    {
        permutations *= i;
    }

    int results[permutations][size];
    int count = 0;

    generatePermutations(array, size, 0, results, &count);

    for (int i = 0; i < count; i++)
    {
        if (isSorted(results[i], size))
        {
            printf("Sorted array: ");
            for (int j = 0; j < size; j++)
            {
                printf("%d ", results[i][j]);
            }
            printf("\n");
            return;
        }
    }

    printf("Array is not sortable.\n");
}

int main()
{
    // 示例用法
    int array[] = {3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);
    printf("Original array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    allbeingSort(array, size);
    return 0;
}
