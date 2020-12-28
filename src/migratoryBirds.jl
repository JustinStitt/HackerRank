# link = https://www.hackerrank.com/challenges/migratory-birds

function migratoryBirds(arr)
     freq = Dict(k => count(e->e==k, arr) for k in arr)
     function fcomp(x, y, f) # ad-hoc
          f[x] == f[y] && return (x > y) ? false : true
          f[x] > f[y] && return true
          return false
     end
     sort!(arr, lt=(x,y)->fcomp(x,y,freq))
     return arr[1]
end

n = parse(Int, readline()) # number of birds sighted in arr
arr = readline() |> split |> x->parse.(Int, x)
migratoryBirds(arr) |> println