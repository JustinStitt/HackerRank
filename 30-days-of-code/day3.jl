# 30-days-of-code: Day #3 - Conditional Statements
# link = https://www.hackerrank.com/challenges/30-conditional-statements/problem?h_r=profile
function main()
    n = parse(Int, readline())
    isweird(n)
end

function isweird(n::Int)
    if n & 1 > 0
        println("Weird")
        return
    end
    if 2 <= n <= 5
        println("Not Weird")
    elseif 6 <= n <= 20
        println("Weird")
    else
        println("Not Weird")
    end
    nothing
end

main()
