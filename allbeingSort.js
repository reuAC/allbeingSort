function isSorted(array) {
  for (var i = 1; i < array.length; i++) {
    if (array[i] < array[i - 1]) {
      return false;
    }
  }
  return true;
}

function allbeingSort(array, level) {
  if (level === 0) {
    return array;
  }

  var permutations = allbeingPermutation(array);
  for (var i = 0; i < permutations.length; i++) {
    if (isSorted(permutations[i])) {
      return permutations[i];
    }
  }

  return array;
}

function allbeingPermutation(array) {
  var results = [];

  function generatePermutations(currentPerm, remainingArray, level) {
    if (level === array.length) {
      results.push(currentPerm);
      return;
    }

    for (var i = 0; i < remainingArray.length; i++) {
      var newArray = remainingArray.slice();
      var nextElement = newArray.splice(i, 1);
      generatePermutations(currentPerm.concat(nextElement), newArray, level + 1);
    }
  }

  generatePermutations([], array, 0);
  return results;
}

// 示例用法
var array = [3, 2, 1];
var sortedArray = allbeingSort(array, array.length);
console.log(sortedArray);
