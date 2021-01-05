# link = https://www.hackerrank.com/challenges/30-sorting

function bubblesort!(arr)
    n = length(arr)
    totalswaps = 0
    for i in 1:n
        numswaps = 0
        for j in 1:(n-1)
            if arr[j] > arr[j + 1]
                arr[j], arr[j+1] = arr[j+1], arr[j]
                numswaps += 1
            end
        end
        totalswaps += numswaps
        if numswaps == 0
            break # array is sorted
        end
    end
    println("Array is sorted in $totalswaps swaps.")
    println("First Element: ", arr[1])
    println("Last Element: ", arr[n]) 
end

n = parse(Int, readline() ) # the number of elements in array 'a'
arr = readline() |> split |> x->parse.(Int, x)
bubblesort!(arr)