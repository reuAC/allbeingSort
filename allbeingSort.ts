function isSorted(array: number[]): boolean {
    for (let i = 1; i < array.length; i++) {
      if (array[i] < array[i - 1]) {
        return false;
      }
    }
    return true;
  }
  
  function generatePermutations(array: number[], level: number, results: number[][]): void {
    if (level === array.length) {
      results.push([...array]);
      return;
    }
  
    for (let i = level; i < array.length; i++) {
      [array[level], array[i]] = [array[i], array[level]];
      generatePermutations(array, level + 1, results);
      [array[level], array[i]] = [array[i], array[level]];
    }
  }
  
  function allbeingSort(array: number[]): void {
    const permutations: number[][] = [];
    generatePermutations(array, 0, permutations);
  
    for (const permutation of permutations) {
      if (isSorted(permutation)) {
        console.log('Sorted array:', permutation);
        return;
      }
    }
  
    console.log('Array is not sortable.');
  }
  
  //示例用法
  const array: number[] = [3, 2, 1];
  
  console.log('Original array:', array);
  allbeingSort(array);
  