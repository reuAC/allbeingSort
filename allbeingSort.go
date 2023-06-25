package main

import (
	"fmt"
)

func isSorted(array []int) bool {
	for i := 1; i < len(array); i++ {
		if array[i] < array[i-1] {
			return false
		}
	}
	return true
}

func generatePermutations(array []int, level int, results *[][]int) {
	if level == len(array) {
		temp := make([]int, len(array))
		copy(temp, array)
		*results = append(*results, temp)
		return
	}

	for i := level; i < len(array); i++ {
		array[level], array[i] = array[i], array[level]
		generatePermutations(array, level+1, results)
		array[level], array[i] = array[i], array[level]
	}
}

func allbeingSort(array []int) {
	permutations := [][]int{}
	generatePermutations(array, 0, &permutations)

	for _, permutation := range permutations {
		if isSorted(permutation) {
			fmt.Print("Sorted array: ")
			for _, num := range permutation {
				fmt.Printf("%d ", num)
			}
			fmt.Println()
			return
		}
	}

	fmt.Println("Array is not sortable.")
}

func main() {
	array := []int{3, 2, 1}

	fmt.Print("Original array: ")
	for _, num := range array {
		fmt.Printf("%d ", num)
	}
	fmt.Println()

	allbeingSort(array)
}
