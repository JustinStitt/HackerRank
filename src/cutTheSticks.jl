# link = https://www.hackerrank.com/challenges/cut-the-sticks

function cutTheSticks(arr::Array{Int, 1})
    sort!(arr)
    count = Int[]
    while length(arr) > 0
        push!(count, length(arr))
        small = arr[1]
        arr = map(x->x-small, arr) # cut down all sticks by smallest stick
        filter!(x->x!=0, arr) # remove empty sticks (size 0)
    end
    for e in count
        println(e)
    end
end

n = parse(Int, readline()) # size of array
arr = readline() |> split |> x->parse.(Int, x)
cutTheSticks(arr)