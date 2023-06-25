def is_sorted(array):
    for i in range(1, len(array)):
        if array[i] < array[i - 1]:
            return False
    return True

def generate_permutations(array, level, results):
    if level == len(array):
        results.append(array.copy())
        return

    for i in range(level, len(array)):
        array[level], array[i] = array[i], array[level]
        generate_permutations(array, level + 1, results)
        array[level], array[i] = array[i], array[level]

def allbeing_sort(array):
    permutations = []
    generate_permutations(array, 0, permutations)

    for permutation in permutations:
        if is_sorted(permutation):
            print("Sorted array:", permutation)
            return

    print("Array is not sortable.")

# 示例用法
array = [3, 2, 1]

print("Original array:", array)
allbeing_sort(array)
