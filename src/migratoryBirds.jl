# link = https://www.hackerrank.com/challenges/migratory-birds

function migratoryBirds(arr)
     return sort(arr, lt=
            (x,y)->(count(e->e==x,arr) > count(e->e==y, arr)))[1]
end

n = parse(Int, readline()) # number of birds sighted in arr
arr = readline() |> split |> x->parse.(Int, x)
migratoryBirds(arr) |> println