import java.util.ArrayList;
import java.util.List;

public class AllbeingSort {

    public static boolean isSorted(int[] array) {
        for (int i = 1; i < array.length; i++) {
            if (array[i] < array[i - 1]) {
                return false;
            }
        }
        return true;
    }

    public static void generatePermutations(int[] array, int level, List<int[]> results) {
        if (level == array.length) {
            results.add(array.clone());
            return;
        }

        for (int i = level; i < array.length; i++) {
            swap(array, level, i);
            generatePermutations(array, level + 1, results);
            swap(array, level, i);
        }
    }

    public static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void allbeingSort(int[] array) {
        List<int[]> permutations = new ArrayList<>();
        generatePermutations(array, 0, permutations);

        for (int[] permutation : permutations) {
            if (isSorted(permutation)) {
                System.out.print("Sorted array: ");
                for (int num : permutation) {
                    System.out.print(num + " ");
                }
                System.out.println();
                return;
            }
        }

        System.out.println("Array is not sortable.");
    }

    public static void main(String[] args) {
        // 示例用法
        int[] array = {3, 2, 1};

        System.out.print("Original array: ");
        for (int num : array) {
            System.out.print(num + " ");
        }
        System.out.println();

        allbeingSort(array);
    }
}
