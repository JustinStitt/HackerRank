# link = https://www.hackerrank.com/contests/hack-the-interview-v/challenges/the-xor-problem

function maxXorValue(x, k)
    # XOR is one or the other but NOT both
    b = fill('0', length(x))
    for i in 1:length(x)
        if k <= 0 break end
        if(x[i] == '0')
            b[i] = '1'
            k -= 1
        end
    end
    return b |> String
end

t = parse(Int, readline()) # number of test cases
for _ in 1:t
    bitstring = readline()
    max_swaps = parse(Int, readline())
    maxXorValue(bitstring, max_swaps) |> println
end