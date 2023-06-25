#include <iostream>
#include <vector>
#include <algorithm>

bool isSorted(const std::vector<int> &array)
{
    for (size_t i = 1; i < array.size(); i++)
    {
        if (array[i] < array[i - 1])
        {
            return false;
        }
    }
    return true;
}

void generatePermutations(std::vector<int> &array, size_t level, std::vector<std::vector<int>> &results)
{
    if (level == array.size())
    {
        results.push_back(array);
        return;
    }

    for (size_t i = level; i < array.size(); i++)
    {
        std::swap(array[level], array[i]);
        generatePermutations(array, level + 1, results);
        std::swap(array[level], array[i]);
    }
}

void allbeingSort(std::vector<int> &array)
{
    std::vector<std::vector<int>> permutations;
    generatePermutations(array, 0, permutations);

    for (const auto &permutation : permutations)
    {
        if (isSorted(permutation))
        {
            std::cout << "Sorted array: ";
            for (const auto &num : permutation)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
            return;
        }
    }

    std::cout << "Array is not sortable." << std::endl;
}

int main()
{
    // 示例用法
    std::vector<int> array = {6, 2, 3};
    std::cout << "Original array: ";
    for (const auto &num : array)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    allbeingSort(array);

    return 0;
}
