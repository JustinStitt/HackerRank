# link = https://www.hackerrank.com/challenges/strange-advertising

function viralAdvertising(n)
    csum = 0
    f(x) = begin
        x == 1 && (csum += 2; return 6)
        l = div(f(x - 1), 2)
        csum  += l
        l * 3
    end 
    f(n)
    return csum
end

n = parse(Int, readline()) # the day number
viralAdvertising(n) |> println