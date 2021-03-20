# link = https://www.hackerrank.com/challenges/utopian-tree

function p(x)
    res = 1
    for i in 1:x
        res += (i & 1 == 0 ? 1 : res)
    end
    return res
end

t = parse(Int, readline()) # number of test cases
for _ in 1:t
    n = parse(Int, readline()) # number of growth cycles

    p(n) |> println    
end