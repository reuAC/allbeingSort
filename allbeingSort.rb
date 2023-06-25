def sorted?(array)
    (1...array.length).each do |i|
      return false if array[i] < array[i - 1]
    end
    true
  end
  
  def generate_permutations(array, level, results)
    if level == array.length
      results << array.dup
      return
    end
  
    (level...array.length).each do |i|
      array[level], array[i] = array[i], array[level]
      generate_permutations(array, level + 1, results)
      array[level], array[i] = array[i], array[level]
    end
  end
  
  def allbeing_sort(array)
    permutations = []
    generate_permutations(array, 0, permutations)
  
    permutations.each do |permutation|
      if sorted?(permutation)
        puts "Sorted array: #{permutation}"
        return
      end
    end
  
    puts "Array is not sortable."
  end
  =begin
  //示例用法
  =end
  array = [3, 2, 1]
  puts "Original array: #{array}"
  allbeing_sort(array)
  