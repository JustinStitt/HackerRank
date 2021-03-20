# link = https://www.hackerrank.com/challenges/fair-rations/

function fairRations(arr)
    no = "NO"
    n = length(arr)
    bread = 0    
    # simplify data
    arr = [x%2 for x in arr]
    
    n == 1 && return arr[1]
    
    for i in 1:n-1 # linear pass O(N)
        if arr[i] == 1 # odd
            arr[i] = 0
            arr[i+1] = (arr[i+1] == 0 ? 1 : 0)
            bread += 2
        end
    end
    if count(==(0), arr) != n return no end # linear pass O(N)
    return bread
end

# e e e

function main()
    n = parse(Int, readline()) # number of subjects in line
    arr = readline() |> split |> x->parse.(Int, x) # arr of subjects
    fairRations(arr) |> println
end

main()
