using System;
using System.Collections.Generic;

class AllbeingSorter
{
    static bool IsSorted(int[] array)
    {
        for (int i = 1; i < array.Length; i++)
        {
            if (array[i] < array[i - 1])
            {
                return false;
            }
        }
        return true;
    }

    static void GeneratePermutations(int[] array, int level, List<int[]> results)
    {
        if (level == array.Length)
        {
            results.Add((int[])array.Clone());
            return;
        }

        for (int i = level; i < array.Length; i++)
        {
            Swap(ref array[level], ref array[i]);
            GeneratePermutations(array, level + 1, results);
            Swap(ref array[level], ref array[i]);
        }
    }

    static void Swap(ref int a, ref int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    static void AllbeingSort(int[] array)
    {
        List<int[]> permutations = new List<int[]>();
        GeneratePermutations(array, 0, permutations);

        foreach (int[] permutation in permutations)
        {
            if (IsSorted(permutation))
            {
                Console.Write("Sorted array: ");
                Console.WriteLine(string.Join(" ", permutation));
                return;
            }
        }

        Console.WriteLine("Array is not sortable.");
    }

    static void Main()
    {
        // 示例用法
        int[] array = { 3, 2, 1 };

        Console.Write("Original array: ");
        Console.WriteLine(string.Join(" ", array));

        AllbeingSort(array);
    }
}
