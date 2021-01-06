# link = https://www.hackerrank.com/challenges/find-digits

function findDigits(num::Int)::Int
    count = 0
    for digit in digits(num, base=10)
        digit == 0 && continue
        if num % digit == 0 count += 1 end
    end
    return count
end

function main()
    t = parse(Int, readline()) # number of test cases
    for _ in 1:t
        n = parse(Int, readline()) 
        findDigits(n) |> println
    end
end
main()

