# link = https://www.hackerrank.com/challenges/30-binary-numbers

function maxiumumOnes(n)
    # first convert to bitvector
    bv = digits(n, base=2)
    max_consec_ones = 0
    consec_ones = 0
    for b in bv
        if b == 0
            max_consec_ones = max(max_consec_ones, consec_ones)
            consec_ones = 0
        else
            consec_ones += 1
        end
    end
    return max(max_consec_ones, consec_ones)
end

n = parse(Int, readline())
maxiumumOnes(n) |> println
