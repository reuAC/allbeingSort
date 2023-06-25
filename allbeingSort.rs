fn is_sorted(array: &[i32]) -> bool {
    for i in 1..array.len() {
        if array[i] < array[i - 1] {
            return false;
        }
    }
    true
}

fn generate_permutations(array: &mut [i32], level: usize, results: &mut Vec<Vec<i32>>) {
    if level == array.len() {
        results.push(array.to_vec());
        return;
    }

    for i in level..array.len() {
        array.swap(level, i);
        generate_permutations(array, level + 1, results);
        array.swap(level, i);
    }
}

fn allbeing_sort(array: &mut [i32]) {
    let mut permutations = Vec::new();
    generate_permutations(array, 0, &mut permutations);

    for permutation in permutations {
        if is_sorted(&permutation) {
            println!("Sorted array: {:?}", permutation);
            return;
        }
    }

    println!("Array is not sortable.");
}

fn main() {
    // 示例用法
    let mut array = vec![3, 2, 1];

    println!("Original array: {:?}", array);
    allbeing_sort(&mut array);
}
