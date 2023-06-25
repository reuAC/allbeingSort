function isSorted(array)
    for i = 2, #array do
        if array[i] < array[i - 1] then
            return false
        end
    end
    return true
end

function generatePermutations(array, level, results)
    if level == #array then
        table.insert(results, table.pack(table.unpack(array)))
        return
    end

    for i = level, #array do
        array[level], array[i] = array[i], array[level]
        generatePermutations(array, level + 1, results)
        array[level], array[i] = array[i], array[level]
    end
end

function allbeingSort(array)
    local permutations = {}
    generatePermutations(array, 1, permutations)

    for _, permutation in ipairs(permutations) do
        if isSorted(permutation) then
            io.write("Sorted array: ")
            for i = 1, #permutation do
                io.write(permutation[i] .. " ")
            end
            io.write("\n")
            return
        end
    end

    io.write("Array is not sortable.\n")
end

--print("示例用法")
local array = {3, 2, 1}
io.write("Original array: ")
for i = 1, #array do
    io.write(array[i] .. " ")
end
io.write("\n")

allbeingSort(array)
